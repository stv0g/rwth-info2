// Reversi_KI.h
//
// Part of PAI
//
// containing function for computer move

#include <iostream>
#include <unistd.h>

using namespace std;

int moegliche_zuege(int spielfeld[SIZE_X][SIZE_Y], int spieler);
bool zug_ausfuehren(int spielfeld[SIZE_X][SIZE_Y], int spieler, int pos_x,
		int pos_y);
bool zug_gueltig(int spielfeld[SIZE_X][SIZE_Y], int spieler, int pos_x,
		int pos_y);

bool computer_zug(int spielfeld[SIZE_X][SIZE_Y], int spieler)
{
	if (moegliche_zuege(spielfeld, spieler) == 0)
	{
		return false;
	}
	int look_ahead[SIZE_X][SIZE_Y];
	int min_x = 0;
	int min_y = 0;
	int min = SIZE_X * SIZE_Y;

	for (int i = 0; i < SIZE_Y; i++)
	{
		for (int j = 0; j < SIZE_Y; j++)
		{
			// reset field
			for (int ci = 0; ci < SIZE_X; ci++)
			{
				for (int cj = 0; cj < SIZE_Y; cj++)
				{
					look_ahead[ci][cj] = spielfeld[ci][cj];
				}
			}

			if (zug_gueltig(look_ahead, spieler, i, j))
			{
				zug_ausfuehren(look_ahead, spieler, i, j);
				if (moegliche_zuege(look_ahead, -(spieler - 2) + 1) < min)
				{
					min = moegliche_zuege(look_ahead, -(spieler - 2) + 1);
					min_x = i;
					min_y = j;
				}
			}
		}
	}

	zug_ausfuehren(spielfeld, spieler, min_x, min_y);
	cout << endl << "Player " << spieler << " moves to " << (char) (min_x + 65)
			<< (min_y + 1) << endl;
	usleep(1000000);// 2 seconds pause to check computers move!
	return true;
}
