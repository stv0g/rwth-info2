//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 4.2: Dynamische Datenstrukturen
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include "List.h"
#include "Student.h"
using namespace std;

int main()
{
	List testListe;
	Student stud1;
	int matNr;
	
	char abfrage;
	cout << "Wollen sie die Liste selbst fuellen? (j)/(n) ";
	cin >> abfrage;
	if (abfrage != 'j' )
	{
		stud1.matNr = 12345;
		stud1.adresse = "Ahornst.55";
		stud1.gebDatum = "23.04.1983";
		stud1.name = "Siggi Baumeister";
		testListe.enqueuehead(stud1);
		stud1.matNr = 23456;
		stud1.adresse = "Wüllnerstr.9";
		stud1.gebDatum = "15.10.1963";
		stud1.name = "Walter Rodenstock";
		testListe.enqueuehead(stud1);
		stud1.matNr = 34567;
		stud1.adresse = "Am Markt 1";
		stud1.gebDatum = "19.06.1971";
		stud1.name = "Harro Simoneit";
		testListe.enqueuehead(stud1);
	}
	do
	{
		cout << "\nMenue:" << endl << "-----------------------------" << endl
			 << "(1): Datenelement vorne ergänzen" << endl
			 << "(2): Datenelement abhängen" << endl
		     << "(3): Datenbank ausgeben (vorwärts)" << endl
		     << "(4): Datenbank ausgeben (rückwärts)" << endl
		     << "(5): Datenelement löschen" << endl
		     << "(6): Datenelement hinten gergänzen" << endl
		     << "(7): Beenden" << endl;
		cin >> abfrage;
		switch (abfrage)
		{
	 		case '1': cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
	 				  cin.ignore(10,'\n'); // Ignoriere das Zeichen '\n', das noch im Puffer ist
	 				  getline(cin, stud1.name);  // ganze Zeilen einlesen, inkl Leerzeichen
	 				  cout << "Geburtsdatum: ";
	 				  getline(cin, stud1.gebDatum); 
	 				  cout << "Adresse: ";
	 				  getline(cin, stud1.adresse);
	 				  cout << "Matrikelnummer: ";
	 				  cin >> stud1.matNr;
	 				  testListe.enqueuehead(stud1);	 		
	 				  break;
	 		case '2': cout << "Das hintere Datenelemt wird abgehangen" << endl;
	 				  testListe.dequeue(stud1);
	 				  break;
	 		case '3': cout << "Inhalt der Liste von vorne nach hinten" << endl;
	 				  testListe.ausgabevorwaerts();
	 				  break;
	 		case '4': cout << "Inhalt der Liste von hinten nach vorne" << endl;
	 				  testListe.ausgaberueckwaerts();
	 			 	  break;
	 		case '5': cout << "Bitte geben sie eine Matrikelnr an: "; cin >> matNr;
	 			 	  if (testListe.remove(matNr))
	 			 	  {
	 			 		  cout << "Student wurde erfolgreich aus der Liste entfernt" << endl;
	 			 	  }
	 			 	  else
	 			 	  {
	 			 		  cout << "Matrikel Nr wurde nciht gefunden!" << endl;
	 			 	  }
	 			 	  break;
	 		case '6': cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
	 			 	  cin.ignore(10,'\n'); // Ignoriere das Zeichen '\n', das noch im Puffer ist
	 			 	  getline(cin, stud1.name);  // ganze Zeilen einlesen, inkl Leerzeichen
					  cout << "Geburtsdatum: ";
					  getline(cin, stud1.gebDatum);
					  cout << "Adresse: ";
					  getline(cin, stud1.adresse);
					  cout << "Matrikelnummer: ";
					  cin >> stud1.matNr;
					  testListe.enqueuetail(stud1);
					  break;
	 		case '7': cout << "Das Programm wird nun beendet" << endl;
	 				  break;
	 		default : cout << "Falsche Eingabe, bitte nochmal";
		}
	}
	while(abfrage != '7');
		
	return 0;
}
