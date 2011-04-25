//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 09: Einfuehrung in die Programmierung grafischer Benutzeroberflaechen
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////
#include <QtGui/QApplication>
using namespace std;

#include "ImageController.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	ImageController controller;

	controller.show(); /* show control panel */
	return app.exec(); /* run qt application */
}
