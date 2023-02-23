#include "Mylib.h"

//Duomenu ivedimas ranka
void pild(studentas& temp) {
	cout << "Iveskite varda ir pavarde: ";
	cin >> temp.vardas >> temp.pavarde;
	temp.paz.clear();
	int tmp;
	do {
		cout << "Iveskite pazymius. Noredami baigti iveskite bet koki kita simboli: ";
		do {
			cin >> tmp;
			if (cin && tmp >= 0 && tmp <= 10) {
				temp.paz.push_back(tmp);
			}
			else if (cin && tmp < 0 || tmp > 10) {
				temp.paz.clear();
				break;
			}
		} while (cin);
			
		
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
void spausd(studentas* grupe, string uzkl, int n) {
	cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20);
	switch (uzkl[0]) {
	case 'v':
	case 'V':
		cout << "Galutinis (vid.)" << endl;
		cout << "----------------------------------------------" << endl;
		for (int i = 0; i < n; i++) {
			cout << left << setw(15) << grupe[i].vardas << setw(15) << grupe[i].pavarde;
			cout << fixed << setprecision(2) << pazym(grupe[i], vid(grupe[i])) << endl;
		}
		break;
	case 'm':
	case 'M':
		cout << "Galutinis (med.)" << endl;
		cout << "----------------------------------------------" << endl;
		for (int i = 0; i < n; i++) {
			cout << left << setw(15) << grupe[i].vardas << setw(15) << grupe[i].pavarde;
			cout << fixed << setprecision(2) << pazym(grupe[i], med(grupe[i])) << endl;
		}
		break;
	case 'a':
	case 'A':
		cout << "Galutinis (vid.)" << "Galutinis (med.)" << endl;
		cout << "------------------------------------------------------------------" << endl;
		for (int i = 0; i < n; i++) {
			cout << left << setw(15) << grupe[i].vardas << setw(15) << grupe[i].pavarde;
			cout << fixed << setprecision(2) << setw(20) << pazym(grupe[i], vid(grupe[i])) << pazym(grupe[i], med(grupe[i])) << endl;
		}
		break;
	default:
		break;
	}
}

//Galutinio pazymio skaiciavimas
double pazym(studentas temp, double x) {
	return 0.4 * x + 0.6 * temp.egz;
}

//Pazymiu vidurkio skaiciavimas
double vid(studentas temp) {
	double suma = 0;
	int n = temp.paz.size();
	for (int i = 0; i < n; i++) {
		suma += temp.paz[i];
	}
	return suma / n;
}

//Pazymiu medianos skaiciavimas
double med(studentas temp) {
	rikiuoja(temp);
	int n = temp.paz.size();
	if (n % 2 != 0) return double(temp.paz[n / 2]);
	else return double(temp.paz[(n - 1) / 2] + temp.paz[n / 2]) / 2;
}

//Pazymiu rikiavimas
void rikiuoja(studentas& temp) {
	int n = temp.paz.size();
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (temp.paz[i] > temp.paz[j]) swap(temp.paz[i], temp.paz[j]);
}

//Atsitiktiniu duomenu generavimas
void pildRandom(studentas& temp, int m) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, 10);
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
}
