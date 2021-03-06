//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 7: L�sung eines mathematischen Anwendungsproblems
//
// Datei:  Cramer.h
// Inhalt: Cramer-Klasse
//////////////////////////////////////////////////////////////////////////////

#ifndef CRAMER_H_
#define CRAMER_H_

//////////////////////////////////////////////////////////////////////////////
///////////////////////////////// INCLUDES ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#include "LGSLoeser.h"

//////////////////////////////////////////////////////////////////////////////
///////////////////////// CLASS DECLARATION //////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

class Cramer : public LGSLoeser
{
public:
	Cramer(int dim);
	Vektor loese(QMatrix A, Vektor b);
};

#endif /*CRAMER_H_*/
