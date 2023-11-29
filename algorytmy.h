#pragma once
#include<iostream>
#include<cmath>
#include<cstring>
#include<iomanip>
using namespace std;



enum class kierunek
{
	rosnaco,
	malejaco
};

void sortuj(double* tab, const size_t SIZE, kierunek kier);

int wyszukaj(double* tab, const size_t SIZE, double szukana);

void skrambluj(double* tab, const size_t SIZE);

double stopienUprzadkowania(double* tab, const size_t SIZE, kierunek kier);

void wypisz(double* tab, const size_t SIZE, char sep);

class PrzetwarzanieTablic
{
public:
	virtual void operator()(double *tab, const size_t SIZE) = 0;
};

class Sortuj: public PrzetwarzanieTablic
{
public:
	virtual void operator()(double* tab, const size_t SIZE, kierunek kier) = 0;
};

class Wyszukaj : public PrzetwarzanieTablic
{
public:
	virtual void operator()(double* tab, const size_t SIZE, double szukana) = 0;
};