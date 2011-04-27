//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 7: Lösung eines mathematischen Anwendungsproblems
//
// Datei:  QMatrix.cpp
// Inhalt: Matrix-Klasse zum speichern von quadratischen Matrizen variabler Größe
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
///////////////////////////////// INCLUDES ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#include "QMatrix.h"

#include <cmath>

//////////////////////////////////////////////////////////////////////////////
///////////////////////// Funktions-Implementierung //////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// Erstelle einen Array mit n^2 Inhalten, und betrachte diese als eine Matrix in der die Werte 
// Zeilenweise aneinander gereiht sind.
QMatrix::QMatrix(int n)
{
	dim = n;
	A = new double[n * n];
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			A[i * dim + j] = 0.0;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////
// Kopierkonstruktor
QMatrix::QMatrix(const QMatrix& alteMatrix)
{
	dim = alteMatrix.getDim();
	A = new double[dim * dim];
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			A[i * dim + j] = alteMatrix.get(i, j);
		}
	}
}

//////////////////////////////////////////////////////////////////////////////
//Zuweisungsoperator
QMatrix& QMatrix::operator=(const QMatrix& B)
{
	this->dim = B.getDim();
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			this->A[i * dim + j] = B.get(i, j);
		}
	}

	return *this;
}

//////////////////////////////////////////////////////////////////////////////
// Destruktor
QMatrix::~QMatrix()
{
	delete[] A;
}

//////////////////////////////////////////////////////////////////////////////
// Auf das Element in der i-ten Zeile und j-ten Spalte zurgreifen
double QMatrix::get(const int i, const int j) const
{
	return A[i * dim + j];
}

//////////////////////////////////////////////////////////////////////////////
// Setze Zahl an die i-te Zeile und j-te Spalte
void QMatrix::set(const int i, const int j, const double zahl)
{
	A[i * dim + j] = zahl;
}

//////////////////////////////////////////////////////////////////////////////
// Getmethode für die Dimension (wichtig für fast alle for-Schleifen)
int QMatrix::getDim() const
{
	return dim;
}

//////////////////////////////////////////////////////////////////////////////
// Transponiere die Matrix
void QMatrix::transponiere()
{
	double temp;
	for (int i = 0; i < dim; i++)
	{
		for (int j = i + 1; j < dim; j++)
		{
			temp = A[i * dim + j];
			A[i * dim + j] = A[j * dim + i];
			A[j * dim + i] = temp;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////
// Erstelle einer Matrix mit einer Spalte und Zeile weniger in der die i-te  Zeile und j-te Spalte der
// ursprünglichen Matrix fehlt und gebe diese neue Matrix zurück
QMatrix QMatrix::untermatrix(int i, int j)
{
	QMatrix untermat(this->getDim() - 1);
	int n = 0;
	for (int k = 0; k < this->getDim(); k++)
	{
		for (int l = 0; l < this->getDim(); l++)
		{
			if ((i != k) && (j != l))
			{
				untermat.A[n] = this->get(k, l);
				n++;
			}
		}
	}
	return untermat;

}

//////////////////////////////////////////////////////////////////////////////
QMatrix QMatrix::inverse()
{
	double det = determinante();
	QMatrix adj = adjunkte();

	return adj * (1 / det);
}

//////////////////////////////////////////////////////////////////////////////
double QMatrix::determinante()
{
	int dim = getDim();

	if (dim == 1)
	{
		return get(0, 0);
	}
	else
	{
		double det = 0;

		// Laplace Entwicklung nach erster Spalte
		for (int i = 0; i < getDim(); i++)
		{
			det += pow(-1, i+2) * get(i, 0) * untermatrix(i, 0).determinante();
		}

		return det;
	}
}

//////////////////////////////////////////////////////////////////////////////
QMatrix QMatrix::adjunkte()
{
	QMatrix mat(getDim());

	for (int i = 0; i < getDim(); i++)
	{
		for (int j = 0; j < getDim(); j++)
		{
			mat.set(i, j, pow(-1, i+j) * untermatrix(i, j).determinante());
		}
	}

	mat.transponiere();

	return mat;
}

//////////////////////////////////////////////////////////////////////////////
QMatrix QMatrix::operator*(double scalar)
{
	QMatrix mat(getDim());

	for (int i = 0; i < getDim(); i++)
	{
		for (int j = 0; j < getDim(); j++)
		{
			mat.set(i, j, get(i, j) * scalar);
		}
	}

	return mat;
}

//////////////////////////////////////////////////////////////////////////////
// Ausgabeoperator, außerhalb der Klasse implementiert
ostream& operator<<(ostream& Stream, const QMatrix& A)
{
	for (int i = 0; i < A.getDim(); i++)
	{
		for (int j = 0; j < A.getDim(); j++)
		{
			Stream << setprecision(4) << A.get(i, j) << "\t";
		}
		Stream << endl;
	}
	Stream << endl;
	return Stream;
}
