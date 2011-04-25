#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

struct Date {
	int day;
	int month;
	int year;
};

char * daynames[] = {
		"Sonntag",
		"Montag",
		"Dienstag",
		"Mittwoch",
		"Donnerstag",
		"Freitag",
		"Samstag"
};

char * leapYearStr[] = {
		"kein",
		"ein"
};

/**
 * Days of year
 */
int daysofyear[][12] = {
	{ /* no leap year */
		0,
		1*31,
		1*31 + 1*30 - 2,
		2*31 + 1*30 - 2,
		2*31 + 2*30 - 2,
		3*31 + 2*30 - 2,
		3*31 + 3*30 - 2,
		4*31 + 3*30 - 2,
		4*31 + 4*30 - 2,
		5*31 + 4*30 - 2,
		5*31 + 5*30 - 2,
		6*31 + 5*30 - 2,
	},
	{ /* leap year */
		0,
		1*31,
		1*31 + 1*30 - 1, /* add leap day after march */
		2*31 + 1*30 - 1,
		2*31 + 2*30 - 1,
		3*31 + 2*30 - 1,
		3*31 + 3*30 - 1,
		4*31 + 3*30 - 1,
		4*31 + 4*30 - 1,
		5*31 + 4*30 - 1,
		5*31 + 5*30 - 1,
		6*31 + 5*30 - 1,
	}
};

bool isLeapYear(struct Date date) {
	return date.year % 4 == 0 && (date.year % 400 == 0 || date.year % 100 != 0);
}

int calcLeapDays(struct Date date) {
	int leapDays = 0;
	int years = date.year - 1; /* only use past years for calc */
	leapDays += years / 4;
	leapDays += years / 400;
	leapDays -= years / 100;

	return leapDays;
}

int main(int argc, char **argv) {
	struct Date date;

	/* read date */
	cout << "Bitte gebe ein Datum ein (dd-mm-yyyy): ";
	scanf("%d.%d.%d", &date.day, &date.month, &date.year);

	/* input validation to stay in array boundaries */
	date.day = (date.day-1) % 31 + 1;
	date.month = (date.month-1) % 12 + 1;
	//cout << date.day << "." << date.month << "." << date.year << endl; /* check validation results */

	bool bLeapYear = isLeapYear(date);
	int leapDays = calcLeapDays(date);
	int years = date.year - 1; /* gregorian calendar starts with 1.1.1 */
	int days = 0;

	days += years * 365; /* add years without leap days */
	days += daysofyear[isLeapYear(date)][date.month-1];
	days += date.day;
	days += leapDays;

	/* Output */
	cout << endl << "Berechnungen für den " << setfill('0') << setw(2) << date.day << "." << setw(2) << date.month << "." << setw(4) << date.year << endl;
	cout << "Das Jahr " << setfill('0') << setw(4) << date.year << " ist " << leapYearStr[bLeapYear] << " Schaltjahr." << endl;
	cout << "Anzahl der Schaltjahre:\t\t" << leapDays << endl;
	cout << "Anzahl normaler Jahre:\t\t" << years - leapDays << endl;
	cout << "Anzahl der Tage:\t\t" << days << endl;
	cout << "Wochentag (Modulo):\t\t" << days % 7 << endl;
	cout << "Der Wochentag ist ein " << daynames[days % 7] << "." << endl;

	return 0;
}


