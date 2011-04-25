#include <iostream>	// stream-handling
#include <iomanip>	// stream-formatting
#include <string>	// string-class
using namespace std;

int main_d(int argc, char **argv) {
	/* 2.5.1 */
	int iErste;
	int iZweite;

	/* read from stdin */
	cout << "iErste = "; cin >> iErste;
	cout << "iZweite = "; cin >> iZweite;

	int iSumme = iErste + iZweite;
	int iQuotient = iErste / iZweite;

	/* 2.5.2 */
	double dSumme = iErste + iZweite;
	double dQuotient = iErste / iZweite;

	/* 2.5.3 */
	double dSummeCast = (double) iErste + (double) iZweite;
	double dQuotientCast = iErste / (double) iZweite;

	cout << "iErste = " << iErste << endl << "iZweite = " << iZweite << endl
			<< "iSumme = " << iSumme << endl << "iQuotient = " << iQuotient
			<< endl << "dSumme = " << dSumme << endl << "dQuotient = "
			<< dQuotient << endl << "dSummeCast = " << dSummeCast << endl
			<< "dQuotientCast = " << dQuotientCast << endl;

	/* 2.5.4 */
	string sVorname;
	string sNachname;

	/* read from stdin */
	cout << "Vorname: "; cin >> sVorname;
	cout << "Nachname: "; cin >> sNachname;

	/* string operations */
	string sVornameName = sVorname + " " + sNachname;
	string sNameVorname = sNachname + ", " + sVorname;

	cout << sVornameName << endl << sNameVorname << endl << endl;

	/* 2.5.5 */
	{
		/* 2.5.5 a) */
		int iFeld[2] = { 1, 2 };
		/* 2.5.5 b) */
		int spielfeld[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };

		/* 2.5.5 c) print iFeld */
		for (int i = 0; i < 2; i++) {
			cout << "iFeld[" << i << "] = " << iFeld[i] << endl;
		}
		cout << endl;

		/* 2.5.5 c) print spielfeld */
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << "spielfeld[" << i << "][" << j << "] = " << spielfeld[i][j] << endl;
			}
		}

		/* 2.5.5 d) */
		const int iZweite = 1; /* new scope! */
		cout << endl << "iZweite = " << iZweite << endl;
	}

	cout << "iZweite = " << iZweite << endl << endl;

	/* 2.5.6 */
	int iName1 = sVorname[0];
	int iName2 = sVorname[1];

	cout << "ASCII-Codierung: " << iName1 << ", " << iName2 << endl;

	/* 2.5.7 */
	iName1 = (iName1 - 'A') % ('A'-'a') + 1;
	iName2 = (iName2 - 'A') % ('A'-'a') + 1;

	cout << "Position: " << iName1 << ", " << iName2 << endl;

	return 0;
}
