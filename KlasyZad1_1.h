#pragma once

#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;
class Wektor;

class Punkt
{
	double m_x = 0.0, m_y = 0.0;
public:
	void setXY(double x, double y);
	double getX() const { return m_x; }
	double getY() const { return m_y; }
	void toPunkt(const Wektor& wektor, int n);
	Punkt(double x, double y):m_x(x), m_y(y){}
	Punkt operator+ (const Wektor& rhs);
	static Wektor toWektor(const Punkt* a, const Punkt* b); //Dlaczego w punkcie? - Metoda statyczna bêdzie tu mia³a dostêp do sekcji private punktów, na których bêdziemy pracowaæ. Nie bêdzie trzeba pos³ugiwaæ siê geterami. Nie potrzebujemy nic z klasy Wektor
};
class Wektor
{
	double m_dx = 0.0, m_dy = 0.0;
public:
	void setDXY(double dx, double dy);
	double getDX() const { return m_dx; }
	double getDY() const { return m_dy; }
	double dlugosc() const { return sqrt(m_dx * m_dx + m_dy * m_dy); }
	Punkt toPunkt(int n);
	Wektor(double dx, double dy):m_dx(dx), m_dy(dy){}
};

class Kwadrat
{
	Punkt m_lewy_dolny, m_prawy_gorny;
public:
	void setRogi(Punkt ld, Punkt pg);
	Punkt getLewyDolny() const { return m_lewy_dolny; }
	Punkt getPrawyGorny() const { return m_prawy_gorny; }
	explicit Kwadrat(Punkt ld, Punkt pg):m_lewy_dolny(ld), m_prawy_gorny(pg){}
	explicit Kwadrat(Punkt punkt);
	bool operator  == (const Kwadrat& rhs);
	operator Wektor();
};


class Testy {
private:

	static void TestPunktDoKwadrat();
	static void TestWektorDoPunkt();
	static void TestOpPlusPunktWektor();
	static void TestOpPorownaniaKwadrat();
	static void TestKwDoWek();
	static void TestPktDoWek();
	static void raport(const char* nazwa, bool czyOk);
public:
	static void WykonajTesty();
};

class Kolo
{
	double m_promien = 1.0;
	Punkt m_srodek;
public:
	void setPromien(double r)
	{
		m_promien = (r > 0) ? r : 0;
	}
	void setSrodek(Punkt p)
	{
		m_srodek = p;
	}
	double getPromien() const { return m_promien; }
	Punkt getSrodek() const { return m_srodek; }
	Kolo(Punkt sr, double r)
		: m_srodek(sr), m_promien(r)
	{}
};

enum class TypPaczki
{
	zwykla,
	priorytetowa,
	ekspresowa,
};

class Paczka
{
	double m_waga;
	double m_wymiary[3];
	std::string m_adres;
	TypPaczki m_typ;
	double nieUjemna(double wart) noexcept {return (wart > 0) ? wart : 0;}
public:
	Paczka(double wg, double wys, double sz, double gl, std::string adr, TypPaczki typ);
	void setWaga(double w) noexcept{m_waga = nieUjemna(w);}
	void setWymiary(double w, double sz, double gl) noexcept;
	//Seter przenosz¹cy  (argument adr jest lokaln¹ kopi¹, wiêc mo¿emy jej treœæ przenieœæ do pola m_adres)
	void setAdres(std::string adr) noexcept {m_adres = std::move(adr);}
	void setTyp(TypPaczki typ) noexcept{m_typ = typ;}
	double getWaga() const noexcept { return m_waga; }
	double getWysokosc() const noexcept { return m_wymiary[0]; }
	double getSzerokosc() const noexcept { return m_wymiary[1]; }
	double getGlebokosc() const noexcept { return m_wymiary[2]; }
	std::string getAdres() const noexcept { return m_adres; }
	TypPaczki getTyp() const noexcept { return m_typ; }
};



