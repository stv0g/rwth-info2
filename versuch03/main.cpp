#include <iostream>
#include <stdlib.h>

#define SIZE_X 8
#define SIZE_Y 8

using namespace std;

#include "Reversi_KI.h"

void spielfeld_anzeigen(int spielfeld[SIZE_X][SIZE_Y])
{
	cout << "  ";

	for (int j = 65; j < 65 + SIZE_Y; j++)
	{
		cout << ((char) j) << " ";
	}
	cout << endl;
	for (int i = 0; i < SIZE_X; i++)
	{
		cout << i + 1;

		for (int j = 0; j < SIZE_Y; j++)
		{
			switch (spielfeld[j][i])
			{
			case 0:
				cout << "  ";
				break;

			case 1:
				cout << " X";
				break;

			case 2:
				cout << " O";
				break;

			default:
				cout << "Inconsistent data in field! (spielfeld_anzeigen)" << endl;
				cout << "Aborting .... " << endl;
				exit(0);
				break;
			}
		}; // for j

		cout << endl;
	} // for i
}

int gewinner(int spielfeld[SIZE_X][SIZE_Y])
{
	int count_p1 = 0;
	int count_p2 = 0;

	for (int i = 0; i < SIZE_X; i++)
	{
		for (int j = 0; j < SIZE_Y; j++)
		{
			// loop through all fields + counting of X (1) and O (2)
			switch (spielfeld[j][i])
			{
			case 0: /* empty field */
				break;

			case 1:
				count_p1++;
				break;

			case 2:
				count_p2++;
				break;

			default:
				cout << "Inconsistent data in field! (gewinner)" << endl;
				cout << "Aborting .... " << endl;
				exit(0);
				break;
			}
		}
	}
	if (count_p1 == count_p2)
	{
		return 0;
	}
	if (count_p2 > count_p1)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

bool zug_gueltig(int spielfeld[SIZE_X][SIZE_Y], int spieler, int pos_x,
		int pos_y)
{
	int gegner = 3 - spieler; /* toggle player */

	if (spielfeld[pos_x][pos_y] != 0) // check if field is currently empty
	{
		return false;
	}

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			int p = 1;
			while (pos_x+p*i >= 0 && pos_x+p*i < SIZE_X && pos_y+p*j >= 0 && pos_y+p*j < SIZE_Y) {
				if (spielfeld[pos_x+i*p][pos_y+j*p] == gegner)
					/* a opponents stone
					 * continue to look for own stone */
				{
					p++;
					continue;
				}
				else if (spielfeld[pos_x+i*p][pos_y+j*p] == spieler && p > 1)
					/* oh, thats our stone!
					 * and w've already seen a stone from out opponent (p > 0)
					 * move is valid */
				{
					return true;
				}
				else
					/* no stone or inconsistent playfield
					 * move is invalid, continue with next opponent */
				{
					break;
				}
			}
		}
	}

	return false;
}

bool zug_ausfuehren(int spielfeld[SIZE_X][SIZE_Y], int spieler, int pos_x,
		int pos_y)
{
	int gegner = 3 - spieler; /* toggle player */

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			int p = 1;
			while (pos_x+p*i >= 0 && pos_x+p*i < SIZE_X && pos_y+p*j >= 0 && pos_y+p*j < SIZE_Y) {
				if (spielfeld[pos_x+i*p][pos_y+j*p] == gegner)
					/* a opponents stone
					 * continue to look for own stone */
				{
					p++;
					continue;
				}
				else if (spielfeld[pos_x+i*p][pos_y+j*p] == spieler && p > 1)
					/* oh, thats our stone!
					 * and w've already seen a stone from out opponent (p > 0)
					 * move is valid */
				{
					for (int q = 1; q <= p; q++) { /* turn stones */
						spielfeld[pos_x+q*i][pos_y+q*j] = spieler;
					}
					break;
				}
				else
					/* no stone or inconsistent playfield
					 * move is invalid, continue with next opponent */
				{
					break;
				}
			}
		}
	}

	spielfeld[pos_x][pos_y] = spieler;

	return true;
}

int moegliche_zuege(int spielfeld[SIZE_X][SIZE_Y], int spieler)
{
	int zuege = 0;

	for (int i = 0; i < SIZE_X; i++)
	{
		for (int j = 0; j < SIZE_Y; j++)
		{
			if (zug_gueltig(spielfeld, spieler, i, j))
			{
				zuege++;
			}
		}
	}

	return zuege;
}

bool mensch_zug(int spielfeld[SIZE_X][SIZE_Y], int spieler)
{
	if (moegliche_zuege(spielfeld, spieler) == 0)
	{
		return false;
	}

	int px;
	int py;
	bool repeat = false;

	do
	{
		if (repeat)
		{
			cout << "Invalid input !" << endl;
		}

		string eingabe;
		eingabe.reserve(50);
		cout << endl << "Player " << spieler << ": Your move (e.g. A1): ";
		eingabe.erase(eingabe.begin(), eingabe.end());
		cin >> eingabe;

		px = ((int) eingabe.at(0)) - 65;
		py = ((int) eingabe.at(1)) - 49;
	} while ((repeat = !zug_gueltig(spielfeld, spieler, px, py)));

	zug_ausfuehren(spielfeld, spieler, px, py);
	return true;
}

void spiel(int spielertyp[2])
{
	int spielfeld[SIZE_X][SIZE_Y] =
	{
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 1, 2, 0, 0, 0 },
	{ 0, 0, 0, 2, 1, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 } };

	int aktueller_spieler = 1;
	spielfeld_anzeigen(spielfeld);

	// let each player make its moves until no further moves are possible
	while (moegliche_zuege(spielfeld, aktueller_spieler) > 0) {
		switch (spielertyp[aktueller_spieler-1]) {
			case 1:
				mensch_zug(spielfeld, aktueller_spieler);
				break;

			case 2:
				computer_zug(spielfeld, aktueller_spieler);
				break;

			default:
				cout << "Inconsistent data in field! (spiel)" << endl;
				cout << "Aborting .... " << endl;
				exit(0);
				break;
		}

		cout << endl;
		spielfeld_anzeigen(spielfeld);

		if (moegliche_zuege(spielfeld, 3 - aktueller_spieler)) {
			aktueller_spieler = 3 - aktueller_spieler;
		}
	}

	int winner = gewinner(spielfeld);
	switch (winner)
	{
		case 0:
			cout << "Das Spiel ist unentschieden ausgegangen!" << endl;
			break;

		case 1:
		case 2:
			cout << "Spieler " << winner << " hat gewonnen" << endl;
			break;
	}
}

int main(void)
{
	int typ[2] = { 1, 2 };
	spiel(typ); /* start game */

	return 0;
}

