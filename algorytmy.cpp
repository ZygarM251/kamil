#include "algorytmy.h"
#ifdef Zad1_1
void skrambluj(double* tab, const size_t SIZE)
{
	if (tab != nullptr && SIZE > 1)
	{
		int n = SIZE - 1;
		while (n > 1)
		{
			size_t idx = rand() % (n + 1);
			swap(tab[idx], tab[n--]);
		}
	}
}

void sortuj(double* tab, const size_t SIZE, kierunek kier)
{
	if (tab != nullptr && SIZE > 1)
	{
		if (kier == kierunek::rosnaco)
		{
			for (int i = 0; i < SIZE - 1; i++)
				for (int j = i + 1; j < SIZE; j++)
					if (tab[i] > tab[j])
						swap(tab[i], tab[j]);
		}
		else
			for (int i = 0; i < SIZE - 1; i++)
				for (int j = i + 1; j < SIZE; j++)
					if (tab[i] < tab[j])
						swap(tab[i], tab[j]);
	}
}

int wyszukaj(double* tab, const size_t SIZE, double szukana)
{
	if (tab != nullptr && SIZE > 0)
	{
		for (int i = 0; i < SIZE; i++)
			if (tab[i] == szukana)
				return i;
	}
}

double stopienUprzadkowania(double* tab, const size_t SIZE, kierunek kier)
{
	if (tab != nullptr && SIZE > 1)
	{
		size_t liczbaPoprawnych = 0;
		if (kier == kierunek::rosnaco)
		{
			for (int i = 0; i < SIZE; i++)
			{
				for (int j = 0; j < i; j++)
					if (tab[j] <= tab[i]) liczbaPoprawnych++;
				for (int j = i + 1; j < SIZE; j++)
					if (tab[j] >= tab[i]) liczbaPoprawnych++;
			}
		}
		else
		{
			for (int i = 0; i < SIZE; i++)
			{
				for (int j = 0; j < i; j++)
					if (tab[j] >= tab[i]) liczbaPoprawnych++;
				for (int j = i + 1; j < SIZE; j++)
					if (tab[j] <= tab[i]) liczbaPoprawnych++;
			}
		}
		return 1.0 * liczbaPoprawnych / (SIZE * (SIZE - 1));
	}
	else return -1.0;
}

void wypisz(double* tab, const size_t SIZE, char sep)
{
	cout << fixed << setprecision(2);
	if (tab != nullptr && SIZE > 1)
	{
		cout << "[ ";
		for (int i = 0; i < SIZE - 1; i++)
			cout << tab[i] << sep << " ";
		cout << tab[SIZE - 1] << " ]\n";
	}
	else cout << "[]\n";
}



void Sortuj::operator()(double* tab, const size_t SIZE, kierunek kier) {

	if (tab != nullptr && SIZE > 1)
	{
		if (kier == kierunek::rosnaco)
		{
			for (int i = 0; i < SIZE - 1; i++)
				for (int j = i + 1; j < SIZE; j++)
					if (tab[i] > tab[j])
						swap(tab[i], tab[j]);
		}
		else
			for (int i = 0; i < SIZE - 1; i++)
				for (int j = i + 1; j < SIZE; j++)
					if (tab[i] < tab[j])
						swap(tab[i], tab[j]);
	}

}

int Wyszukaj::operator()(double* tab, const size_t SIZE, double szukana) {

	if (tab != nullptr && SIZE > 0)
	{
		for (int i = 0; i < SIZE; i++)
			if (tab[i] == szukana)
				return i;
	}

}

#endif



