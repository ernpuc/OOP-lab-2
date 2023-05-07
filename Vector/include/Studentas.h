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

class studentas {
private:
	string vardas_;
	string pavarde_;
	vector<int> paz_;
	int egz_;
	double galPaz_;
public:
	studentas() : vardas_(""), pavarde_(""), egz_(0), galPaz_(0) {};
	studentas(std::istream& is);
	studentas(string vardas, string pavarde, vector<int>paz, int egz) : vardas_(vardas), pavarde_(pavarde), paz_(paz), egz_(egz), galPaz_(0) {};
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
	~studentas() { paz_.clear(); vardas_.clear(); pavarde_.clear(); }
};

bool palygVard(studentas& t1, studentas& t2);
bool palygPaz(studentas& t1, studentas& t2);
bool galDaugiau5(studentas stud);
double pazym(int egz, double x);
double med(vector<int> paz);
//std::ostream& operator<< (std::ostream& out, studentas& a);
