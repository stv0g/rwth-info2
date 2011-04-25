//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 10: Anwendung von Filterfunktionen
//
// Datei:  Matrix3x3.cpp
// Inhalt: Klasse Matrix3x3 zur Handhabung von 3x3 Matrizen
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
///////////////////////////////// INCLUDES ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#include "Matrix3x3.h"

//////////////////////////////////////////////////////////////////////////////
///////////////////////// Funktions-Implementierung //////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
Matrix3x3::Matrix3x3()
{
	matrix[0][0] = 0; matrix[0][1] = 0; matrix[0][2] = 0;
	matrix[1][0] = 0; matrix[1][1] = 0; matrix[1][2] = 0; 
	matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = 0; 
}

//////////////////////////////////////////////////////////////////////////////
Matrix3x3::Matrix3x3(int a11, int a12, int a13, int a21, int a22, int a23, int a31, int a32, int a33)
{
	matrix[0][0] = a11; matrix[0][1] = a12; matrix[0][2] = a13;
	matrix[1][0] = a21; matrix[1][1] = a22; matrix[1][2] = a23; 
	matrix[2][0] = a31; matrix[2][1] = a32; matrix[2][2] = a33; 
}

//////////////////////////////////////////////////////////////////////////////
void Matrix3x3::setMatrix(int a11, int a12, int a13, int a21, int a22, int a23, int a31, int a32, int a33)
{
	matrix[0][0] = a11; matrix[0][1] = a12; matrix[0][2] = a13;
	matrix[1][0] = a21; matrix[1][1] = a22; matrix[1][2] = a23; 
	matrix[2][0] = a31; matrix[2][1] = a32; matrix[2][2] = a33;
}

//////////////////////////////////////////////////////////////////////////////
Matrix3x3 Matrix3x3::transpose()
{
	Matrix3x3 trans;
	trans.matrix[0][0] = matrix[0][0]; trans.matrix[0][1] =  matrix[1][0]; trans.matrix[0][2] = matrix[2][0];
	trans.matrix[1][0] = matrix[0][1]; trans.matrix[1][1] =  matrix[1][1]; trans.matrix[1][2] = matrix[2][1];
	trans.matrix[2][0] = matrix[0][2]; trans.matrix[2][1] =  matrix[1][2]; trans.matrix[2][2] = matrix[2][2];
	return trans;
}

//////////////////////////////////////////////////////////////////////////////
int Matrix3x3::getMatrixWert(int i,int j)
{
	return matrix[i][j];
}
