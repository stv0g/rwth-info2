//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 09: Anwendung von Filterfunktionen
//
// Datei:  ImageViewer.h
// Inhalt: Klasse ImageViewer zum oeffnen, speicher, und zum Darstellen von Bildern
//////////////////////////////////////////////////////////////////////////////

#ifndef IMAGEVIEWER_H_
#define IMAGEVIEWER_H_

//////////////////////////////////////////////////////////////////////////////
///////////////////////////////// INCLUDES ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#include <QtGui/QMainWindow>

class QLabel;
class QImage;

//////////////////////////////////////////////////////////////////////////////
///////////////////////// CLASS DECLARATION //////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


/// ImageViewer-Klasse: <br>
/// Diese Klasse ist abgeleitet von der Klasse QMainWindow und dient zur Darstellung eines Bildes <br>
/// Sie kann ein Bild oeffnen und speicher. Mittels Set- und Getmethode laesst sich auf das Bild zugreifen <br
class ImageViewer : public QMainWindow
{

public:
	
	/// Standardkonstruktor, erzeugt ein Fenster der Groe�e 500*400 und zeigt dieses an. 
	/// Ein Bild wird noch nicht erzeugt
	/// @return Eine Instanz dieses Objektes (Inhalt: leer)
	ImageViewer();
	
	/// Konstruktor, der ein Fenster erzeugt und das uebergebene Bild direkt anzeigt
	/// @param Image Zeiger auf QImage
	/// @return Eine Instanz dieses Objektes (Inhalt: Image)
	ImageViewer(QImage* image);

	/// Destructor
	~ImageViewer();

	/// erzeugt eine Instanz von QImage, laed ein Bild auf das Fenster und aktualisiert die Groe�e des Fensters
	void open();
	
	/// speichert das aktuelle Bild, das angezeigt wird 
	void save();
	
	/// Getmethode zum Auslesen des aktuellen Bildes
	/// @return Ein Zeiger auf das aktuelle Bild	
	QImage* getImage();
	
	/// Setmethode zum Setzen des Bildes, das angezeigt wird
	/// @param neu Zeiger auf das Bild, das im Fenster angezeigt werden soll
	void setImage(QImage* neu);
	
	/// Das Bild durchstreichen
	QImage* stroke(QColor color);

	/// Das Bild einrahmen
	QImage* frame(int thickness, QColor);

	/// Das Bild in Graustufen umwandeln
	QImage* grayscale();

	/// Getter für Bildnamen
	QString getName();

private:
	/// Zeiger auf das Bild das im Fenster angezeigt wird
	QImage* image;	
	
	/// Zeiger auf das Label, dieses ist das Hauptwidget von ImageViewer und es beinhaltet das Bild
	QLabel* label;
	
	/// statische Zaehlvariable um die Anzahl der angezeigten Fenster zu zaehlen
	static int count;

	QString name;

};


#endif /*IMAGEVIEWER_H_*/

