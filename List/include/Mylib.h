#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <random>
#include <list>
#include <vector>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;
using std::left;
using std::right;
using std::setw;
using std::fixed;
using std::setprecision;
using std::string;
using std::copy;
using std::swap;
using std::list;
using std::vector;
using std::sort;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::to_string;
using std::lower_bound;
using std::find_if;
using std::copy_if;
using std::remove_copy_if;
using std::remove_if;
using std::partition;

struct studentas {
	string vardas = "", pavarde = "";
	list<int> paz;
	int egz = 0;
	double galPaz = 0;
};

class Timer {
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
	Timer() : start{ std::chrono::high_resolution_clock::now() } {}
	void reset() {
		start = std::chrono::high_resolution_clock::now();
	}
	double elapsed() const {
		return std::chrono::duration<double>
			(std::chrono::high_resolution_clock::now() - start).count();
	}
};

extern int uzkl_iv;
extern int uzkl_skirst;
extern int uzkl_paz;
extern int uzkl_spausd;
extern int uzkl_vykd;

void menu(list<string> tekstas, int& uzkl);
void intUzklausa(string kint_pavad, int& n);
void spausdinti(list<studentas>& grupe, vector<double>& test_laikai);
void spausdConsole(list<studentas>& temp, int uzkl);
void spausdFailas(list<studentas> grupe1, list<studentas> grupe2, int uzkl, vector<double>& test_laikai);
void skirst(list<studentas>& temp, int uzkl, vector<double>& test_laikai);
void skirstyti1(list<studentas> grupe, list<studentas>& grupe1, list<studentas>& grupe2);
list<studentas> skirstyti2(list<studentas>& grupe);
list<studentas> skirstyti3(list<studentas>& grupe);
void failas(list<studentas>& grupe, string pavad, string uzkl_paz, vector<double>& test_laikai);
void spausdLentele(vector<double> laikai);
void spausdLentele(vector <vector< double >> laikai);
void pildConsole(studentas& temp);
void pildFailas(list<studentas>& grupe, string pavad, vector<double>& test_laikai);
void pildRandom(list<studentas>& grupe);
void generuoti();
void testuoti(vector<double>& test_laikai);
double pazym(studentas temp, double x);
double med(studentas temp);
bool gerasPavad(string x, vector<string> pavad);
bool palygVard(studentas& t1, studentas& t2);
bool palygPaz(studentas& t1, studentas& t2);
bool palygGal(const studentas& stud, const double& x);
bool galDaugiau5(studentas stud);

std::ostream& operator<< (std::ostream& out, studentas& a);
