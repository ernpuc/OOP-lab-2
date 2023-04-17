#include "Mylib.h"

int uzkl_iv = 0;
int uzkl_skirst = 0;
int uzkl_paz = 0;
int uzkl_spausd = 0;
int uzkl_vykd = 0;

void testuoti(vector<double>& test_laikai) {
	if (uzkl_vykd != 1) {		//jei vartotojas nera pasirinkes testi programos su tomis paciomis parinktimis
		menu({ "ivesti duomenis patiems", "ivesti duomenis is failo", "generuoti duomenis atsitiktinai" }, uzkl_iv);
		menu({ "skaiciuoti galutini pazymi pagal vidurki", "skaiciuoti galutini pazymi pagal mediana" }, uzkl_paz);
		menu({ "rezultatus isvesti i faila", "rezultatus isvesti i konsole" }, uzkl_spausd);
	}
	if (uzkl_spausd == 1) menu({ "studentus skirstyti i konteinerius 1 strategija", "studentus skirstyti i konteinerius 2 strategija", "studentus skirstyti i konteinerius 3 strategija" }, uzkl_skirst);
	Timer t;
	list<studentas> grupe;
	string pavad;
	ifstream sar;
	list<string> failai;
	int uzkl_fail = -1;
	studentas temp;
	list<string>::iterator ptr;
	vector<string> blogiPavad{ "vargsai.txt", "kieti.txt", "sar.txt", "testavimas.txt", "CMakeLists.txt", "CMakeCache.txt", "install_manifest.txt" };
	switch (uzkl_iv) {
	case 1:		//Ranka daromas studentu duomenu ivedimas
		do {
			pildConsole(temp);
			grupe.push_back(temp);
			menu({ "ivesti dar vieno studento duomenis", "baigti ivedima" }, uzkl_iv);
		} while (uzkl_iv != 2);
		break;
	case 2:		//Duomenu ivedimas is failo
		cout << endl;
		system("dir /b *.txt >sar.txt");
		sar.open("sar.txt");
		try {
			while (!sar.eof()) {
				if (sar >> pavad && gerasPavad(pavad, blogiPavad)) failai.push_back(pavad);
			}
			if (failai.empty()) throw std::runtime_error("Nera nuskaitymui tinkamu failu");
			cout << "Pasirinkite norimo failo nr: " << endl;
			menu(failai, uzkl_fail);
			ptr = failai.begin();
			advance(ptr, --uzkl_fail);
			pavad = *ptr;
		}
		catch (std::runtime_error& e) {
			cout << e.what() << endl;
			return;
		}
		
		sar.close();
		system("del sar.txt");
		cout << endl;

		do {
			t.reset();
			try {
				pildFailas(grupe, pavad, test_laikai);
			}
			catch (std::runtime_error& e) {
				cout << e.what() << endl;
			}
		} while (grupe.empty());

		//pildFailas(grupe, pavad);
		break;
	case 3:		//Atsitiktinai daromas studentu duomenu ivedimas
		pildRandom(grupe);
		break;
	default:
		break;
	}

	spausdinti(grupe, test_laikai);

	if (uzkl_iv == 2 && uzkl_spausd == 1) {			//duomenu ivedimas is failo ir isvedimas i faila
		test_laikai.push_back(t.elapsed());
	}
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
}

void menu(list<string> tekstas, int& uzkl) {
	bool geraIvestis = false;
	int n = 1;
	cout << endl << "Galimos komandos:" << endl;
	for (auto& i : tekstas) {
		cout << n << " - " << i << endl;
		n++;
	}
	do {
		cout << "Iveskite norimos komandos numeri: ";
		cin >> uzkl;
		for (int i = 1; i <= tekstas.size(); i++)
			if (uzkl == i) {
				geraIvestis = true;
				break;
			}
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

//Galutinio pazymio skaiciavimas
double pazym(studentas temp, double x) {
	return 0.4 * x + 0.6 * temp.egz;
}

//Pazymiu medianos skaiciavimas
double med(studentas temp) {
	temp.paz.sort();
	//sort(temp.paz.begin(), temp.paz.end());
	int n = temp.paz.size();
	auto ptr = temp.paz.begin();
	if (n & 1) {
		advance(ptr, n / 2);
		return *ptr;
	}
	else {
		advance(ptr, (n - 1) / 2);
		return (*ptr + *(++ptr)) / 2;
	}


	/*if (n % 2 != 0) return double(temp.paz.at(size_t(n) / 2));
	else return double(temp.paz.at((size_t(n) - 1) / 2) + temp.paz.at(size_t(n) / 2)) / 2;*/
}

bool gerasPavad(string x, vector<string> pavad) {
	for (auto& i : pavad) {
		if (i == x) return 0;
	}
	return 1;
}

bool palygVard(studentas& t1, studentas& t2) {
	return (t1.vardas < t2.vardas) ? true : (t1.pavarde < t2.pavarde);
}

bool palygPaz(studentas& t1, studentas& t2) {
	return t1.galPaz < t2.galPaz;
}

bool palygGal(const studentas& stud, const double& x) {
	return stud.galPaz < x;
}

bool galDaugiau5(studentas stud) {
	return stud.galPaz >= 5.0;
}

std::ostream& operator<< (std::ostream& out, studentas& a) {
	out << left << setw(15) << a.vardas << setw(15) << a.pavarde << fixed << setprecision(2) << a.galPaz;
	return out;
}