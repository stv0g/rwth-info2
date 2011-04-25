//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 8.2: STL
//
// Datei:  Student.h
// Inhalt: Studentenklasse mit Merkmalen eines Studenten
//////////////////////////////////////////////////////////////////////////////

#ifndef STUDENT_H
#define STUDENT_H

//////////////////////////////////////////////////////////////////////////////
///////////////////////////////// INCLUDES ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

//////////////////////////////////////////////////////////////////////////////
///////////////////////// KLASSE DEKLARATION/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//StudentenKlasse
class Student
{
  public:
	Student(){}
	Student(int matrikelnummer, string name, string vorname, string datum);
	int getMatNr() const;
	bool operator == (const Student& stud) const;
	bool operator < (const Student& stud) const;
	friend ostream& operator << (ostream& out, Student& stud);

	//ostream& ausgabe(ostream& out);
	//friend bool operator == (const Student& stud1,const Student& stud2);
	//friend bool operator < (const Student& stud1,const Student& stud2);
	//friend bool operator > (const Student& stud1,const Student& stud2);

  private:
	int matNr;
	string name;
	string vorname;
	string geburtsdatum;
};

// Ausgabeoperator muss au�erhalb der Klasse definiert sein, weil er als linken Operand
// keine Instanz der Klasse besitzt, sondern meist "cout"
ostream& operator << (ostream& out, Student& stud);

#endif // STUDENT_H

