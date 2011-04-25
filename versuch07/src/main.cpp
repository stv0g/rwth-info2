//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 7: Lösung eines mathematischen Anwendungsproblems
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "QMatrix.h"
#include "Vektor.h"
#include "LR.h"
//#include "Gauss.h"
//#include "Cramer.h"
#include <iostream>

using namespace std;

//////////////////////////////////////////////////////////////////////////////
void Eingabe(QMatrix& A, int n);
void Eingabe(Vektor& b, int n);

//////////////////////////////////////////////////////////////////////////////

/*
Die Benennung der Variablen entspricht, in diesem Versuch,
den mathematischen Bezeichnungen im Script.
Matrizen haben einen Großbuchstaben und
Vektoren einen Kleinbuchstaben.
*/

//////////////////////////////////////////////////////////////////////////////

int main()
{
	cout << "Wieviele Gleichungen/Unbekannte hat ihr LGS.." ;
	int dim;
	cin >> dim;
	QMatrix A(dim);
	Vektor b(dim);
	Vektor x(dim);
	Eingabe(A,dim);
	Eingabe(b,dim);
	cout << A;
	
	LR system1(dim);
	x = system1.loese(A,b);
	cout << x;
	
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
void Eingabe(QMatrix& A, int n)
{
	double zahl;
	cout << "Bitte geben sie die Matrix(" << n << " Zeilen/Spalten) ein..." << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a" << (i+1) << (j+1) << ": ";
			cin >> zahl;
			A.set(i,j, zahl);
		}
		cout << endl;
	}
}

//////////////////////////////////////////////////////////////////////////////
void Eingabe(Vektor& b, int n)
{
	double zahl;
	cout << "Bitte geben sie den Vektor b (" << n << " Eintraege) ein..." << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "b" << (i+1) << ": ";
		cin >> zahl;
		b.set(i, zahl);
	}
	
}
