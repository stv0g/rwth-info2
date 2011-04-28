//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 7: L�sung eines mathematischen Anwendungsproblems
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>

#include "QMatrix.h"
#include "Vektor.h"
#include "LR.h"
#include "Gauss.h"
#include "Cramer.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////////
void Eingabe(QMatrix& A, int n);
void Eingabe(Vektor& b, int n);

/*
 Die Benennung der Variablen entspricht, in diesem Versuch,
 den mathematischen Bezeichnungen im Script.
 Matrizen haben einen Großbuchstaben und
 Vektoren einen Kleinbuchstaben.
 */

//////////////////////////////////////////////////////////////////////////////
int main()
{
	int dim = 3;
	QMatrix A(dim);
	Vektor b(dim);
	Vektor x(dim);

	char eingabe;
	cout << "Wollen Sie selbst ein LGS angeben (j/n)? ";
	cin >> eingabe;
	if (eingabe == 'j')
	{
		cout << "Wieviele Gleichungen/Unbekannte hat ihr LGS?: ";
		cin >> dim;
		Eingabe(A, dim);
		Eingabe(b, dim);
	}
	else
	{
		/* Beispiel Daten. Ergebnis (4, -2, -1) */
		A.set(0, 0, 1);
		A.set(0, 1, 2);
		A.set(0, 2, 2);
		A.set(1, 0, 2);
		A.set(1, 1, 3);
		A.set(1, 2, 1);
		A.set(2, 0, 3);
		A.set(2, 1, 4);
		A.set(2, 2, 1);

		b.set(0, -2);
		b.set(1, 1);
		b.set(2, 3);

		/*A.set(0, 0, 3);
		 A.set(0, 1, 2);
		 A.set(0, 2, 1);
		 A.set(1, 0, 6);
		 A.set(1, 1, 6);
		 A.set(1, 2, 3);
		 A.set(2, 0, 9);
		 A.set(2, 1, 10);
		 A.set(2, 2, 6);

		 b.set(0, 1);
		 b.set(1, 1);
		 b.set(2, 1);*/
	}

	cout << endl << "A = " << endl << A;
	cout << "b = " << endl << b;

	if (A.determinante() == 0)
	{
		cerr << "Fehler: Das LGS besitzt keine eindeutige Lösung (det(A) = 0)!"
				<< endl;
		exit(-1);
	}

	cout << "Wollen Sie weitere Eigenschaften der Koeffizientenmatrix berechnen (j/n)? ";
	cin >> eingabe;
	if (eingabe == 'j')
	{
		cout << "Dim(A) = " << A.getDim() << endl;
		cout << "Det(A) = " << A.determinante() << endl;
		cout << "Adj(A) = " << endl << A.adjunkte() << endl;
		cout << "A^-1 = " << endl << A.inverse() << endl;
		cout << "A^T = " << endl << A.transponiere() << endl;
	}

	Cramer solver1(dim);
	LR solver2(dim);
	Gauss solver3(dim);

	cout << "x_cramer =" << endl << solver1.loese(A, b);
	cout << "x_lr =" << endl << solver2.loese(A, b);
	cout << "x_gauss =" << endl << solver3.loese(A, b);

	return 0;
}

//////////////////////////////////////////////////////////////////////////////
void Eingabe(QMatrix& A, int n)
{
	double zahl;
	cout << "Bitte geben sie die Matrix(" << n << " Zeilen/Spalten) ein..."
			<< endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a" << (i + 1) << (j + 1) << ": ";
			cin >> zahl;
			A.set(i, j, zahl);
		}
		cout << endl;
	}
}

//////////////////////////////////////////////////////////////////////////////
void Eingabe(Vektor& b, int n)
{
	double zahl;
	cout << "Bitte geben sie den Vektor b (" << n << " Eintraege) ein..."
			<< endl;
	for (int i = 0; i < n; i++)
	{
		cout << "b" << (i + 1) << ": ";
		cin >> zahl;
		b.set(i, zahl);
	}

}
