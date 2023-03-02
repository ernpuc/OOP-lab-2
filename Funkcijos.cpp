#include "Mylib.h"

//Duomenu ivedimas ranka
void pild(studentas& temp) {
	cout << "Iveskite varda ir pavarde: ";
	cin >> temp.vardas >> temp.pavarde;
	temp.paz.clear();
	int tmp = 0;
	do {
		cout << "Iveskite pazymius. Noredami baigti iveskite -1. " << endl;
		do {
			cin >> tmp;
			if (cin) {
				if (tmp >= 0 && tmp <= 10) {
					temp.paz.push_back(tmp);
				}
				else if (tmp != -1) {
					temp.paz.clear();
					break;
				}
			}
			else {
				temp.paz.clear();
				break;
			}
		} while (tmp != -1);
			
		
		if (temp.paz.size() == 0) cout << "Ivesti galima tik sveikus skaicius nuo 0 iki 10. " << endl;
		cin.clear();
		cin.ignore(10000, '\n');
	} while (temp.paz.size() == 0);			//ciklas kartojamas tuo atveju, jeigu buvo bloga ivestis

	cout << "Iveskite egzamino paz. ";
	cin >> temp.egz;
	while (!cin || temp.egz < 0 || temp.egz > 10) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Egzamino paz. turi buti skaicius nuo 0 iki 10. " << endl;
		cout << "Iveskite egzamino paz. ";
		cin >> temp.egz;
	}
}

//Rezultatu spausdinimas
void spausd(vector<studentas>& grupe, int uzkl) {
	cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20);
	switch (uzkl) {
	case 1:
		cout << "Galutinis (vid.)" << endl;
		cout << "----------------------------------------------" << endl;
		for (auto& stud : grupe) {
			cout << left << setw(15) << stud.vardas << setw(15) << stud.pavarde;
			cout << fixed << setprecision(2) << pazym(stud, vid(stud)) << endl;
		}
		break;
	case 2:
		cout << "Galutinis (med.)" << endl;
		cout << "----------------------------------------------" << endl;
		for (auto& stud : grupe) {
			cout << left << setw(15) << stud.vardas << setw(15) << stud.pavarde;
			cout << fixed << setprecision(2) << pazym(stud, med(stud)) << endl;
		}
		break;
	case 3:
		cout << "Galutinis (vid.)" << "Galutinis (med.)" << endl;
		cout << "------------------------------------------------------------------" << endl;
		for (auto& stud : grupe) {
			cout << left << setw(15) << stud.vardas << setw(15) << stud.pavarde;
			cout << fixed << setprecision(2) << setw(20) << pazym(stud, vid(stud)) << pazym(stud, med(stud)) << endl;
		}
		break;
	default:
		break;
	}
}

//Rezultatu spausdinimas
void spausdFailas(vector<studentas>& grupe, int uzkl) {
	ofstream rf("rezultatai.txt");
	std::stringstream buffer;
	switch (uzkl) {
	case 1:
		buffer << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (vid.)" << endl;
		buffer << "----------------------------------------------" << endl;
		for (auto& stud : grupe) {
			buffer << left << setw(15) << stud.vardas << setw(15) << stud.pavarde << fixed << setprecision(2) << pazym(stud, vid(stud)) << endl;
		}
		rf << buffer.str();
		break;
	case 2:
		buffer << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (med.)" << endl;
		buffer << "----------------------------------------------" << endl;
		for (auto& stud : grupe) {
			buffer << left << setw(15) << stud.vardas << setw(15) << stud.pavarde << fixed << setprecision(2) << pazym(stud, med(stud)) << endl;
		}
		rf << buffer.str();
		break;
	case 3:
		buffer << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (vid.)" << "Galutinis (med.)" << endl;
		buffer << "------------------------------------------------------------------" << endl;
		for (auto& stud : grupe) {
			buffer << left << setw(15) << stud.vardas << setw(15) << stud.pavarde << fixed << setprecision(2) << setw(20) << pazym(stud, vid(stud)) << pazym(stud, med(stud)) << endl;
		}
		rf << buffer.str();
		break;
	default:
		break;
	}
	cout << "Rezultatai irasyti i 'rezultatai.txt'" << endl;
}

//Galutinio pazymio skaiciavimas
double pazym(studentas temp, double x) {
	return 0.4 * x + 0.6 * temp.egz;
}

//Pazymiu vidurkio skaiciavimas
double vid(studentas temp) {
	double suma = 0;
	for (auto& paz : temp.paz) {
		suma += paz;
	}
	return suma / temp.paz.size();
}

//Pazymiu medianos skaiciavimas
double med(studentas temp) {
	sort(temp.paz.begin(), temp.paz.end());
	int n = temp.paz.size();
	if (n % 2 != 0) return double(temp.paz.at(n / 2));
	else return double(temp.paz.at((n - 1) / 2) + temp.paz.at(n / 2)) / 2;
}


bool palyg(studentas& t1, studentas& t2) {
	if (t1.vardas != t2.vardas) return t1.vardas < t2.vardas;
	else return t1.pavarde < t2.pavarde;
}

//Duomenu pildymas is failo
void pildFailas(vector<studentas>& grupe) {
	studentas temp;
	string eil;
	string elem;
	std::stringstream df_buffer;
	string pavad;
	ifstream df;
	do {
		cout << "Iveskite failo pavadinima: ";
		cin >> pavad;
		df.open(pavad);
		if (!df) cout << "Toks failas neegzistuoja" << endl;
	} while (!df);
	

	df_buffer << df.rdbuf();
	df.close();

	if (!df_buffer.eof()) getline(df_buffer, eil);		//praleidziama pirma eilute
	while (df_buffer) {
		temp.paz.clear();
		if (!df_buffer.eof()) {
			getline(df_buffer, eil);
			for (auto i = eil.begin(); i < eil.end(); i++) if (*i == ',') *i = '.';
			std::stringstream eilut(eil);
			eilut >> temp.vardas >> temp.pavarde;
			while (eilut >> elem) {
				temp.paz.push_back(stoi(elem));
			}
			temp.egz = temp.paz.back();
			temp.paz.pop_back();
		}
		else break;
		grupe.push_back(temp);
	}
}

//Atsitiktiniu duomenu generavimas
void pildRandom(vector<studentas>& grupe) {
	studentas temp;
	int n;
	cout << "Kiek studentu sudaro grupe? ";
	cin >> n;

	//tikrinama ivestis
	while (!cin || n < 1) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Grupe gali sudaryti tik naturalusis skaicius studentu. ";
		cout << "Kiek studentu sudaro grupe? ";
		cin >> n;
	}

	int m;
	cout << "Koks yra galimas pazymiu kiekis? ";
	cin >> m;

	//tikrinama ivestis
	while (!cin || m < 1) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Pazymiu kiekis turi buti naturalusis skaicius. ";
		cout << "Koks yra galimas pazymiu kiekis? ";
		cin >> m;
	}

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, 10);
	for (int i = 0; i < n; i++) {
		temp.egz = dist(mt);
		temp.paz.clear();
		temp.paz.reserve(m);
		for (int i = 0; i < m; i++) temp.paz.push_back(dist(mt));

		switch (dist(mt)) {
		case 0:
			temp.vardas = "Lukas";
			break;
		case 1:
			temp.vardas = "Matas";
			break;
		case 2:
			temp.vardas = "Adomas";
			break;
		case 3:
			temp.vardas = "Nojus";
			break;
		case 4:
			temp.vardas = "Kajus";
			break;
		case 5:
			temp.vardas = "Motiejus";
			break;
		case 6:
			temp.vardas = "Markas";
			break;
		case 7:
			temp.vardas = "Benas";
			break;
		case 8:
			temp.vardas = "Herkus";
			break;
		case 9:
			temp.vardas = "Jonas";
			break;
		case 10:
			temp.vardas = "Dominykas";
			break;
		}
		switch (dist(mt)) {
		case 0:
			temp.pavarde = "Kazlauskas";
			break;
		case 1:
			temp.pavarde = "Petrauskas";
			break;
		case 2:
			temp.pavarde = "Jankauskas";
			break;
		case 3:
			temp.pavarde = "Butkus";
			break;
		case 4:
			temp.pavarde = "Paulauskas";
			break;
		case 5:
			temp.pavarde = "Vasiliauskas";
			break;
		case 6:
			temp.pavarde = "Baranauskas";
			break;
		case 7:
			temp.pavarde = "Urbonas";
			break;
		case 8:
			temp.pavarde = "Navickas";
			break;
		case 9:
			temp.pavarde = "Ramanauskas";
			break;
		case 10:
			temp.pavarde = "Savickas";
			break;
		}
		grupe.push_back(temp);
		temp.paz.clear();
	}
}
