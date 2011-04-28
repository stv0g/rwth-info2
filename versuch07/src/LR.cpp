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
	int dim = A.getDim();

	/* Vertausche Zeilen um 0en in der Hauptdiagonale zu vermeiden */
	for (int i = 0; i < dim; i++)
	{
		if (A.get(i, i) == 0) /* 0 gefunden! */
		{
			for (int j = 0; j < dim; j++)
			{
				if (i != j && A.get(j, i) != 0) {
					A.vertauscheZeile(i, j);
					cout << "Zeile " << i+1 << " und " << j+1 << " vertauscht!" << endl;
					break;
				}
			}
		}
	}

	for (int i = 0; i < dim; i++)
	{
		for (int j = i + 1; j < dim; j++)
		{
			A.set(j, i, A.get(j, i) / A.get(i, i));

			for (int k = i + 1; k < dim; k++)
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
	int dim = A.getDim();

	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (i == j) /* Diagonale */
			{
				L->set(i, j, 1);
				R->set(i, j, A.get(i, j));
			}
			else if (j > i) /* obere Dreiecksmatrix */
			{
				R->set(i, j, A.get(i, j));
			}
			else if (j < i) /* untere Dreiecksmatrix */
			{
				L->set(i, j, A.get(i, j));
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////
void LR::vorwaertsEinsetzen(Vektor& b)
{
	int dim = L->getDim();

	for (int i = 0; i < dim; i++)
	{
		double yi = b.get(i);

		for (int k = 0; k < i; k++)
		{
			yi -= L->get(i, k) * y->get(k);
		}

		y->set(i, yi);
	}
}

//////////////////////////////////////////////////////////////////////////////
void LR::rueckwaertsEinsetzen()
{
	int dim = R->getDim();

	for (int i = dim-1; i >= 0; i--)
	{
		double xi = y->get(i);

		for (int k = i + 1; k < dim; k++)
		{
			xi -= R->get(i, k) * x->get(k);
		}

		x->set(i, xi / R->get(i, i));
	}
}

