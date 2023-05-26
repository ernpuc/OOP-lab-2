#pragma once
#include <memory>
#include <algorithm>
#include <string>

template <class T> 
class myVector {
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef std::reverse_iterator<T*> reverse_iterator;
	typedef std::reverse_iterator<const T*> const_reverse_iterator;

	myVector() { create(); }
	explicit myVector(size_type n, const T& val = T{}) { create(n, val); }
	myVector(std::initializer_list<T> init_list) : data{ alloc.allocate(init_list.size()) }, avail{ data + init_list.size() }, limit{ data + init_list.size() } {
		std::uninitialized_copy(init_list.begin(), init_list.end(), data);
	}
	myVector(const myVector& v) { create(v.begin(), v.end()); }
	myVector(const_iterator i, const_iterator j) { create(i, j); }
	myVector& operator=(const myVector&);

	bool empty() const { return size() == 0; }
	size_type size() const { return avail - data; }
	size_type max_size() const { return alloc.max_size(); }
	void reserve(size_type n);
	size_type capacity() const { return limit - data; }
	void shrink_to_fit();

	const T& operator[](size_type i) const { return data[i]; }
	const T& at(size_type i) const;
	const T& back() const { return *(avail - 1); }
	const T& front() const { return *data; }	

	iterator begin() { return data; }
	const_iterator begin() const { return data; }
	iterator end() { return avail; }
	const_iterator end() const { return avail; }
	reverse_iterator reverse_begin() { return reverse_iterator(avail); }
	const_reverse_iterator reverse_begin() const { return const_reverse_iterator(avail); }
	reverse_iterator reverse_end() { return reverse_iterator(data);	}
	const_reverse_iterator reverse_end() const { return const_reverse_iterator(data); }
	
	void push_back(const T& val);
	void pop_back();
	void resize(size_type n);
	void clear() { uncreate(); }

	~myVector() { uncreate(); }
private:
	iterator data;
	iterator avail;
	iterator limit;

	std::allocator<T> alloc;
	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);

	void uncreate();

	void grow();
	void unchecked_append(const T&);
};



template <class T>
myVector<T>& myVector<T>::operator=(const myVector& rhs) {
	if (&rhs != this) {
		uncreate();
		create(rhs.begin(), rhs.end());
	}
	return *this;
}

template <class T>
void myVector<T>::create() {
	data = avail = limit = nullptr;
}

template <class T>
void myVector<T>::create(size_type n, const T& val) {
	data = alloc.allocate(n);
	limit = avail = data + n;
	std::uninitialized_fill(data, limit, val);
}

template <class T>
void myVector<T>::create(const_iterator i, const_iterator j) {
	data = alloc.allocate(j - i);
	avail = limit = std::uninitialized_copy(i, j, data);
}

template <class T>
void myVector<T>::uncreate() {
	if (data) {
		iterator it = avail;
		while (it != data)
			alloc.destroy(--it);
		
		alloc.deallocate(data, limit - data);
	}
	data = limit = avail = nullptr;
}

template <class T>
void myVector<T>::grow() {
	size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));

	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = std::uninitialized_copy(data, avail, new_data);

	uncreate();

	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

template <class T>
void myVector<T>::unchecked_append(const T& val) {
	alloc.construct(avail++, val);
}

template <class T>
const T& myVector<T>::at(size_type i) const {
	if (i >= size()) {
		throw std::out_of_range("myVector::out_of_range");
	}
	return data[i];
}

template <class T>
void myVector<T>::reserve(size_type new_size) {
	if (new_size < capacity()) return;

	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = std::uninitialized_copy(data, avail, new_data);

	uncreate();

	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

template<class T>
void myVector<T>::shrink_to_fit(){
	if (size() < capacity()) {
		limit = avail;
	}
}

template <class T>
void myVector<T>::resize(size_type new_size) {
	if (new_size < size()) {
		for (size_type i = new_size; i < size(); i++) {
			alloc.destroy(data + i);
		}
	}
	else if (new_size > capacity()) {
		reserve(new_size);
	}
	for (size_type i = size(); i < new_size; i++) {
		alloc.construct(data + i);
	}
	avail = data + new_size;
}

template<class T>
void myVector<T>::push_back(const T& val) {
	if (avail == limit)
		grow();
	unchecked_append(val);
}

template <class T>
void myVector<T>::pop_back() {
	if (size() != 0) {
		alloc.destroy(avail - 1);
		avail--;
	}
}