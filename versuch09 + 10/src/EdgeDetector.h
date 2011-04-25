//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 10: Anwendung von Filterfunktionen
//
// Datei:  EdgeDetector.h
// Inhalt: Klasse EdgeDetector zur Detektierung von Kanten in Farb-/Graubildern
//////////////////////////////////////////////////////////////////////////////

#ifndef EDGEDETECTOR_H_
#define EDGEDETECTOR_H_

//////////////////////////////////////////////////////////////////////////////
///////////////////////////////// INCLUDES ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#include "Matrix3x3.h"

//////////////////////////////////////////////////////////////////////////////
///////////////////////// CLASS DECLARATION //////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

class EdgeDetector
{
public:
	EdgeDetector();

	enum FilterDirection {
		HORIZONTAL,
		VERTICAL,
		BOTH,
		NONE
	};

	/* Faltungssumme berechnen */
	void applyFilter(QImage *in, QImage *out);

	/* Fitlermatrix ändern */
	void setFilter(int a11, int a12, int a13, int a21, int a22, int a23, int a31, int a32, int a33);

	/* Normalisierungsfaktur manuell festlegen */
	void setSensivity(double newSensivity);

	void setNormalize(bool newNormalize);
	void setFilterDirection(FilterDirection newDir);

private:
	Matrix3x3 filter;
	double sensivity;
	bool normalize;
	FilterDirection direction;
};

#endif /*EDGEDETECTOR_H_*/
