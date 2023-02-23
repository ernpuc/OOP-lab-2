#include "Mylib.h"

void pild(studentas& temp) {
	cout << "Iveskite varda ir pavarde: ";
	cin >> temp.vardas >> temp.pavarde;
	int* mas = new int[temp.paz_sk + 1];
	do {
		cout << "Iveskite pazymius. Noredami baigti iveskite bet koki kita simboli: ";
		while (cin >> mas[temp.paz_sk]) {
			if (mas[temp.paz_sk] > 0 && mas[temp.paz_sk] < 10) {
				temp.paz_sk++;
				int* tmp = new int[temp.paz_sk];
				copy(mas, mas + temp.paz_sk, tmp);
				delete[] mas;
				mas = new int[temp.paz_sk + 1];
				copy(tmp, tmp + temp.paz_sk, mas);
			}
			else {
				temp.paz_sk = 0;
				break;
			}
		}
		if (temp.paz_sk == 0) cout << "Ivesti galima tik sveikus skaicius nuo 0 iki 10. " << endl;
		cin.clear();
		cin.ignore(10000, '\n');
	} while (temp.paz_sk == 0);


	temp.paz = new int[temp.paz_sk];
	copy(mas, mas + temp.paz_sk, temp.paz);

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

void pildRandom(studentas& temp, int m) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, 10);
	temp.paz_sk = m;
	temp.paz = new int[temp.paz_sk];
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
	for (int i = 0; i < m; i++) temp.paz[i] = dist(mt);
	temp.egz = dist(mt);
}

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
			delete[] grupe[i].paz;
		}
		break;
	case 'm':
	case 'M':
		cout << "Galutinis (med.)" << endl;
		cout << "----------------------------------------------" << endl;
		for (int i = 0; i < n; i++) {
			cout << left << setw(15) << grupe[i].vardas << setw(15) << grupe[i].pavarde;
			cout << fixed << setprecision(2) << pazym(grupe[i], med(grupe[i])) << endl;
			delete[] grupe[i].paz;
		}
		break;
	case 'a':
	case 'A':
		cout << "Galutinis (med.)" << "Galutinis (vid.)" << endl;
		cout << "------------------------------------------------------------------" << endl;
		for (int i = 0; i < n; i++) {
			cout << left << setw(15) << grupe[i].vardas << setw(15) << grupe[i].pavarde;
			cout << fixed << setprecision(2) << setw(20) << pazym(grupe[i], vid(grupe[i])) << pazym(grupe[i], med(grupe[i])) << endl;
			delete[] grupe[i].paz;
		}
		break;
	default:
		break;
	}
	delete[] grupe;
}

double pazym(studentas temp, double x) {
	return 0.4 * x + 0.6 * temp.egz;
}

double vid(studentas temp) {
	double suma = 0;
	for (int i = 0; i < temp.paz_sk; i++) {
		suma += temp.paz[i];
	}
	return suma / temp.paz_sk;
}

double med(studentas temp) {
	rikiuoja(temp);
	if (temp.paz_sk % 2 != 0) return double(temp.paz[temp.paz_sk / 2]);
	else return double(temp.paz[(temp.paz_sk - 1) / 2] + temp.paz[temp.paz_sk / 2]) / 2;
}

void rikiuoja(studentas& temp) {
	for (int i = 0; i < temp.paz_sk - 1; i++)
		for (int j = i + 1; j < temp.paz_sk; j++)
			if (temp.paz[i] > temp.paz[j]) swap(temp.paz[i], temp.paz[j]);
}