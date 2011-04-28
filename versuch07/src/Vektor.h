//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 7: L�sung eines mathematischen Anwendungsproblems
//
// Datei:  Vektor.h
// Inhalt: Vektor-Klasse zum speichern von Vektoren variabler Größe
//////////////////////////////////////////////////////////////////////////////

#ifndef VEKTOR_H_
#define VEKTOR_H_

//////////////////////////////////////////////////////////////////////////////
///////////////////////////////// INCLUDES ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
using namespace std;

//////////////////////////////////////////////////////////////////////////////
///////////////////////// CLASS DECLARATION //////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

class Vektor
{
public:
	// Konstruktor, �bernimmt die Dimension
	Vektor(int n);
	//Kopierkonstruktor
	Vektor(const Vektor&);
	//Zuweisungsoperator
	Vektor& operator=(const Vektor& b);
	//Destruktor
	~Vektor();
	
	// Set- und Getmethoden zum Bearbeiten und Lesen der Inhalte des Vektors
	double get(const int i) const;
	void set(const int i, const double Zahl);
	int getDim() const;
	
private:
	double* v; // Vektor
	int dim;
};

ostream& operator<<(ostream& Stream, const Vektor& v);

#endif /*VEKTOR_H_*/
