//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 10: Anwendung von Filterfunktionen
//
// Datei:  Matrix3x3.h
// Inhalt: Klasse Matrix3x3 zur Handhabung von 3x3 Matrizen
//////////////////////////////////////////////////////////////////////////////

#ifndef MATRIX3X3_H_
#define MATRIX3X3_H_

//////////////////////////////////////////////////////////////////////////////
///////////////////////////////// INCLUDES ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
///////////////////////// CLASS DECLARATION //////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/// Matrizen-Klasse: <br>
/// Eine Instanz dieser Klasse ist eine 3x3-Matrix aus Integerwerten
class Matrix3x3
{
public:
	/// Standardkonstruktor, besetzt alle Werte der Matrix mit Null.
	/// @return eine Instanz dieses Objektes
	Matrix3x3();
	
	/// Konstruktor, der alle Werte der Matrix belegt. <br>
	/// | a11 a12 a13 | <br>
	/// | a21 a22 a23 | <br>
	/// | a31 a32 a33 | <br>
	/// @return eine Instanz dieses Objektes
	Matrix3x3(int a11, int a12, int a13, int a21, int a22, int a23, int a31, int a32, int a33);
	
	/// Besetzt die Werte der Matrix neu
	void setMatrix(int a11, int a12, int a13, int a21, int a22, int a23, int a31, int a32, int a33);

	/// Gibt die Matrix in transponierter Form zurueck
	/// @return Die transponierte Matrix
	Matrix3x3 transpose();
	
	/// Gibt den Wert der Matrix an der Stelle i,j zurück
	int getMatrixWert(int i,int j);

private:	
	/// Die 3x3 Matrix
	int matrix[3][3];
};

#endif /*MATRIX3X3_H_*/
