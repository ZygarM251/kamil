#pragma once
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

class Testy;


class Koder{
	int m_rozmiar;
	char* m_klucz = nullptr;
	static int m_rozmiarTabWsk;
	static int licznik;
	static Koder** m_tabWsk;
	int numerWtablicy = 0;
	friend Testy;

	void alokuj(int rozmiar);
	void zwolnij();
	bool jestOK();
	Koder() = delete;
	static void licznikIncrement() {licznik++;}
	static void licznikDecrement() {licznik--;}
public:
	Koder(const char* i_klucz);
	~Koder();
	Koder(const Koder& org);
	Koder& operator=(const Koder& org);
	Koder(Koder&& org);
	Koder& operator=(Koder&& org);
	static void WpiszWTablice(Koder* wsk);
	static void UsunZTablicy(Koder* wsk);
	void setKlucz(const char* i_klucz, int rozmiar);
	void szyfruj(char* i_info, size_t i_liczZnak) const;
	void deszyfruj(char* i_info, size_t i_liczZnak) const;
	static int getLicznik() {return licznik;}
	int sprawdzDuplikaty();
};

class Testy {
private:
	char* sprawdzKod(Koder& koder);
	static void testKopiowania();
	static void testPrzenoszenia();
	static void testSetKlucz();
	static void testSetKluczZmiana();
	static void testLicznikKopiowanie();
	static void testLicznikPrzenoszenie();
	static void testLicznikUsuwanie();
	static void testTabWskDopis();
	static void testTabWskusun();
	static void testDuplikaty();
public:
	static void wykonajtesty();
};




