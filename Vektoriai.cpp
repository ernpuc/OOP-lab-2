#include "Mylib.h"

int main() {
	vector<studentas> grupe;
	studentas temp;
	int n = 0;
	int uzkl = 0;
	bool failas = false;
	do {
		cout << "Ar norite duomenys ivesti patys (1), ar ivesti is failo (2), ar generuoti atsitiktinai (3)? ";
		cin >> uzkl;
		if (!cin) {
			cin.clear();
			cin.ignore(10000, '\n');
		}
	} while (uzkl != 1 && uzkl != 2 && uzkl != 3);
	cin.ignore(10000, '\n');
	switch (uzkl) {
	case 1:		//Ranka daromas studentu duomenu ivedimas
		while (uzkl == 1) {
			pild(temp);
			grupe.push_back(temp);

			do {
				cout << "Ar norite ivesti dar vieno studento duomenis (1), ar baigti ivedima (2)? ";
				cin >> uzkl;
				if (!cin) {
					cin.clear();
					cin.ignore(10000, '\n');
				}
			} while (uzkl != 1 && uzkl != 2);
		}
		break;
	case 2:		//Duomenu ivedimas is failo
		pildFailas(grupe);
		failas = true;
		break;
	case 3:		//Atsitiktinai daromas studentu duomenu ivedimas
		pildRandom(grupe);
		break;
	default:
		break;
	}

	sort(grupe.begin(), grupe.end(), palyg);
	do {
		cout << "Ar norite kad galutinis pazymys butu skaiciuojamas pagal vidurki (1), pagal mediana (2), ar abu (3)? ";
		cin >> uzkl;
		if (!cin) {
			cin.clear();
			cin.ignore(10000, '\n');
		}
	} while (uzkl != 1 && uzkl != 2 && uzkl != 3);
	if (failas == true) spausdFailas(grupe, uzkl);
	else spausd(grupe, uzkl);
}