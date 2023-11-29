#pragma once
#include <iostream>
#include "Lab3_Klasy.h"



void Testy::raport(const char* nazwa, bool wynik) {
	cerr << "test " << nazwa << ":\t";
	if (wynik) cerr << "OK" << endl;
	else cerr << "FAIL" << endl;
}

void Testy::testMostFrequentDouble() {
	double tab[] = { 1.1,2.2,3.3,2.2 };
	int liczbaPowtorzen = 0;
	double wynik = mostFrequent<double, sizeof(tab) / sizeof(double)>(tab, liczbaPowtorzen);
	raport("MostFrequentDouble", liczbaPowtorzen == 2 && wynik == 2.2);
}

void Testy::testMostFrequentChar() {
	char tab[] = {'t','e','s','t'};
	int liczbaPowtorzen = 0;
	char wynik = mostFrequent<char, sizeof(tab) / sizeof(char)>(tab, liczbaPowtorzen);
	raport("MostFrequentChar", liczbaPowtorzen == 2 && wynik == 't');
}

void Testy::testAddInt() {
	int a = 1, b = 2, c = 3, d = 4;
	int* tab[10] = {&a,&b,&c};
	add<int>(tab, 10, &d);
	raport("MostAddInt", tab[3]==&d);
}

void Testy::wykonajTesty() {
	cout << endl;
	testMostFrequentDouble();
	testMostFrequentChar();
	testAddInt();
}