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
	void galutinis();
public:
	studentas() : vardas_(""), pavarde_(""), egz_(0), galPaz_(0) {};
	studentas(std::istream& is);
	studentas(string vardas, string pavarde, vector<int>paz, int egz) : vardas_(vardas), pavarde_(pavarde), paz_(paz), egz_(egz) { galutinis(); };
	string vardas() const { return vardas_; }
	string pavarde() const { return pavarde_; }
	double galPaz() const { return galPaz_; }
	~studentas() { paz_.clear(); vardas_.clear(); pavarde_.clear(); }
};

bool palygVard(studentas& t1, studentas& t2);
bool palygPaz(studentas& t1, studentas& t2);
bool galDaugiau5(studentas stud);
double pazym(int egz, double x);
double med(vector<int> paz);
std::ostream& operator<< (std::ostream& out, studentas& a);
