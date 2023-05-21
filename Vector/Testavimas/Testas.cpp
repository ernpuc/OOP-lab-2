#include "pch.h"
#include "../Vector/include/Mylib.h"
#include "../Vector/include/Studentas.h"
#include "../Vector/src/Studentas.cpp"
#include "../Vector/src/Funkcijos.cpp"
#include "../Vector/src/pildFunkcijos.cpp"
#include "../Vector/src/spausdFunkcijos.cpp"

vector<int> paz1 = { 1, 2, 3 };
vector<int> paz2 = { 5, 6, 7, 8 };
studentas stud1("vardas1", "pavarde1", paz1, 5);
studentas stud2("vardas2", "pavarde2", paz2, 8);
TEST(StudTestai, med_) {
	EXPECT_EQ(med(paz1), 2);
	EXPECT_EQ(med(paz2), 6.5);
}

TEST(StudTestai, galDaugiau5_) {
	EXPECT_FALSE(galDaugiau5(stud1));
	EXPECT_TRUE(galDaugiau5(stud2));
}

TEST(StudTestai, palygPaz_) {
	EXPECT_TRUE(palygPaz(stud1, stud2));
}

TEST(StudTestai, palygVard_) {
	EXPECT_TRUE(palygVard(stud1, stud2));
}
