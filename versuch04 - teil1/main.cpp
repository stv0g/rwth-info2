/**
 * Praktikum Informatik 1
 * Versuch 4.1: Dynamische Datenstrukturen

 * Datei:  main.cpp
 * Inhalt: Hauptprogramm
 */

#include <iostream>
#include <string>
#include "Stack.h"
#include "Student.h"

using namespace std;

int main()
{
	Stack testStack;
	Student stud1;

	char abfrage;
	cout << "Wollen sie den Stack selbst fuellen? (j)/(n) "; cin >> abfrage;

	if (abfrage != 'j')
	{
		stud1.matNr = 12345;
		stud1.adresse = "Ahornst.55";
		stud1.gebDatum = "23.04.1983";
		stud1.name = "Siggi Baumeister";
		testStack.push(stud1);

		stud1.matNr = 23456;
		stud1.adresse = "Wöllnerstr.9";
		stud1.gebDatum = "15.10.1963";
		stud1.name = "Walter Rodenstock";
		testStack.push(stud1);

		stud1.matNr = 34567;
		stud1.adresse = "Am Markt 1";
		stud1.gebDatum = "19.06.1971";
		stud1.name = "Harro Simoneit";
		testStack.push(stud1);
	}

	do
	{
		cout << "\nMenue:" << endl << "----------------------------" << endl
				<< "(1): Datenelement hinzufügen" << endl
				<< "(2): Datenelement abhängen" << endl
				<< "(3): Datenbank ausgeben" << endl
				<< "(7): Beenden" << endl;
		cout << "Ihre Wahl: "; cin >> abfrage;

		switch (abfrage)
		{
		case '1':
			cout << endl << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
			cin.ignore(10, '\n'); // Ignoriere das Zeichen '\n', das noch im Puffer ist
			getline(cin, stud1.name); // ganze Zeilen einlesen, inkl Leerzeichen
			cout << "Geburtsdatum: ";
			getline(cin, stud1.gebDatum);
			cout << "Adresse: ";
			getline(cin, stud1.adresse);
			cout << "Matrikelnummer: ";
			cin >> stud1.matNr;
			testStack.push(stud1);
			break;

		case '2':
			cout << endl << "Das oberste Datenelemt wird entfernt" << endl;
			testStack.pop(stud1);
			break;

		case '3':
			cout << endl << "Inhalt des Stacks:" << endl;
			testStack.ausgabe();
			break;

		case '7':
			cout << endl << "Das Programm wird nun beendet" << endl;
			break;

		default:
			cout << "Falsche Eingabe, bitte nochmal" << endl;
			break;
		}
	} while (abfrage != '7');

	return 0;
}
