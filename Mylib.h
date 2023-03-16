#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <random>
#include <vector>

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
using std::vector;
using std::sort;
using std::ifstream;
using std::ofstream;
using std::getline;

struct studentas {
	string vardas = "", pavarde = "";
	vector<int> paz;
	int egz = 0;
	double med;
	double vid;
};



void pild(studentas& temp);
void pildFailas(vector<studentas>& grupe);
void pildRandom(vector<studentas>& grupe);
void spausd(vector<studentas>& temp, int uzkl);
void spausdFailas(vector<studentas>& temp, int uzkl);
double pazym(studentas temp, double x);
double vid(studentas temp);
double med(studentas temp);
bool palyg(studentas& t1, studentas& t2);