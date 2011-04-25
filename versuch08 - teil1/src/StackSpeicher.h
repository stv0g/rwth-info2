//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 8.1: Sortierverfahren, Templates
//
// Datei:  StackSpeicher.h
// Inhalt: generischer Stackspeicher
//////////////////////////////////////////////////////////////////////////////

#ifndef STACKSPEICHER_H_
#define STACKSPEICHER_H_

//////////////////////////////////////////////////////////////////////////////
///////////////////////////////// INCLUDES ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;
//////////////////////////////////////////////////////////////////////////////
///////////////////////// CLASS DECLARATION //////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

// StackKlasse
template<int size, class T>
class StackSpeicher
{
  public:
	StackSpeicher();
	void push (const T& e);
	bool pop (T& e);
	void sort(int start, int ende);

  private:
	T space[size];
	int index;
};

//////////////////////////////////////////////////////////////////////////////
////////////////// Funktions-Implementierung /////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
// Konstruktor
template <int size, class T>
StackSpeicher <size, T> :: StackSpeicher():index(-1)
{
}


//////////////////////////////////////////////////////////////////////////////
// Einf�gen
template <int size, class T>
void StackSpeicher <size, T>::push(const T& e)
{
	if (index < (size-1))
	{
		index += 1;
		space[index] = e;
	}
}

//////////////////////////////////////////////////////////////////////////////
// Entnehmen
template<int size, class T>
bool StackSpeicher<size, T>::pop(T& e)
{
	if (index >= 0)
	{
		e = space[index];
		index -= 1;
		return true;
	}
	else {
		return false;
	}
}

//////////////////////////////////////////////////////////////////////////////
// Sortieren mit Quicksort
template<int size, class T>
void StackSpeicher<size, T>::sort(int start = 0, int ende = -1)
{
	if (ende < 0) /* only for first invocation */
	{
		ende = index;
	}

	int i = start, j = ende - 1, trenn = ende;

	if (start >= ende) return; /* Abbruchkriterium für Rekursion */

	while (true) {
		while ((!(space[i] < space[trenn]) || space[i] == space[trenn]) && i < ende) i++;
		while ((space[j] < space[trenn] || space[j] == space[trenn]) && j >= start) j--;

		if (i >= j)
		{
			break;
		}
		else
		{
			/* swap: i <-> j */
			T tmp = space[i];
			space[i] = space[j];
			space[j] = tmp;
		}
	}

	/* swap: i <-> trenn */
	T tmp = space[trenn];
	space[trenn] = space[i];
	space[i] = tmp;

	sort(start, i-1);
	sort(i+1, ende);
}

#endif /*STACKSPEICHER_H_*/
