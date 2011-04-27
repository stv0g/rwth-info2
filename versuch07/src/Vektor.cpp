//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 7: L�sung eines mathematischen Anwendungsproblems
//
// Datei:  Vektor.cpp
// Inhalt: Vektor-Klasse zum speichern von Vektoren variabler Gr��e
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
///////////////////////////////// INCLUDES ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

//////////////////////////////////////////////////////////////////////////////
///////////////////////// Funktions-Implementierung //////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// Konstruktor erstellt array mit n Inhalten
Vektor::Vektor(int n)
{
	dim = n;
	v = new double[n];
	for (int i = 0; i < dim; i++)
	{
		v[i] = 0.0;
	}
}

//////////////////////////////////////////////////////////////////////////////
// Kopierkonstruktor
Vektor::Vektor(const Vektor& alterVektor)
{
	dim = alterVektor.dim;
	v = new double[dim];
	for (int i = 0; i < dim; i++)
	{
		v[i] = alterVektor.get(i);
	}
}

//////////////////////////////////////////////////////////////////////////////
//Zuweisungsoperator
Vektor& Vektor::operator=(const Vektor& b)
{
	this->dim = b.getDim();
	for (int i = 0; i < dim; i++)
	{
		this->v[i] = b.get(i);
	}
	return *this;
}

//////////////////////////////////////////////////////////////////////////////
// Destruktor
Vektor::~Vektor()
{
	delete[] v;
}

//////////////////////////////////////////////////////////////////////////////
// Getmethode f�r den i-ten Eintrag
double Vektor::get(const int i) const
{
	return v[i];
}

//////////////////////////////////////////////////////////////////////////////
// Schreibt Zahl an den i-ten Eintrag 
void Vektor::set(const int i, const double zahl)
{
	v[i] = zahl;
}

//////////////////////////////////////////////////////////////////////////////
int Vektor::getDim() const
{
	return dim;
}

//////////////////////////////////////////////////////////////////////////////
// Ausgabeoperator, au�erhalb der Klasse implementiert
ostream& operator<<(ostream& Stream, const Vektor& v)
{
	for (int i = 0; i < v.getDim(); i++)
	{
		Stream << setprecision(3) << v.get(i) << endl;
	}
	Stream << endl;
	return Stream;
}
