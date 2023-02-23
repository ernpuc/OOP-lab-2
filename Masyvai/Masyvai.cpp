#include "Mylib.h"

int main() {
	studentas* grupe;
	int n;
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

		grupe = new studentas[n];
		int m;
		cout << "Koks yra galimas pazymiu kiekis? ";
		cin >> m;

		//tikrinama ivestis
		while (!cin || n < 1) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Pazymiu kiekis turi buti naturalusis skaicius. ";
			cout << "Koks yra galimas pazymiu kiekis? ";
			cin >> m;
		}

		for (int i = 0; i < n; i++) pildRandom(grupe[i], m);
	}
	
	//Ranka daromas studentu duomenu ivedimas
	else {
		n = 1;
		grupe = new studentas[n];
		do {
			pild(grupe[n - 1]);
			studentas* temp = new studentas[n];
			copy(grupe, grupe + n, temp);
			delete[] grupe;
			grupe = new studentas[n + 1];
			copy(temp, temp + n, grupe);
			do {
				cout << "Ar norite ivesti dar vieno studento duomenis? (T/N) ";
				cin >> uzkl;
			} while (uzkl != "t" && uzkl != "T" && uzkl != "n" && uzkl != "N");
			n++;
		} while (uzkl == "t" || uzkl == "T");
		n--;
	}

	do {
		cout << "Ar norite kad galutinis pazymys butu skaiciuojamas pagal vidurki, pagal mediana, ar abu? (V/M/A) ";
		cin >> uzkl;
	} while (uzkl != "v" && uzkl != "V" && uzkl != "m" && uzkl != "M" && uzkl != "a" && uzkl != "A");

	spausd(grupe, uzkl, n);
}