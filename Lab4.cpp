#include "Wybor.h"

using namespace std;

/*
* Uwaga: Zadania kod rozwiazania zaania umieszczaæ pomiêdzy #ifdef a #endif.
*/

#ifdef Zad_4_1



int main()
{

	CzyWiekszy CzyWiekszyInt(true), CzyWiekszyDouble(false);
	test a, b, c, d, e;
	vector<test> vecA = {a,b,c,d,e};
	
	sort(vecA.begin(), vecA.end(), CzyWiekszyInt);
		cout << "sort dla int:" << endl;
		cout << vecA << endl;
		
		sort(vecA.begin(), vecA.end(), CzyWiekszyDouble);
		cout << "sort dla double:" << endl;
		cout << vecA << endl;
}

#endif


#ifdef Zad_4_2


int main()
{
	random_device srng;
	mt19937 rng;
	rng.seed(1);

	list<int> lista = {};
	list<int>::iterator iter = lista.begin();
	uniform_int_distribution<int> uniDistInt(1, 20);
	//rng.seed(srng());

	do {
		int a = uniDistInt(rng);
		if (count(lista.begin(), lista.end(), a) < 2) {
			iter = lista.insert(iter, a);
		}
		else {
			break;
		}
	} while (true);

	cout << "lista:"<<endl<<lista << endl;

	
	lista.sort();
	//lista.unique();
	unique(lista.begin(), lista.end());
	
	cout << lista << endl;

    /*
	for (int i = 0; i < rozmiarListy; i++) {
		if (count(lista.begin(), lista.end(), *iter)>1) {
			iter = lista.erase(iter);
			rozmiarListy--;
		}
		iter++;
	}
	*/
	int rozmiarListy = lista.size();

	vector<int> Wek;
	Wek.reserve(rozmiarListy);
	iter = lista.begin();
	for (int i = 0; i < rozmiarListy; i++) {
		Wek.push_back(*iter);
		iter++;
	}
	sort(Wek.begin(), Wek.end(), [](int& a, int& b)->bool {return a > b; });
	cout <<" Wektor po posortowaniu:"<<endl << Wek << endl;
	replace_if(Wek.begin(), Wek.end(), [](int& a)->bool {return ((a & 1) == 1); }, 0);
	cout << " Wektor z zerami:" << endl << Wek << endl;
	_Erase_remove(Wek, 0);
	cout << " Wektor skrocony:" << endl << Wek << endl;
}

#endif

#ifdef Zad_4_3


tuple<vector<Paczka>, vector<int>> filtruj(vector<Paczka> wek, function()) {

	tuple<vector<Paczka>, vector<int>> a = {};
	return a;
}






int main()
{





}

#endif