//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 7: L�sung eines mathematischen Anwendungsproblems
//
// Datei:  LR.cpp
// Inhalt: LR-Klasse
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
///////////////////////////////// INCLUDES ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#include "LR.h"
#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////
///////////////////////// Funktions-Implementierung //////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
LR::LR(int n)
{
	x = new Vektor(n);
	y = new Vektor(n);
	L = new QMatrix(n);
	R = new QMatrix(n);
}

LR::~LR()
{
	delete x;
	delete y;
	delete L;
	delete R;
}

//////////////////////////////////////////////////////////////////////////////
Vektor LR::loese(QMatrix A, Vektor b)
{
	zerlege(A);
	erzeugeLundR(A);
	vorwaertsEinsetzen(b);
	rueckwaertsEinsetzen();

	return *x;
}

//////////////////////////////////////////////////////////////////////////////
void LR::zerlege(QMatrix& A)
{
	// TODO Der PseudoCode funktioniert nur, wenn nicht durch 0 dividiert wird.
	for (int i = 1; i <= A.getDim(); i++)
	{
		for (int j = i + 1; j <= A.getDim(); j++)
		{
			A.set(j, i, A.get(j, i) / A.get(i, i));

			for (int k = i + 1; k <= A.getDim(); k++)
			{
				A.set(j, k, A.get(j, k) - (A.get(j, i) * A.get(i, k)));
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////
// Schreibe aus der Matrix A in die Matrizen L und R
void LR::erzeugeLundR(QMatrix& A)
{
	for (int i = 1; i <= A.getDim(); i++)
	{
		for (int j = 1; j <= A.getDim(); j++)
		{
			if (i == j) /* Diagonale */
			{
				L->set(i, j, 1.0);
			}

			R->set(i, j, A.get(i, j));
		}
	}

}

//////////////////////////////////////////////////////////////////////////////
void LR::vorwaertsEinsetzen(Vektor& b)
{

}

//////////////////////////////////////////////////////////////////////////////
void LR::rueckwaertsEinsetzen()
{

}

