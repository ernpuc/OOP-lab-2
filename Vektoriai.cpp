#include "Mylib.h"

int main() {
	int uzkl_test = 0;
	do {
		if (uzkl_test != 2 || uzkl_vykd == 2) menu({ "generuoti nauja duomenu faila", "vykdyti testavima" }, uzkl_test);
		switch (uzkl_test) {
		case 1:
			generuoti();
			break;
		case 2:
			testuoti();
			menu({ "testi programos vykdyma nekeiciant parinkciu", "keisti parinktis", "baigti programos vykdyma" }, uzkl_vykd);
			break;
		default:
			break;
		}
	} while (uzkl_vykd != 3);

}