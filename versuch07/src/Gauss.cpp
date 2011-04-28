//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 7: Lösung eines mathematischen Anwendungsproblems
//
// Datei:  Gauss.cpp
// Inhalt: Gauss-Klasse
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
///////////////////////////////// INCLUDES ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#include "Gauss.h"
#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////
///////////////////////// Funktions-Implementierung //////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
Gauss::Gauss(int dim)
{
	x = new Vektor(dim);
}

//////////////////////////////////////////////////////////////////////////////
Gauss::~Gauss()
{
	delete x;
	delete b;
	delete A;
}

//////////////////////////////////////////////////////////////////////////////
Vektor Gauss::loese(QMatrix B, Vektor c)
{
	A = new QMatrix(B);
	b = new Vektor(c);

	stufenform();
	rueckwaertsEinsetzen();

	return *x;
}

//////////////////////////////////////////////////////////////////////////////
void Gauss::stufenform()
{
	int dim = A->getDim();

	/* Vertausche Zeilen um 0en in der Hauptdiagonale zu vermeiden */
	for (int i = 0; i < dim; i++)
	{
		if (A->get(i, i) == 0) /* 0 gefunden! */
		{
			for (int j = 0; j < dim; j++)
			{
				if (i != j && A->get(j, i) != 0)
				{
					A->vertauscheZeile(i, j);
					cout << "Zeile " << i + 1 << " und " << j + 1
							<< " vertauscht!" << endl;
					break;
				}
			}
		}
	}

	for (int k = 0; k < dim; k++)
	{
		for (int l = k + 1; l < dim; l++)
		{
			double quot = A->get(l, k) / A->get(k, k);

			b->set(l, b->get(l) - b->get(k) * quot);

			for (int m = 0; m < dim; m++)
			{
				A->set(l, m, A->get(l, m) - A->get(k, m) * quot);
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////
void Gauss::rueckwaertsEinsetzen()
{
	int dim = A->getDim();

	for (int i = dim - 1; i >= 0; i--)
	{
		double xi = b->get(i);

		for (int k = i + 1; k < dim; k++)
		{
			xi -= A->get(i, k) * x->get(k);
		}

		x->set(i, xi / A->get(i, i));
	}
}
