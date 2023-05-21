/*! \file Studentas.h */
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <tuple>

using std::string;
using std::vector;
using std::accumulate;
using std::tie;

/*!
   \brief Abstrakti bazinė žmogaus klasė 
*/
class zmogus {
protected:
	string vardas_;
	string pavarde_;
public:
	/*! \brief žmogaus konstruktorius */
	zmogus(string vardas = "", string pavarde = "") : vardas_(vardas), pavarde_(pavarde) {};	
	virtual string vardas() const  = 0;
	virtual string pavarde() const = 0;
	virtual void setVardas(string vardas) = 0;
	virtual void setPavarde(string pavarde) = 0;
	virtual ~zmogus() { vardas_.clear(), pavarde_.clear(); }
};

/*!
   \brief Išvestinė studento klasė
*/
class studentas: public zmogus {
private:
	vector<int> paz_;
	int egz_;
	double galPaz_;
public:
	/*! \brief studento default konstruktorius */
	studentas() : zmogus("", ""), egz_(0), galPaz_(0) {};
	/*! \brief studento konstruktorius iš įvedimo */
	studentas(std::istream& is);
	/*! \brief studento konstruktorius turint visus duomenis */
	studentas(string vardas, string pavarde, vector<int>paz, int egz) : zmogus(vardas, pavarde), paz_(paz), egz_(egz), galPaz_(0) {};
	studentas(const studentas& stud);							//!< copy konstruktorius
	studentas& operator=(const studentas& stud);				//!< copy priskyrimo operatorius
	studentas(studentas&& stud);								//!< move konstruktorius
	studentas& operator=(studentas&& stud);						//!< move priskyrimo operatorius
	string vardas() const { return vardas_; }
	string pavarde() const { return pavarde_; }
	void setVardas(string vardas) { vardas_ = vardas; }
	void setPavarde(string pavarde) { pavarde_ = pavarde; }
	void setPaz(vector<int> paz) { paz_ = paz; }
	void setEgz(int egz) { egz_ = egz; }
	void setGalPaz(double galPaz) { galPaz_ = galPaz; }
	double galPaz();
	friend std::ostream& operator<< (std::ostream& out, studentas& a);
	~studentas() { paz_.clear(); }
};

bool palygVard(studentas& t1, studentas& t2);
bool palygPaz(studentas& t1, studentas& t2);
bool galDaugiau5(studentas stud);
double pazym(int egz, double x);
double med(vector<int> paz);
//std::ostream& operator<< (std::ostream& out, studentas& a);
