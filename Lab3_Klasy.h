#pragma once
#include <iostream>

using namespace std;

template <typename typ, int size>
typ mostFrequent(typ(&data)[size], int& highestFreq)
{
	if (data != nullptr && size > 0)
	{
		highestFreq = 1;
		typ mostFreq = data[0];
		int freq = 0;
		for (int element = 0; element < size; element++)
		{
			freq = 0;
			for (int another = 0; another < size; another++)
				if (data[element] == data[another])
					freq++;
			if (freq > highestFreq)
			{
				highestFreq = freq;
				mostFreq = data[element];
			}
		}
		return mostFreq;
	}
	else throw(std::domain_error("No data!"));
}

template <typename typ>
void add(typ** adreses, int size, typ* adres)
{
	if (adreses != nullptr && size > 0)
	{
		typ** firstEmpty = nullptr;
		for (typ** adr = adreses; adr < adreses + size; adr++)
		{
			if (*adr == adres)
				throw std::domain_error("Adress already exist!");
			else if (*adr == nullptr && firstEmpty == nullptr)
				firstEmpty = adr;
		}
		if (firstEmpty != nullptr)
			*firstEmpty = adres;
	}
	else throw(std::domain_error("No data!"));
}

class Testy {
private:
	static void raport(const char* nazwa, bool wynik);
	static void testMostFrequentDouble();
	static void testMostFrequentChar();
	static void testAddInt();
public:
	static void wykonajTesty();
};