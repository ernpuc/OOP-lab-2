#include "Mylib.h"

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
	switch (uzkl_paz) {
	case 1:
		temp.galPaz = pazym(temp, sum / temp.paz.size());
		break;
	case 2:
		temp.galPaz = pazym(temp, med(temp));
		break;
	}
	cin.ignore(10000, '\n');
}

//Duomenu pildymas is failo
void pildFailas(list<studentas>& grupe, string pavad, vector<double>& test_laikai) {
	studentas temp;
	string eil;
	string elem;
	std::stringstream df_buffer;
	ifstream df;
	int nd_sk = -3;		//vardas, pavarde ir egzaminas nera iskaiciuojami
	double sum = 0;
	int paz;
	df.open(pavad);
	if (!df) {
		throw std::runtime_error("Toks failas neegzistuoja. Bandykite ivesti is naujo: ");
	}
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
		switch (uzkl_paz) {
		case 1:
			temp.galPaz = pazym(temp, sum / temp.paz.size());
			break;
		case 2:
			temp.galPaz = pazym(temp, med(temp));
			break;
		}
		grupe.push_back(temp);
	}
	test_laikai.push_back(grupe.size());
	test_laikai.push_back(t.elapsed());
}

//Atsitiktiniu duomenu generavimas
void pildRandom(list<studentas>& grupe) {
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


	list<string> vardas{ "Lukas", "Matas", "Adomas", "Nojus", "Kajus", "Motiejus", "Markas", "Benas", "Herkus", "Jonas", "Dominykas" };
	list<string> pavarde{ "Kazlauskas", "Petrauskas", "Jankauskas", "Butkus", "Paulauskas", "Vasiliauskas", "Baranauskas", "Urbonas", "Navickas", "Ramanauskas", "Savickas" };

	
	for (int i = 0; i < n; i++) {
		sum = 0;
		temp.paz.clear();
		auto ptr_v = vardas.begin();
		auto ptr_p = pavarde.begin();
		advance(ptr_v, dist(mt));
		advance(ptr_p, dist(mt));
		temp.vardas = *ptr_v;
		temp.pavarde = *ptr_p;
		for (int i = 0; i < m; i++) {
			temp.paz.push_back(dist(mt));
			sum += temp.paz.back();
		}
		temp.egz = dist(mt);
		switch (uzkl_paz) {
		case 1:
			temp.galPaz = pazym(temp, sum / temp.paz.size());
			break;
		case 2:
			temp.galPaz = pazym(temp, med(temp));
			break;
		}
		grupe.push_back(temp);
		temp.paz.clear();
	}
}