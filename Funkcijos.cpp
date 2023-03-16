#include "Mylib.h"

void menu(string tekstas, int& uzkl, int sk) {
	bool geraIvestis = false;
	cout << "Galimos komandos:" << endl;
	cout << tekstas;
	do {
		cout << "Iveskite norimos komandos numeri: ";
		cin >> uzkl;
		for (int i = 1; i <= sk; i++) if (uzkl == i) geraIvestis = true;
		if (!cin) {
			cin.clear();
		}
		cin.ignore(10000, '\n');
	} while (!geraIvestis);
}

void intUzklausa(string kint_pavad, int& n) {
	while (true) {
		try {
			cout << "Koks yra " << kint_pavad << "? ";
			cin >> n;
			if (!cin || n < 1) {
				throw std::runtime_error("Bloga ivestis, " + kint_pavad + " turi buti naturalusis skaicius. \n");
			}
			else break;
		}
		catch (std::runtime_error& e) {
			cin.clear();
			cin.ignore(10000, '\n'); 
			cout << e.what();
		}
	}
	cin.ignore(10000, '\n');
}

//naujo duomenu failo generavimas
void generuoti() {
	int n;
	int m;
	string pavad;
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, 10);

	intUzklausa("irasu skaicius", n);
	intUzklausa("pazymiu skaicius", m);
	pavad = "stud" + to_string(n) + ".txt";
	ofstream rf(pavad);

	Timer t;
	rf << left << setw(16) << "Vardas" << setw(16) << "Pavarde" << right;
	for (int i = 1; i <= m; i++) rf << setw(5) << "ND" + to_string(i);
	rf << setw(12) << "Egzaminas\n";
	for (int i = 1; i <= n; i++) {
		rf << left << setw(16) << "Vardas" + to_string(i) << setw(16) << "Pavarde" + to_string(i) << right;
		for (int j = 0; j < m; j++) rf << setw(5) << dist(mt);
		rf << setw(8) << dist(mt) << "\n";
	}
	rf.close();
	cout << "Failas pavadinimu " << pavad << " sugeneruotas per " << t.elapsed() << "s" << endl;
	visas_laikas += t.elapsed();
}

//Galutinio pazymio skaiciavimas
double pazym(studentas temp, double x) {
	return 0.4 * x + 0.6 * temp.egz;
}

//Pazymiu medianos skaiciavimas
double med(studentas temp) {
	sort(temp.paz.begin(), temp.paz.end());
	int n = temp.paz.size();
	if (n % 2 != 0) return double(temp.paz.at(size_t(n) / 2));
	else return double(temp.paz.at((size_t(n) - 1) / 2) + temp.paz.at(size_t(n) / 2)) / 2;
}


bool palygVard(studentas& t1, studentas& t2) {
	if (t1.vardas != t2.vardas) return t1.vardas < t2.vardas;
	else return t1.pavarde < t2.pavarde;
}

bool palygPaz(studentas& t1, studentas& t2) {
	return t1.galPaz < t2.galPaz;
}

bool palygGal(const studentas& stud, const double& x) {
	return stud.galPaz < x;
}