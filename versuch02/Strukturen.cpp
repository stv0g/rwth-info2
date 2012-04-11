#include <iostream>
#include <string>

using namespace std;

struct Person {
	string sNachname, sVorname;
	int iGeburtsjahr, iAlter;
};

struct Person readPerson() {
	struct Person nPerson;

	/* read from stdin */
	cout << "Nachname: "; cin >> nPerson.sNachname;
	cout << "Vorname: "; cin >> nPerson.sVorname;

	cout << "Geburtsjahr: "; cin >> nPerson.iGeburtsjahr;
	cout << "Alter: "; cin >> nPerson.iAlter;

	return nPerson;
}

void printPerson(struct Person nPerson) {
	cout << endl << "Nachname: " << nPerson.sNachname << endl
		<< "Vorname: " << nPerson.sVorname << endl
		<< "Geburtsjahr: " << nPerson.iGeburtsjahr << endl
		<< "Alter: " << nPerson.iAlter << endl;
}

int main_f(int argc, char **argv) {
	struct Person nBenutzer = readPerson();
	printPerson(nBenutzer);

	struct Person nKopieGesamt = nBenutzer;
	printPerson(nKopieGesamt);

	/* deep copy */
	struct Person nKopieEinzeln;
	nKopieEinzeln.sNachname = nBenutzer.sNachname;
	nKopieEinzeln.sVorname = nBenutzer.sVorname;
	nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
	nKopieEinzeln.iAlter = nBenutzer.iAlter;

	printPerson(nKopieEinzeln);

	return 0;
}
