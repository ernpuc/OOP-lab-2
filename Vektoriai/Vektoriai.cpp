#include "Mylib.h"

int main() {
	vector<studentas> grupe;
	studentas temp;
	int n = 0;
	string uzkl;

	do {
		cout << "Ar norite patys ivesti studentu duomenis? (T/N) ";
		cin >> uzkl;
	} while (uzkl != "t" && uzkl != "T" && uzkl != "n" && uzkl != "N");

	//Atsitiktinai daromas studentu duomenu ivedimas
	if (uzkl == "n" || uzkl == "N") {
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

		for (int i = 0; i < n; i++) {
			pildRandom(temp, m);
			grupe.push_back(temp);
		}
	}

	//Ranka daromas studentu duomenu ivedimas
	else while (uzkl == "t" || uzkl == "T") {
		n++;
		pild(temp);
		grupe.push_back(temp);

		do {
			cout << "Ar norite ivesti dar vieno studento duomenis? (T/N) ";
			cin >> uzkl;
		} while (uzkl != "t" && uzkl != "T" && uzkl != "n" && uzkl != "N");
	}

	do {
		cout << "Ar norite kad galutinis pazymys butu skaiciuojamas pagal vidurki, pagal mediana, ar abu? (V/M/A) ";
		cin >> uzkl;
	} while (uzkl != "v" && uzkl != "V" && uzkl != "m" && uzkl != "M" && uzkl != "a" && uzkl != "A");
	
	spausd(&grupe[0], uzkl, n);
}