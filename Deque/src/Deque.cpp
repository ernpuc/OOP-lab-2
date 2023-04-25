#include "Mylib.h"

int main() {
	deque <deque< double >> laikai;
	deque <double> test_laikai;
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