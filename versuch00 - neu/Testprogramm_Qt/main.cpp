 //////////////////////////////////////////////////////////////////////////////
 // Praktikum Informatik 1 SS2012
 // Testprogramm_Qt:
 // Versuch00: Vorbereitung auf Praktikum
 //
 // Datei: main.cpp
 // Inhalt: Hauptprogramm
 ////////////////////////////////////////////////////////////////////////////

#include <QtGui/QApplication>
#include <QtGui/QPushButton>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QPushButton hello("Schlieﬂe mich");

    hello.resize(200,200);
    QObject::connect(&hello, SIGNAL(clicked()),&app, SLOT(quit()));

    hello.show();


    return app.exec();
}
