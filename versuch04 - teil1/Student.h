/**
 * Praktikum Informatik 1
 * Versuch 4.1: Dynamische Datenstrukturen

 * Datei:  Student.h
 * Inhalt: Studentenstruktur mit Merkmalen eines Studenten
 */


#include <string>
using namespace std;

#ifndef STUDENT_H_
#define STUDENT_H_

struct Student
{
	string name;
	int matNr;
	string gebDatum;
	string adresse;
};

#endif /*STUDENT_H_*/
