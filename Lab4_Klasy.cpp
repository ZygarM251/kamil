#pragma once
#include "Lab4_Klasy.h"

random_device srng;
mt19937 rng;


CzyWiekszy::CzyWiekszy(bool A) { czyInt = A; }
test::test() {
	//rng.seed(srng());
	uniform_int_distribution<int> uniDistInt(0, 9);
	uniform_real_distribution<double> uniDistReal(0, 3);
	a = uniDistInt(rng);
	b = uniDistReal(rng);
}

ostream& operator<<(ostream& str, test& test) {
	str << "("<< test.a << ", " << test.b <<")";
	return str;
}

ostream& operator<<(ostream& str, vector<test>&wek) {
	str << "[";
	for (test& elem : wek) {
		str << elem << ", ";
	}
	str << "]";
	return str;
}

bool CzyWiekszy::operator()(test& wybrany, test& ref) {
	if (czyInt) {
		return(wybrany.a > ref.a);}
	else {
		return(wybrany.b > ref.b);}
}

ostream& operator<<(ostream& str, list<int>& lista) {
	str << "[";
	for (int& elem : lista) {
		str << elem << ", ";
	}
	str << "]";
	return str;
}

ostream& operator<<(ostream& str, vector<int>& wek) {
	str << "[";
	for (int& elem : wek) {
		str << elem << ", ";
	}
	str << "]";
	return str;
}