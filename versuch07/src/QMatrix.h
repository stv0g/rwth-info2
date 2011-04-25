//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 7: L�sung eines mathematischen Anwendungsproblems
//
// Datei:  QMatrix.h
// Inhalt: Matrix-Klasse zum speichern von quadratischen Matrizen variabler Gr��e
//////////////////////////////////////////////////////////////////////////////

#ifndef QMATRIX_H_
#define QMATRIX_H_

//////////////////////////////////////////////////////////////////////////////
///////////////////////////////// INCLUDES ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
using namespace std;

//////////////////////////////////////////////////////////////////////////////
///////////////////////// CLASS DECLARATION //////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

class QMatrix
{
public:
	// Konstruktor, �bernimmt die Dimension
	QMatrix(int n);
	//Kopierkonstruktor
	QMatrix(const QMatrix&);
	// Zuweisungsoperator
	QMatrix& operator=(const QMatrix& B);
	//Destruktor
	~QMatrix();
	
	// Set- und Getmethoden zum Bearbeiten und Lesen der Inhalte des Vektors
	double get(const int i, const int j) const;
	void set(const int i, const int j, const double zahl);
	int getDim() const;
	
	// Hilfsmethoden f�r die Cramersche Regel
	void transponiere();
	QMatrix untermatrix(int i, int j);
	
private:
	double* A; // Matrix
	int dim;
};

ostream& operator<<(ostream& Stream, const QMatrix& A);

#endif /*QMATRIX_H_*/
