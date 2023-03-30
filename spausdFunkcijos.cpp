#include "Mylib.h"

void spausdinti(vector<studentas>& grupe) {
	switch (uzkl_spausd) {
	case 1:
		skirstyti(grupe, uzkl_paz);
		break;
	case 2:
		spausdConsole(grupe, uzkl_paz);
		break;
	}
}



//Rezultatu spausdinimas
void spausdConsole(vector<studentas>& grupe, int uzkl) {
	sort(grupe.begin(), grupe.end(), palygVard);
	cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20);
	switch (uzkl) {
	case 1:
		cout << "Galutinis (vid.)" << endl;
		cout << "----------------------------------------------" << endl;
		for (auto& stud : grupe) {
			cout << stud << endl;
		}
		break;
	case 2:
		cout << "Galutinis (med.)" << endl;
		cout << "----------------------------------------------" << endl;
		for (auto& stud : grupe) {
			cout << stud << endl;
		}
		break;
	default:
		break;
	}
}

//Rezultatu spausdinimas
void skirstyti(vector<studentas>& grupe, int uzkl) {
	Timer t;
	sort(grupe.begin(), grupe.end(), palygPaz);
	spausdLaikas("Duomenu rusiavimas pagal pazymi", t.elapsed());
	t.reset();
	auto low = lower_bound(grupe.begin(), grupe.end(), 5.0, palygGal);
	vector<studentas> kieti(low, grupe.end());
	grupe.resize(grupe.size() - kieti.size());
	spausdLaikas("Duomenu skirstymas", t.elapsed());
	t.reset();
	sort(grupe.begin(), grupe.end(), palygVard);
	sort(kieti.begin(), kieti.end(), palygVard);
	spausdLaikas("Duomenu rusiavimas pagal pavardes", t.elapsed());
	switch (uzkl) {
	case 1:
		spausdFailas(grupe, "vargsai.txt", "(vid.)");
		spausdFailas(kieti, "kieti.txt", "(vid.)");
		break;
	case 2:
		spausdFailas(grupe, "vargsai.txt", "(med.)");
		spausdFailas(kieti, "kieti.txt", "(med.)");
		break;
	default:
		break;
	}
}

void spausdFailas(vector<studentas>& grupe, string pavad, string uzkl_paz) {
	std::stringstream buffer;
	Timer t;
	ofstream rf(pavad);
	buffer << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis " + uzkl_paz << endl;
	buffer << "----------------------------------------------" << endl;
	for (auto& stud : grupe) {
		buffer << stud << endl;
	}
	rf << buffer.str();
	rf.close();
	spausdLaikas("Rezultatu spausdinimas i " + pavad, t.elapsed());
}

void spausdLaikas(string tekstas, double laikas) {
	cout << "| " << left << setw(39) << tekstas << setw(5) << "|" << setw(10) << right << to_string(laikas) << "s |" << endl;
}