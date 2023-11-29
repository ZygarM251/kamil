#pragma once
#include "Lab1.h"
#ifdef Zad_1_1
void Punkt::toPunkt(const Wektor& wektor, int n) {
	m_x = wektor.getDX() * n;
	m_y = wektor.getDY() * n;
}

void Punkt::setXY(double x, double y)
{
	m_x = x;
	m_y = y;
}

Wektor Punkt::toWektor(const Punkt* a, const Punkt* b) {
	double x = b->m_x - a->m_x;
	double y = b->m_y - a->m_y;
	double dlugosc = sqrt(x * x + y * y);
	x = x / dlugosc;
	y = y / dlugosc;
	Wektor result(x, y);
	return result;
}

Punkt Punkt::operator+ (const Wektor& rhs) {
	double x = m_x + rhs.getDX();
	double y = m_y + rhs.getDY();
	Punkt result(x, y);
	return result;
}

void Wektor::setDXY(double dx, double dy)
{
	m_dx = dx;
	m_dy = dy;
}

Punkt Wektor::toPunkt(int n) {
	Punkt result(n * m_dx, n * m_dy);
	return result;
}

void Kwadrat::setRogi(Punkt ld, Punkt pg)
{
	m_lewy_dolny = ld;
	m_prawy_gorny = pg;
}

Kwadrat::Kwadrat(Punkt punkt) :m_lewy_dolny(0, 0), m_prawy_gorny(0, 0) {
	double x = punkt.getX();
	double y = punkt.getY();
	if (x * y < 0) {
		swap(x, y);
	}
	x = abs(x);
	y = abs(y);
	m_prawy_gorny.setXY(x, y);
	m_lewy_dolny.setXY(-x, -y);

}

bool Kwadrat::operator  == (const Kwadrat& rhs) {

	if (this != &rhs) {
		double roznicaX = m_lewy_dolny.getX() - m_prawy_gorny.getX();
		double roznicaY = m_lewy_dolny.getY() - m_prawy_gorny.getY();
		double przekA = sqrt(roznicaX * roznicaX + roznicaY * roznicaY);
		roznicaX = rhs.getLewyDolny().getX() - rhs.getPrawyGorny().getX();
		roznicaY = rhs.getPrawyGorny().getX() - rhs.getLewyDolny().getX();
		double przekB = sqrt(roznicaX * roznicaX + roznicaY * roznicaY);
		if (przekA != przekB) { return false; }
	}
	return true;
}

Kwadrat::operator Wektor() {
	double x = m_prawy_gorny.getX() - m_lewy_dolny.getX();
	double y = m_prawy_gorny.getY() - m_lewy_dolny.getY();
	Wektor result(x, y);
	return result;
}

void Testy::TestPunktDoKwadrat() {
	Punkt punktA(-2, 3), punktB(0, 4.3);
	Kwadrat Kw1(punktA), Kw2(punktB);
	bool test1LD = ((Kw1.getLewyDolny().getX() == -3) && (Kw1.getLewyDolny().getY() == -2));
	bool test1PG = ((Kw1.getPrawyGorny().getX() == 3) && (Kw1.getPrawyGorny().getY() == 2));
	bool test2LD = ((Kw2.getLewyDolny().getX() == 0) && (Kw2.getLewyDolny().getY() == -4.3));
	bool test2PG = ((Kw2.getPrawyGorny().getX() == 0) && (Kw2.getPrawyGorny().getY() == 4.3));
	raport("TestPunktDoKwadrat", (test1LD && test1PG && test2LD && test2PG));
}
void Testy::TestWektorDoPunkt() {
	Wektor WekA(2, 3), WekB(-1, 2);
	Punkt PktA(0, 0), PktB(0, 0);
	PktA = WekA.toPunkt(1);
	PktB = WekB.toPunkt(2);
	bool testA = ((PktA.getX() == 2) && (PktA.getY() == 3));
	bool testB = ((PktB.getX() == -2) && (PktB.getY() == 4));
	raport("TestPunktDoKwadrat", (testA && testB));
}
void Testy::TestOpPlusPunktWektor() {
	Punkt pktA(-2, -2), pktB(2, 3);
	Wektor WekA(1, 2), WekB(2.5, 3);
	pktA = pktA + WekA;
	pktB = pktB + WekB;
	bool testA = (pktA.getX() == -1 && pktA.getY() == 0);
	bool testB = (pktB.getX() == 4.5 && pktB.getY() == 6);
	raport("TestOpPlusPunktWektor", (testA && testB));
}
void Testy::TestOpPorownaniaKwadrat() {
	Punkt pktA(-2, -2), pktB(2, 2), pktC(3, 3);
	Kwadrat KwA(pktA, pktB), KwB(pktA, pktC);
	bool testA = (KwA == KwA);
	bool testB = (KwA == KwB);
	raport("TestOpPorownaniaKwadrat", (testA && !testB));
}
 void Testy::TestKwDoWek() {
	Punkt pktA(-2, -2), pktB(2, 1), pktC(3, 3);
	Kwadrat KwA(pktA, pktB), KwB(pktA, pktC);
	Wektor WekA(0, 0), WekB(0, 0);
	WekA = static_cast<Wektor>(KwA);
	WekB = static_cast<Wektor>(KwB);
	bool testA = (WekA.getDX() == 4 && WekA.getDY() == 3);
	bool testB = (WekB.getDX() == 5 && WekB.getDY() == 5);
	raport("TestKwDoWek", (testA && testB));
}
void Testy::TestPktDoWek() {
	Punkt pktA(-2, 2), pktB(2, 2), pktC(4, 3);
	Wektor WekA(0, 0), WekB(0, 0);
	WekA = Punkt::toWektor(&pktA, &pktB);
	WekB = Punkt::toWektor(&pktA, &pktC);
	bool testA = (WekA.getDX() == 1 && WekA.getDY() == 0);
	double e = 0.01;
	bool testB = ((WekB.getDX() > 0.9865 - e || WekB.getDX() < 0.9865 + e) && (WekA.getDY() > 0.1644 + e || WekA.getDY() < 0.1644 - e));
	raport("TestPktDoWek", (testA && testB));
}
void Testy::raport(const char* nazwa, bool czyOk) {
	cout << nazwa << ":\t";
	if (czyOk) { cout << "OK" << endl; }
	else { cout << "FAIL" << endl; }
}

void Testy::WykonajTesty() {
	TestPunktDoKwadrat();
	TestWektorDoPunkt();
	TestOpPorownaniaKwadrat();
	TestOpPlusPunktWektor();
	TestKwDoWek();
	TestPktDoWek();
}






void Paczka::setWymiary(double w, double sz, double gl) noexcept
{
	m_wymiary[0] = nieUjemna(w);
	m_wymiary[1] = nieUjemna(sz);
	m_wymiary[2] = nieUjemna(gl);
}




Paczka::Paczka(double wg, double wys, double sz, double gl, std::string adr, TypPaczki typ)
{
	setWaga(wg); setWymiary(wys, sz, gl); setAdres(adr), setTyp(typ);
}




std::vector<Paczka> tworzTabliceTestowa()
{
	std::vector<Paczka> tablica =
	{
		{ 30.0, 0.4, 0.5, 0.6, "ul. ... Katowice ...", TypPaczki::zwykla },
		{ 20.0, 0.2, 0.5, 0.6, "ul. ... Bytom ...", TypPaczki::zwykla },
		{ 15.0, 0.2, 0.5, 0.6, "ul. ... Bytom ...", TypPaczki::priorytetowa },
		{ 20.0, 0.3, 0.3, 0.2, "ul. ... Szczecin ...", TypPaczki::zwykla },
		{ 120.0, 0.8, 1.5, 1.6, "ul. ... Gdansk ...", TypPaczki::zwykla },
		{ 0.5, 0.1, 0.2, 0.2, "ul. ... Poznan ...", TypPaczki::ekspresowa },
		{ 1.5, 0.2, 0.2, 0.2, "ul. ... Katowice ...", TypPaczki::ekspresowa },
		{ 11.5, 0.5, 1.2, 1.2, "ul. ... Katowice ...", TypPaczki::priorytetowa },
		// Dopisz jeszcze przynajmnej 10 przyk³¹dowych instancji.
	};
	return tablica;
}
#endif