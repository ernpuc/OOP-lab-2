#include "Mylib.h"

void spausdinti(deque<studentas>& grupe, deque<double>& test_laikai) {
	switch (uzkl_spausd) {
	case 1:
		skirst(grupe, uzkl_paz, test_laikai);
		break;
	case 2:
		spausdConsole(grupe, uzkl_paz);
		break;
	}
}

//Rezultatu spausdinimas
void spausdConsole(deque<studentas>& grupe, int uzkl) {
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
	}
}

void skirst(deque<studentas>& grupe, int uzkl, deque<double>& test_laikai) {
	Timer t;
	sort(grupe.begin(), grupe.end(), palygPaz);
	test_laikai.push_back(t.elapsed());
	t.reset();

	deque<studentas> kieti;
	deque<studentas> vargsai;
	switch (uzkl_skirst) {
	case 1:
		skirstyti1(grupe, vargsai, kieti);
		test_laikai.push_back(t.elapsed());
		t.reset();
		spausdFailas(vargsai, kieti, uzkl, test_laikai);
		break;
	case 2:
		kieti = skirstyti2(grupe);
		test_laikai.push_back(t.elapsed());
		t.reset();
		spausdFailas(grupe, kieti, uzkl, test_laikai);
		break;
	case 3:
		kieti = skirstyti3(grupe);
		test_laikai.push_back(t.elapsed());
		t.reset();
		spausdFailas(grupe, kieti, uzkl, test_laikai);
		break;
	}
}

//Rezultatu spausdinimas
void spausdFailas(deque<studentas> vargsai, deque<studentas> kieti, int uzkl, deque<double>& test_laikai) {
	Timer t;
	sort(vargsai.begin(), vargsai.end(), palygVard);
	sort(kieti.begin(), kieti.end(), palygVard);
	test_laikai.push_back(t.elapsed());
	switch (uzkl) {
	case 1:
		failas(vargsai, "vargsai.txt", "(vid.)", test_laikai);
		failas(kieti, "kieti.txt", "(vid.)", test_laikai);
		break;
	case 2:
		failas(vargsai, "vargsai.txt", "(med.)", test_laikai);
		failas(kieti, "kieti.txt", "(med.)", test_laikai);
		break;
	default:
		break;
	}
}

void failas(deque<studentas>& grupe, string pavad, string uzkl_paz, deque<double>& test_laikai) {
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

void skirstyti1(deque<studentas> grupe, deque<studentas>& grupe1, deque<studentas>& grupe2) {
	for (auto& stud : grupe) {
		if (stud.galPaz() < 5.0) grupe1.push_back(stud);
		else grupe2.push_back(stud);
	}
	//remove_copy_if(grupe.begin(), grupe.end(), std::back_inserter(grupe1), galDaugiau5);
	//copy_if(grupe.begin(), grupe.end(), std::back_inserter(grupe2), galDaugiau5);
}

deque<studentas> skirstyti2(deque<studentas>& grupe) {
	deque<studentas> kieti;
	for (auto i = grupe.end(); i != grupe.begin(); i--) {
		if (grupe.back().galPaz() >= 5.0) kieti.push_back(grupe.back()), grupe.pop_back();
		else break;
	}
	//copy_if(grupe.begin(), grupe.end(), std::back_inserter(kieti), galDaugiau5);
	//remove_if(grupe.begin(), grupe.end(), galDaugiau5);
	return kieti;
}

deque<studentas> skirstyti3(deque<studentas>& grupe) {
	auto low = find_if(grupe.begin(), grupe.end(), galDaugiau5);
	//auto low = lower_bound(grupe.begin(), grupe.end(), 5.0, palygGal);
	deque<studentas> kieti(low, grupe.end());
	grupe.resize(grupe.size() - kieti.size());
	return kieti;
}

void spausdLentele(deque <deque< double >> laikai) {
	int n = laikai.at(0).size();
	deque<string> tekstas{ "Irasu skaicius: ", "Failo nuskaitymas", "Duomenu rusiavimas pagal pazymi", "Duomenu skirstymas", "Duomenu rusiavimas pagal pavardes", "Rezultatu spausdinimas i vargsai.txt", "Rezultatu spausdinimas i kieti.txt", "Visas programos vykdymo laikas:" };
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

void spausdLentele(deque<double> laikai) {
	deque<string> tekstas{ "Irasu skaicius: ", "Failo nuskaitymas", "Duomenu rusiavimas pagal pazymi", "Duomenu skirstymas", "Duomenu rusiavimas pagal pavardes", "Rezultatu spausdinimas i vargsai.txt", "Rezultatu spausdinimas i kieti.txt", "Visas programos vykdymo laikas:" };
	string line1(41, '-'), line2(16, '-');
	cout << endl << "| " << left << setw(39) << tekstas.at(0) << " |" << right << setw(13) << int(laikai.at(0)) << "   |" << endl;
	cout << "|" << line1 << "|" << line2 << "|" << endl;
	for (int i = 1; i < laikai.size(); i++) {
		cout << "| " << left << setw(39) << tekstas.at(i) << " |" << right << setw(13) << to_string(laikai.at(i)) << "s " << " |" << endl;
	}
}
