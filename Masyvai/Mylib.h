#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <random>

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

struct studentas {
	string vardas = "", pavarde = "";
	int* paz = nullptr;
	int paz_sk = 0;
	int egz = 0;
};

void pild(studentas& temp);
void pildRandom(studentas& temp, int m);
void spausd(studentas* temp, string uzkl, int n);
double pazym(studentas temp, double x);
double vid(studentas temp);
double med(studentas temp);
void rikiuoja(studentas& temp);