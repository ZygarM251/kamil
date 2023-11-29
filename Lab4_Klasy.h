#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <list>
#include <algorithm>
#include <ranges>
#include <tuple>
using namespace std;

struct test {
	int a;
	double b;
	test();
};

class CzyWiekszy {
	bool czyInt;
public:
	CzyWiekszy(bool A);
	bool operator()(test& wybrany, test& ref);
};

ostream& operator<<(ostream& str, test& test);
ostream& operator<<(ostream& str, vector<test>& wek);
ostream& operator<<(ostream& str, list<int>& lista);
ostream& operator<<(ostream& str, vector<int>& wek);