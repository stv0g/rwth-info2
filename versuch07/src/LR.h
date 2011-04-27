//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 7: L�sung eines mathematischen Anwendungsproblems
//
// Datei:  LR.h
// Inhalt: LR-Klasse
/////////////////////////////////////////////////////////////////////////////

#ifndef LR_H_
#define LR_H_

//////////////////////////////////////////////////////////////////////////////
///////////////////////////////// INCLUDES ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#include "LGSLoeser.h"
#include "QMatrix.h"
#include "Vektor.h"

//////////////////////////////////////////////////////////////////////////////
///////////////////////// CLASS DECLARATION //////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

class LR: public LGSLoeser
{
public:
	// Konstruktor, übernimmt die Dimension
	LR(int n);
	// Lösungsmethode, übernimmt Matrix A und Vektor b und gibt die Lösung x zurück
	Vektor loese(QMatrix A, Vektor b);
     // Destruktor
     ~LR();

private:
	// Unterteilung des Lösungsvorgangs in 4 Schritte:
	// Zerlegt Matrix A, Die zerlegten Matrizen L und R sind danach in A gespeichert
	void zerlege(QMatrix& A);
	// Herauskopieren der bedeutenden Einträge in L und R
	void erzeugeLundR(QMatrix& A);
	// Vorwaertseinsetzen(berechnen von Vektor y aus L und b)
	void vorwaertsEinsetzen(Vektor& b);
	// Rueckwaertseinsetzen(berechnen von Vektor x aus R und y)
	void rueckwaertsEinsetzen();
	
	Vektor* y;
	QMatrix* L;
	QMatrix* R;
};


#endif /*LR_H_*/
