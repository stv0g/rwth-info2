//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 8.2: STL
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Student.h"

using namespace std;


int main()
{
	Student stud1(22222, "Born"      ,"Jessica", "16.03.1986");
	Student stud2(24528, "Rodenstock","Max"    , "09.02.1985");
	Student stud3(95420, "Schneider" ,"Petra"  , "29.12.1989");
	Student stud4(44523, "Baumeister","Siggi"  , "13.01.1979");
	Student stud5(12635, "Baumeister","Dinah"  , "07.06.1982");
	Student stud6(81237, "Simoneit"  ,"Harro"  , "30.10.1973");
	Student stud7(54879, "Soers"     ,"Irmchen", "01.06.1983");
	Student stud8(35484, "West"      ,"Johnny" , "24.12.1980");

	
	/* now using std::vector<T> */
	vector<Student> students;

	students.push_back(stud1);
	students.push_back(stud2);
	students.push_back(stud3);
	students.push_back(stud4);
	students.push_back(stud5);
	students.push_back(stud6);
	students.push_back(stud7);
	students.push_back(stud8);

	sort(students.begin(), students.end());

	/* output again */
	for (vector<Student>::iterator it = students.begin(); it != students.end(); ++it)
	{
		cout << *it;
	}

	int matNr;
	cout << endl << "Bitte gebe die Matrikelnr an, die du löschen willst: "; cin >> matNr;

	for (vector<Student>::iterator it = students.begin(); it != students.end(); ++it)
	{
		if (it->getMatNr() == matNr) /* found */
		{
			char decission;

			cout << "Gefunden: " << *it;
			cout << "Soll dieser Student aus der Liste gelöscht werden? (j/n) "; cin >> decission;

			if (decission == 'j')
			{
				students.erase(it); /* remove from vector */
				break;
			}
		}
	}

	/* output again */
	cout << endl;
	for (vector<Student>::iterator it = students.begin(); it != students.end(); ++it)
	{
			cout << *it;
	}

	return 0;
}
