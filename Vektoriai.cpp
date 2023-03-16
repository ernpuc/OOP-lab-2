#include "Mylib.h"

double visas_laikas = 0;

int main() {
	vector<studentas> grupe;
	int uzkl = 0;
	
	do {
		menu("1 - generuoti nauja duomenu faila\n2 - vykdyti duomenu ivedima\n", uzkl, 2);
		switch (uzkl) {
		case 1:
			generuoti();
			break;
		case 2:
			pildyti(grupe);
			break;
		default:
			break;
		}

		if (!grupe.empty()) {
			spausdinti(grupe);
			break;
		}
		menu("1 - testi programos vykdyma\n2 - baigti programos vykdyma\n", uzkl, 2);
	} while (uzkl != 2);

	cout << "Programos vykdymas uztruko " << visas_laikas << "s" << endl;
}