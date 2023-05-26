/*! \file pildFunkcijos.cpp */
#include "Mylib.h"

//Duomenu ivedimas ranka
void pildConsole(studentas& temp) {
	string vardas, pavarde;
	vector<int> paz;
	int egz;
	cout << "Iveskite varda ir pavarde: ";
	cin >> vardas >> pavarde;
	int x = 0;
	do {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Iveskite pazymius. Noredami baigti iveskite -1. " << endl;
		while (true) {
			try {
				cin >> x;
				if (x == -1) break;
				if (!cin || x < 0 || x > 10) {
					throw std::runtime_error("Ivesti galima tik sveikus skaicius nuo 0 iki 10. \n");
				}

				else {
					paz.push_back(x);
				}
			}
			catch (std::runtime_error& e) {
				paz.clear();
				cout << e.what();
				break;
			}
		}
	} while (paz.size() == 0);			//ciklas kartojamas tuo atveju, jeigu buvo bloga ivestis

	while (true) {
		try {
			cout << "Iveskite egzamino paz. ";
			if (!(cin >> egz) || egz < 0 || egz > 10) {
				throw std::runtime_error("Egzamino paz. turi buti skaicius nuo 0 iki 10. ");
			}
			else break;
		}
		catch (std::runtime_error& e) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << e.what();
		}
	}
	studentas tmp(vardas, pavarde, paz, egz);
	temp = tmp;
	cin.ignore(10000, '\n');
}

//Duomenu pildymas is failo
void pildFailas(vector<studentas>& grupe, string pavad, vector<double>& test_laikai) {
	string eil;
	string elem;
	std::stringstream df_buffer;
	ifstream df;
	df.open(pavad);
	if (!df) {
		throw std::runtime_error("Toks failas neegzistuoja. Bandykite ivesti is naujo: ");
	}
	cout << "Failas skaitomas..." << endl;
	Timer t;
	df_buffer << df.rdbuf();
	df.close();

	if (!df_buffer.eof()) getline(df_buffer, eil);		//praleidziama pirma eilute

	while (df_buffer) {
		if (df_buffer.eof()) break;
		getline(df_buffer, eil);
		if (eil.empty()) break;
		std::stringstream eilut(eil);
		studentas tmp(eilut);
		grupe.push_back(tmp);
	}
	test_laikai.push_back(grupe.size());
	test_laikai.push_back(t.elapsed());
}

//Atsitiktiniu duomenu generavimas
void pildRandom(vector<studentas>& grupe) {
	string vardas_, pavarde_;
	vector<int> paz;
	int egz; 
	int n;
	int m;
	intUzklausa("studentu skaicius", n);
	intUzklausa("pazymiu kiekis", m);

	Timer t;
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, 10);


	vector<string> vardas{ "Lukas", "Matas", "Adomas", "Nojus", "Kajus", "Motiejus", "Markas", "Benas", "Herkus", "Jonas", "Dominykas" };
	vector<string> pavarde{ "Kazlauskas", "Petrauskas", "Jankauskas", "Butkus", "Paulauskas", "Vasiliauskas", "Baranauskas", "Urbonas", "Navickas", "Ramanauskas", "Savickas" };

	for (int i = 0; i < n; i++) {
		paz.reserve(m);
		vardas_ = vardas.at(dist(mt));
		pavarde_ = pavarde.at(dist(mt));
		for (int i = 0; i < m; i++) {
			paz.push_back(dist(mt));
		}
		egz = dist(mt);
		studentas temp(vardas_, pavarde_, paz, egz);
		grupe.push_back(temp);
		paz.clear();
	}
}