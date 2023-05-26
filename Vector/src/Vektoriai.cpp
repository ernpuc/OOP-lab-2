/*! \file Vektoriai.cpp */
#include "Mylib.h"

int main() {
	//zmogus zmog("Ernestas", "Pucinskas");
	//cout << zmog.vardas() << " " << zmog.pavarde();

	//string vardas = "vardas", pavarde = "pavarde";
	//studentas stud1(vardas, pavarde, { 1, 2, 3, 6 }, 8);
	//studentas stud2(stud1);
	//studentas stud3;
	//stud3 = stud2;
	//stud1.setPaz({ 4, 7, 9 });
	//stud1.setVardas("asdg");
	//stud2.setPavarde("fdsh");
	//stud2.setPaz({ 8, 10, 7, 5, 3 });
	//stud3.setEgz(9);
	//cout << stud1 << endl;
	//cout << stud2 << endl;
	//cout << stud3 << endl;
	vector <vector< double >> laikai;
	vector <double> test_laikai;
	int uzkl_test = 0;
	do {
		if (uzkl_test != 2 || uzkl_vykd == 2) menu({ "generuoti nauja duomenu faila", "vykdyti testavima" }, uzkl_test);
		switch (uzkl_test) {
		case 1:
			generuoti();
			break;
		case 2:
			testuoti(test_laikai);
			if (!test_laikai.empty()) {
				laikai.push_back(test_laikai);
				spausdLentele(test_laikai);
			}
			menu({ "testi programos vykdyma nekeiciant parinkciu", "keisti parinktis", "baigti programos vykdyma" }, uzkl_vykd);
			test_laikai.clear();
			break;
		default:
			break;
		}
	} while (uzkl_vykd != 3);
	if (!laikai.empty()) spausdLentele(laikai);
}