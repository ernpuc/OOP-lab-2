#include "Mylib.h"

void pildyti(vector<studentas>& grupe) {
	grupe.clear();
	studentas temp;
	int uzkl;
	menu("1 - ivesti duomenis patiems\n2 - ivesti duomenis is failo\n3 - generuoti duomenis atsitiktinai \n", uzkl, 3);
	switch (uzkl) {
	case 1:		//Ranka daromas studentu duomenu ivedimas
		do {
			pildConsole(temp);
			grupe.push_back(temp);
			menu("1 - ivesti dar vieno studento duomenis \n2 - baigti ivedima \n", uzkl, 2);
		} while (uzkl != 2);
		break;
	case 2:		//Duomenu ivedimas is failo
		pildFailas(grupe);
		break;
	case 3:		//Atsitiktinai daromas studentu duomenu ivedimas
		pildRandom(grupe);
		break;
	default:
		break;
	}
}

//Duomenu ivedimas ranka
void pildConsole(studentas& temp) {
	cout << "Iveskite varda ir pavarde: ";
	cin >> temp.vardas >> temp.pavarde;
	temp.paz.clear();
	int tmp = 0;
	double sum = 0;
	do {
		sum = 0;
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Iveskite pazymius. Noredami baigti iveskite -1. " << endl;
		while (true) {
			try {
				cin >> tmp;
				if (tmp == -1) break;
				if (!cin || tmp < 0 || tmp > 10) {
					throw std::runtime_error("Ivesti galima tik sveikus skaicius nuo 0 iki 10. \n");
				}

				else {
					temp.paz.push_back(tmp);
					sum += tmp;
				}
			}
			catch (std::runtime_error& e) {
				temp.paz.clear();
				cout << e.what();
				break;
			}
		}
	} while (temp.paz.size() == 0);			//ciklas kartojamas tuo atveju, jeigu buvo bloga ivestis

	temp.med = med(temp);
	temp.vid = sum / temp.paz.size();

	while (true) {
		try {
			cout << "Iveskite egzamino paz. ";
			cin >> tmp;
			if (!cin || tmp < 0 || tmp > 10) {
				throw std::runtime_error("Egzamino paz. turi buti skaicius nuo 0 iki 10. ");
			}
			else {
				temp.egz = tmp;
				break;
			}
		}
		catch (std::runtime_error& e) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << e.what();
		}
	}
	cin.ignore(10000, '\n');
}

//Duomenu pildymas is failo
void pildFailas(vector<studentas>& grupe) {
	studentas temp;
	string eil;
	string elem;
	std::stringstream df_buffer;
	string pavad;
	ifstream df;
	int nd_sk = -3;		//vardas, pavarde ir egzaminas nera iskaiciuojami
	double sum = 0;
	int paz;
	cout << endl;
	system("dir *.txt");
	cout << endl;
	cout << "Iveskite failo pavadinima: ";
	do {
		try {
			cin >> pavad;
			df.open(pavad);
			if (!df) {
				throw std::runtime_error("Toks failas neegzistuoja. Bandykite ivesti is naujo: ");
			}
			else break;
		}
		catch (std::runtime_error& e) {
			cout << e.what();
		}
	} while (true);

	cout << "Failas skaitomas..." << endl;
	Timer t;
	df_buffer << df.rdbuf();
	df.close();

	if (!df_buffer.eof()) getline(df_buffer, eil);		//praleidziama pirma eilute
	std::stringstream eilute(eil);
	while (eilute >> elem) {
		if (eilute.eof()) break;
		nd_sk++;
	}

	while (df_buffer) {
		sum = 0;
		temp.paz.clear();
		if (df_buffer.eof()) break;
		getline(df_buffer, eil);
		if (eil.empty()) break;
		std::stringstream eilut(eil);
		eilut >> temp.vardas >> temp.pavarde;
		for (int i = 0; i < nd_sk; i++) {
			eilut >> elem;
			paz = stoi(elem);
			temp.paz.push_back(paz);
			sum += paz;
		}
		eilut >> temp.egz;
		temp.med = med(temp);
		temp.vid = double(sum) / nd_sk;
		grupe.push_back(temp);
	}
	cout << "Failo nuskaitymas uztruko " << t.elapsed() << "s" << endl;
	visas_laikas += t.elapsed();
}

//Atsitiktiniu duomenu generavimas
void pildRandom(vector<studentas>& grupe) {
	studentas temp;
	int n;
	int m;
	double sum = 0;
	intUzklausa("studentu skaicius", n);
	intUzklausa("pazymiu kiekis", m);

	Timer t;
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, 10);


	vector<string> vardas{ "Lukas", "Matas", "Adomas", "Nojus", "Kajus", "Motiejus", "Markas", "Benas", "Herkus", "Jonas", "Dominykas" };
	vector<string> pavarde{ "Kazlauskas", "Petrauskas", "Jankauskas", "Butkus", "Paulauskas", "Vasiliauskas", "Baranauskas", "Urbonas", "Navickas", "Ramanauskas", "Savickas" };

	for (int i = 0; i < n; i++) {
		sum = 0;
		temp.paz.clear();
		temp.paz.reserve(m);
		temp.vardas = vardas.at(dist(mt));
		temp.pavarde = pavarde.at(dist(mt));
		for (int i = 0; i < m; i++) {
			temp.paz.push_back(dist(mt));
			sum += temp.paz.at(i);
		}
		temp.egz = dist(mt);
		temp.med = med(temp);
		temp.vid = sum / temp.paz.size();
		grupe.push_back(temp);
		temp.paz.clear();
	}
	visas_laikas += t.elapsed();
}