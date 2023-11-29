# pragma once
#include <cmath>
#include <cstring>
#include <iostream>
#include "Lab2.h"

int Koder::licznik = 0;
Koder** Koder::m_tabWsk = new Koder*[10];
int Koder::m_rozmiarTabWsk = 10;

void Koder::alokuj(int rozmiar) {
	if (rozmiar > 0) {
		m_klucz = new char[rozmiar];
		m_rozmiar = rozmiar;
	}
}
 
void Koder::zwolnij() {
	if (m_klucz != nullptr) {
		delete[] m_klucz;
		m_klucz = nullptr;
	}
}

bool Koder::jestOK() {
	if (m_klucz == nullptr || m_rozmiar <= 0) {
		cerr << "NIE JEST OK" << endl;
		throw std::invalid_argument("");
	}
	return true;
}

Koder::Koder(const char* i_klucz) {
	const char* klucz = "klucz";
	if (i_klucz != "" && i_klucz != nullptr) {
		klucz = i_klucz;
	}
	int rozmiar = sizeof(klucz);
	alokuj(rozmiar);
	for (int i = 0; i < rozmiar; i++) { m_klucz[i] = klucz[i]; }
	numerWtablicy = licznik;
	licznikIncrement();
	WpiszWTablice(this);
}

Koder::~Koder() {
	licznikDecrement();
	UsunZTablicy(this);
	zwolnij();
}

Koder::Koder(const Koder& org) :m_rozmiar(org.m_rozmiar) {
	if (org.m_klucz != nullptr) alokuj(org.m_rozmiar);
	for (int i = 0; i < org.m_rozmiar; i++)
		this->m_klucz[i] = org.m_klucz[i];
	numerWtablicy = licznik;
	licznikIncrement();
	WpiszWTablice(this);
}


Koder& Koder::operator=(const Koder& org) {

	if (this != &org) {

		bool roznyrozmiar = this->m_rozmiar != org.m_rozmiar;
		if (this->m_klucz != nullptr && roznyrozmiar) {
			zwolnij();
		}
		if (org.m_klucz != nullptr) {
			if (roznyrozmiar) alokuj(org.m_rozmiar);
			for (int i = 0; i < org.m_rozmiar; i++) { m_klucz[i] = org.m_klucz[i]; }
		}
		this->m_rozmiar = org.m_rozmiar;

	}
	return *this;
}

Koder::Koder(Koder&& org) : m_rozmiar(org.m_rozmiar) {

	this->m_klucz = org.m_klucz;
	org.m_klucz = nullptr;
	numerWtablicy = licznik;
	licznikIncrement();
	WpiszWTablice(this);
}

Koder& Koder::operator=(Koder&& org) {
	if (this != &org) {
		if (this->m_klucz != nullptr) zwolnij();
		this->m_klucz = org.m_klucz;
		this->m_rozmiar = org.m_rozmiar;
		org.m_klucz = nullptr;
	}
	return *this;
}

void Koder::setKlucz(const char* i_klucz, int rozmiar)
{
	if (i_klucz != nullptr && strcmp(i_klucz, m_klucz) && strcmp(i_klucz, "")) {

		if (rozmiar != m_rozmiar) {
			zwolnij();
			alokuj(rozmiar);
		}
		m_rozmiar = rozmiar;
		strncpy(m_klucz, i_klucz, m_rozmiar);
	}
}

void Koder::WpiszWTablice(Koder* Wsk)
{
	if (licznik >= m_rozmiarTabWsk) {
		Koder** temp = new Koder * [10 * m_rozmiarTabWsk];
		for (int i = 0; i < m_rozmiarTabWsk; i++) temp[i] = m_tabWsk[i];
		delete[] Koder::m_tabWsk;
		Koder::m_tabWsk = temp;
	}
	m_tabWsk[licznik - 1] = Wsk;
}

void Koder::UsunZTablicy(Koder* wsk) {
	m_tabWsk[wsk->numerWtablicy] = nullptr;
}


void Koder::szyfruj(char* i_info, size_t i_liczZnak) const
{
	if (i_info != nullptr && i_liczZnak > 0)
		for (size_t i = 0; i < i_liczZnak; i++)
			i_info[i] ^= m_klucz[i % m_rozmiar];
}

void Koder::deszyfruj(char* i_info, size_t i_liczZnak) const
{
	szyfruj(i_info, i_liczZnak);
}

int Koder::sprawdzDuplikaty() {
	int liczduplikatow = 0;
	for (int i = 0; i < licznik; i++) {
		if (!strcpy(Koder::m_tabWsk[i]->m_klucz, this->m_klucz)) liczduplikatow++;
	}
	return liczduplikatow;
}









char* Testy::sprawdzKod(Koder& koder) {
	return koder.m_klucz;
}

void Testy::testKopiowania() {
	Koder koderA("kodA"), koderB("kodB");
	koderB = koderA;
	cerr << "TestKopiowania:\t";
	if (!(strcmp(koderB.m_klucz, "kodA"))) {
		cerr << "OK" << endl;
	}else {
		cerr << "FAIL" << endl;
	}
}

void Testy::testPrzenoszenia() {
	Koder koderA("kodA"), koderB("kodB");
	koderB = std::move(koderA);
	cerr << "TestPrzenoszenia:\t";
	if (!(strcmp(koderB.m_klucz, "kodA")) && koderA.m_klucz == nullptr) {
		cerr << "OK" << endl;
	}else {
		cerr << "FAIL" << endl;
	}
}

void Testy::testSetKlucz() {
	Koder koderA("kodA");
	char kod[] = "kodB";
	koderA.setKlucz(kod, sizeof(kod));
	cerr << "TestSetKlucz:\t";
	if (!(strcmp(koderA.m_klucz, "kodB"))) {
		cerr << "OK" << endl;
	}else {
		cerr << "FAIL" << endl;
	}
}

void Testy::testSetKluczZmiana() {
	Koder koderA("kodA"), koderB("kodB");
	koderA = koderB;
	char kod[] = "kodC";
	koderA.setKlucz(kod, sizeof(kod));
	cerr << "TestSetKluczZmiana:\t";
	if (!(strcmp(koderB.m_klucz, "kodB"))) {
		cerr << "OK" << endl;
	}else {
		cerr << "FAIL" << endl;
	}
}

void Testy::testLicznikKopiowanie() {
	Koder koderA("kodA");
	Koder koderB = koderA;
	cerr << "TestLicznikKopiowanie:\t";
	if (Koder::getLicznik() == 2) {
		cerr << "OK" << endl;
	}else {
		cerr << "FAIL" << endl;
	}
}

void Testy::testLicznikPrzenoszenie() {
	Koder koderA("kodA");
	Koder koderB = std::move(koderA);
	cerr << "TestLicznikPrzenoszenie:\t";
	if (Koder::getLicznik() == 2) {
		cerr << "OK" << endl;
	}else {
		cerr << "FAIL" << endl;
	}
}

void Testy::testLicznikUsuwanie() {

	{	Koder koderA("kodA"); }

	cerr << "TestLicznikUsuwanie:\t";
	if (Koder::getLicznik() == 0) {
		cerr << "OK" << endl;
	}else {
		cerr << "FAIL" << endl;
	}
}

void Testy::testTabWskDopis() {
	Koder koderA("kodA");
	cerr << "testTabWskDopis:\t";
	if (!strcmp(Koder::m_tabWsk[0]->m_klucz, "kodA")) {
		cerr << "OK" << endl;
	} else{
		cerr << "FAIL" << endl;
	}


}

void Testy::testTabWskusun() {
	{
		Koder koderA("kodA");
	}
	
	cerr << "testTabWskusun:\t";
	if (Koder::m_tabWsk[0] == nullptr) {
		cerr << "OK" << endl;
	}
	else {
		cerr << "FAIL" << endl;
	}
}

void Testy::testDuplikaty() {
	//Koder koderA("kodA"), koderA("kodA"), koderA("kodA"), koderA("kodA"), koderA("kodA");

}

void Testy::wykonajtesty() {
	testKopiowania();
	testPrzenoszenia();
	testSetKlucz();
	testSetKluczZmiana();
	testLicznikKopiowanie();
	testLicznikPrzenoszenie();
	testLicznikUsuwanie();
	testTabWskDopis();
	testTabWskusun();
}