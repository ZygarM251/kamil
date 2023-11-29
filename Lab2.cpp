
#pragma once
#include "Wybor.h"

using namespace std;

/*
* Uwaga: Zadania kod rozwiazania zaania umieszczaæ pomiêdzy #ifdef a #endif.
*/

#ifdef Zad_2_1


	
int main()
{
	Testy::wykonajtesty();

	Koder maszyna("1234567890");
	char wiadomosc[] = "Tajny Komunikat";
	int dlugosc = strlen(wiadomosc);
	cout << "Wiadomosc: " << wiadomosc << endl;
	maszyna.szyfruj(wiadomosc, dlugosc);
	cout << "Szyfrogram: " << wiadomosc << endl;
	maszyna.deszyfruj(wiadomosc, dlugosc);
	cout << "Wiadomosc: " << wiadomosc << endl;
}

#endif

#ifdef Zad_2_2

int main()
{
	//Brak zadania
}

#endif

#ifdef Zad_2_3

int main()
{
	//brak zadania
}

#endif