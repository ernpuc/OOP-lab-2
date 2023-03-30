#include "Mylib.h"

void spausdinti(vector<studentas>& grupe, vector<double>& test_laikai) {
	switch (uzkl_spausd) {
	case 1:
		skirstyti(grupe, uzkl_paz, test_laikai);
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
void skirstyti(vector<studentas>& grupe, int uzkl, vector<double>& test_laikai) {
	Timer t;
	sort(grupe.begin(), grupe.end(), palygPaz);
	test_laikai.push_back(t.elapsed());
	t.reset();
	
	auto low = lower_bound(grupe.begin(), grupe.end(), 5.0, palygGal);
	vector<studentas> kieti(low, grupe.end());
	grupe.resize(grupe.size() - kieti.size());
	
	test_laikai.push_back(t.elapsed());
	t.reset();
	sort(grupe.begin(), grupe.end(), palygVard);
	sort(kieti.begin(), kieti.end(), palygVard);
	test_laikai.push_back(t.elapsed());
	switch (uzkl) {
	case 1:
		spausdFailas(grupe, "vargsai.txt", "(vid.)", test_laikai);
		spausdFailas(kieti, "kieti.txt", "(vid.)", test_laikai);
		break;
	case 2:
		spausdFailas(grupe, "vargsai.txt", "(med.)", test_laikai);
		spausdFailas(kieti, "kieti.txt", "(med.)", test_laikai);
		break;
	default:
		break;
	}
}

void spausdFailas(vector<studentas>& grupe, string pavad, string uzkl_paz, vector<double>& test_laikai) {
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
	test_laikai.push_back(t.elapsed());
}

void spausdLentele(vector <vector< double >> laikai) {
	int n = laikai.at(0).size();
	vector<string> tekstas{ "Irasu skaicius: ", "Failo nuskaitymas", "Duomenu rusiavimas pagal pazymi", "Duomenu skirstymas", "Duomenu rusiavimas pagal pavardes", "Rezultatu spausdinimas i vargsai.txt", "Rezultatu spausdinimas i kieti.txt", "Visas programos vykdymo laikas:" };
	for (int i = 0; i < laikai.size(); i++) if (laikai.at(i).size() != n) return;
	ofstream rf("testavimas.txt");
	rf << "Failu testavimo rezultatai: " << endl;
	rf << endl << "| " << left << setw(39) << tekstas.at(0);
	for (int i = 0; i < laikai.size(); i++) {
		rf << " |" << right << setw(13) << int(laikai[i][0]) << "  ";
	}
	rf << " |" << endl;
	string line1(41, '-'), line2(16, '-');
	rf << "|" << line1 << "|";
	for (int i = 0; i < laikai.size(); i++) rf << line2 << "|";
	rf << endl;
	for (int i = 1; i < n; i++) {
		rf << "| " << left << setw(39) << tekstas.at(i);
		for (int j = 0; j < laikai.size(); j++) {
			rf << " |" << right << setw(13) << to_string(laikai[j][i]) << "s ";
		}
		rf << " |" << endl;
	}
	rf.close();
}

void spausdLentele(vector<double> laikai) {
	vector<string> tekstas{ "Irasu skaicius: ", "Failo nuskaitymas", "Duomenu rusiavimas pagal pazymi", "Duomenu skirstymas", "Duomenu rusiavimas pagal pavardes", "Rezultatu spausdinimas i vargsai.txt", "Rezultatu spausdinimas i kieti.txt", "Visas programos vykdymo laikas:" };
	string line1(41, '-'), line2(16, '-');
	cout << endl << "| " << left << setw(39) << tekstas.at(0) << " |" << right << setw(13) << int(laikai.at(0)) << "   |" << endl;
	cout << "|" << line1 << "|" << line2 << "|" << endl;
	for (int i = 1; i < laikai.size(); i++) {
		cout << "| " << left << setw(39) << tekstas.at(i) <<  " |" << right << setw(13) << to_string(laikai.at(i)) << "s " << " |" << endl;
	}
}
