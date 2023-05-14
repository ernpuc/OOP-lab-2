#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <tuple>

using std::string;
using std::vector;
using std::accumulate;
using std::tie;

class zmogus {
protected:
	string vardas_;
	string pavarde_;
public:
	zmogus(string vardas = "", string pavarde = "") : vardas_(vardas), pavarde_(pavarde) {};
	virtual string vardas() const  = 0;
	virtual string pavarde() const = 0;
	virtual void setVardas(string vardas) = 0;
	virtual void setPavarde(string pavarde) = 0;
	virtual ~zmogus() { vardas_.clear(), pavarde_.clear(); }
};

class studentas: public zmogus {
private:
	vector<int> paz_;
	int egz_;
	double galPaz_;
public:
	studentas() : zmogus("", ""), egz_(0), galPaz_(0) {};
	studentas(std::istream& is);
	studentas(string vardas, string pavarde, vector<int>paz, int egz) : zmogus(vardas, pavarde), paz_(paz), egz_(egz), galPaz_(0) {};
	studentas(const studentas& stud);
	studentas& operator=(const studentas& stud);
	studentas(studentas&& stud);
	studentas& operator=(studentas&& stud);
	string vardas() const { return vardas_; }
	string pavarde() const { return pavarde_; }
	void setVardas(string vardas) { vardas_ = vardas; }
	void setPavarde(string pavarde) { pavarde_ = pavarde; }
	void setPaz(vector<int> paz) { paz_ = paz; }
	void setEgz(int egz) { egz_ = egz; }
	void setGalPaz(double galPaz) { galPaz_ = galPaz; }
	double galPaz();
	friend std::ostream& operator<< (std::ostream& out, studentas& a);
	~studentas() { paz_.clear(); }
};

bool palygVard(studentas& t1, studentas& t2);
bool palygPaz(studentas& t1, studentas& t2);
bool galDaugiau5(studentas stud);
double pazym(int egz, double x);
double med(vector<int> paz);
//std::ostream& operator<< (std::ostream& out, studentas& a);
