//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 8.1: Sortierverfahren, Templates
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> /* to sort vector */

#include "Student.h"
#include "StackSpeicher.h"

using namespace std;

int main()
{
	/* create students */
	Student stud1(22222, "Born"      ,"Jessica", "16.03.1986");
	Student stud2(24528, "Rodenstock","Max"    , "09.02.1985");
	Student stud3(95420, "Schneider" ,"Petra"  , "29.12.1989");
	Student stud4(44523, "Baumeister","Siggi"  , "13.01.1979");
	Student stud5(12635, "Baumeister","Dinah"  , "07.06.1982");
	Student stud6(81237, "Simoneit"  ,"Harro"  , "30.10.1973");
	Student stud7(54879, "Soers"     ,"Irmchen", "01.06.1983");
	Student stud8(35484, "West"      ,"Johnny" , "24.12.1980");

	Student stud; /* for output */

	/* test overloading of == operator */
	cout << "stud1 und stud2 sind " << ((stud1 == stud2) ? "gleich" : "ungleich") << endl << endl;
	
	/* test stack and quicksort */
	StackSpeicher<8, Student> students;

	/* fill stack */
	students.push(stud1);
	students.push(stud2);
	students.push(stud3);
	students.push(stud4);
	students.push(stud5);
	students.push(stud6);
	students.push(stud7);
	students.push(stud8);

	students.sort();

	while (students.pop(stud))
	{
		cout << stud;
	}

	return 0;
}
