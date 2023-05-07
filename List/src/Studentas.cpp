#include "Studentas.h"
#include <Mylib.h>

studentas::studentas(std::istream& is) {
	int x;
	is >> vardas_ >> pavarde_;
	while (is >> x) paz_.push_back(x);
	egz_ = paz_.back();
	paz_.pop_back();
	galutinis();
}

void studentas::galutinis() {
	double vid = 0;
	switch (uzkl_paz) {
	case 1:
		vid = accumulate(paz_.begin(), paz_.end(), 0) / paz_.size();
		galPaz_ = pazym(egz_, vid);
		break;
	case 2:
		galPaz_ = pazym(egz_, med(paz_));
		break;
	}
}

bool palygVard(studentas& t1, studentas& t2) {
	return tie(t1.vardas(), t1.pavarde()) < tie(t2.vardas(), t2.pavarde());
}

bool palygPaz(studentas& t1, studentas& t2) {
	return t1.galPaz() < t2.galPaz();
}

bool galDaugiau5(studentas stud) {
	return stud.galPaz() >= 5.0;
}

//Galutinio pazymio skaiciavimas
double pazym(int egz, double x) {
	return 0.4 * x + 0.6 * egz;
}

//Pazymiu medianos skaiciavimas
double med(list<int> paz) {
	paz.sort();
	//sort(temp.paz.begin(), temp.paz.end());
	int n = paz.size();
	auto ptr = paz.begin();
	if (n & 1) {
		advance(ptr, n / 2);
		return *ptr;
	}
	else {
		advance(ptr, (n - 1) / 2);
		return (*ptr + *(++ptr)) / 2;
	}
}

std::ostream& operator<< (std::ostream& out, studentas& a) {
	out << left << setw(15) << a.vardas() << setw(15) << a.pavarde() << fixed << setprecision(2) << a.galPaz();
	return out;
}