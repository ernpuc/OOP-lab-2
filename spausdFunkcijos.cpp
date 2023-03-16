#include "Mylib.h"

void spausdinti(vector<studentas>& grupe) {
	int uzkl_paz;
	int uzkl_spausd;

	menu("1 - skaiciuoti galutini pazymi pagal vidurki \n2 - skaiciuoti galutini pazymi pagal mediana \n", uzkl_paz, 2);
	Timer t;
	switch (uzkl_paz) {
	case 1:
		for (auto& stud : grupe) {
			stud.galPaz = pazym(stud, stud.vid);
		}
		break;
	case 2:
		for (auto& stud : grupe) {
			stud.galPaz = pazym(stud, stud.med);
		}
		break;
	}
	visas_laikas += t.elapsed();
	menu("1 - spausdinti duomenis i faila \n2 - spausdinti duomenis i konsole \n", uzkl_spausd, 2);

	t.reset();
	switch (uzkl_spausd) {
	case 1:
		cout << "Duomenys rusiuojami, skirstomi ir rasomi i failus" << endl;
		skirstyti(grupe, uzkl_paz);
		break;
	case 2:
		spausdConsole(grupe, uzkl_paz);
		break;
	}
	visas_laikas += t.elapsed();
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
			cout << left << setw(15) << stud.vardas << setw(15) << stud.pavarde;
			cout << fixed << setprecision(2) << stud.galPaz << endl;
		}
		break;
	case 2:
		cout << "Galutinis (med.)" << endl;
		cout << "----------------------------------------------" << endl;
		for (auto& stud : grupe) {
			cout << left << setw(15) << stud.vardas << setw(15) << stud.pavarde;
			cout << fixed << setprecision(2) << stud.galPaz << endl;
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
	auto low = lower_bound(grupe.begin(), grupe.end(), 5.0, palygGal);
	vector<studentas> kieti(low, grupe.end());
	grupe.resize(std::distance(grupe.begin(), low) + 1);
	cout << "Duomenu rusiavimas ir skirstymas uztruko " << t.elapsed() << "s" << endl;
	t.reset();
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
	
	cout << "Rezultatu failu spausdinimas uztruko " << t.elapsed() << "s" << endl;
}

void spausdFailas(vector<studentas>& grupe, string pavad, string uzkl_paz) {
	sort(grupe.begin(), grupe.end(), palygVard);
	std::stringstream buffer;
	ofstream rf(pavad);
	buffer << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis " + pavad << endl;
	buffer << "----------------------------------------------" << endl;
	for (auto& stud : grupe) {
		buffer << left << setw(15) << stud.vardas << setw(15) << stud.pavarde << fixed << setprecision(2) << stud.galPaz << endl;
	}
	rf << buffer.str();
	rf.close();
}