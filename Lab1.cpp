#pragma once
#include "Wybor.h"

/*
* Uwaga: Zadania kod rozwiazania zaania umieszczać pomiędzy #ifdef a #endif. 
*/


#ifdef Zad_1_1

int main()
{
    Testy::WykonajTesty();
}

#endif

#ifdef Zad_1_2

int main()
{
	//brak zadania
}

#endif

#ifdef Zad_1_3


void main(void)
{
	constexpr size_t SIZE = 10;
	srand(time(0));
	double tablica[SIZE];
	for (int i = 0; i < SIZE; i++)
		tablica[i] = rand() % 100;
	wypisz(tablica, SIZE, ';');
	cout << stopienUprzadkowania(tablica, SIZE, kierunek::rosnaco) << endl;
	sortuj(tablica, SIZE, kierunek::rosnaco);
	wypisz(tablica, SIZE, ';');
	cout << stopienUprzadkowania(tablica, SIZE, kierunek::rosnaco) << endl;
	skrambluj(tablica, SIZE);
	wypisz(tablica, SIZE, ';');
	cout << stopienUprzadkowania(tablica, SIZE, kierunek::rosnaco) << endl;
	sortuj(tablica, SIZE, kierunek::malejaco);
	wypisz(tablica, SIZE, ';');
	cout << stopienUprzadkowania(tablica, SIZE, kierunek::rosnaco) << endl;
}

#endif