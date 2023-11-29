//#include "Wybor.h"
#pragma once
#include "Wybor.h"
using namespace std;

/*
* Uwaga: Zadania kod rozwiazania zaania umieszczaæ pomiêdzy #ifdef a #endif.
*/

#ifdef Zad_3_1


int main()
{
		// dla mostFrequent:
		int tabInt[] = { 1,2,3,4,4,5,6,8,8,8,1,4,1,2,5,8,5,5,1 };
		int wynik = 0;
		cout << mostFrequent<int, (sizeof(tabInt) / sizeof(int))>(tabInt, wynik);
		cout << " (" << wynik << ")" << endl;

		// dla add:
		double zm1 = 1.0, zm2 = 2.0, zm3 = 3.0;
		cout << "Adresy zmiennych:\nzm1: " << &zm1
			<< " zm2: " << &zm2 << " zm3: " << &zm3 << endl;
		double* tabAdr[10] = { &zm1, &zm2 };
		cout << "Adresy w tab:\n";
		for (int i = 0; i < 10; i++)
			cout << "tabAdr[" << i << "]: " << tabAdr[i] << endl;

		try { add(tabAdr, 10, &zm3); }
		catch (std::exception e) { cout << "zm3(1): " << e.what() << endl; }
		try { add(tabAdr, 10, &zm1); }
		catch (std::exception e) { cout << "zm1(1): " << e.what() << endl; }
		try { add(tabAdr, 10, &zm3); }
		catch (std::exception e) { cout << "zm3(2): " << e.what() << endl; }

		for (int i = 0; i < 10; i++)
			cout << "tabAdr[" << i << "]: " << tabAdr[i] << endl;

		Testy::wykonajTesty();
}


#endif

#ifdef Zad_3_2

int main()
{

}

#endif

#ifdef Zad_3_3

int main()
{

}

#endif