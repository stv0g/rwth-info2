//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 4.2: Dynamische Datenstrukturen
//
// Datei:  List.cpp
// Inhalt: Liste mit Methoden
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
///////////////////////////////// INCLUDES ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#include "List.h"

//////////////////////////////////////////////////////////////////////////////
///////////////////////// Funktions-Implementierung //////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// Konstruktor mit Zeigerinitialisierung
List::List()
{
	head = NULL;
	tail = NULL;
}

//////////////////////////////////////////////////////////////////////////////
// vorne an head anhängen
void List::enqueuehead(const Student& stud)
{
	ListElem* neu = new ListElem;
	neu->data = stud;
	neu->prev = NULL;
	if (tail == NULL) // Liste leer??
	{
		neu->next = NULL;
		tail = neu;
	}
	else 
	{
		neu->next = head;
		head->prev = neu;
	}

	head = neu;
}

//////////////////////////////////////////////////////////////////////////////
// hinten an tail anhängen
void List::enqueuetail(const Student& stud)
{
	ListElem* neu = new ListElem;
	neu->data = stud;
	neu->next = NULL;
	if (tail == NULL) // Liste leer??
	{
		neu->next = NULL;
		head = neu;
	}
	else
	{
		neu->prev = tail;
		tail->next = neu;
	}

	tail = neu;
}

bool List::remove(int matNr) {
	ListElem* cursor = head;
	while (cursor != NULL)
	{
		if (cursor->data.matNr == matNr) {
			if(cursor == head)
			{
				head = head->next;
				head->prev = NULL;
			}
			else if (cursor == tail)
			{
				tail = tail->prev;
				tail->next = NULL;
			}
			else {
				cursor->prev->next = cursor->next;
				cursor->next->prev = cursor->prev;
			}

			delete cursor;
			return true;
		}

		cursor = cursor->next;
	}

	return false;
}

//////////////////////////////////////////////////////////////////////////////
// Element hinten abhängen
bool List::dequeue(Student& stud)
{
	ListElem* cursor = head;
	if (head == NULL)   //Liste leer??
	{
		return false;;
	}
	else if (head == tail) // Ein Element in Liste
	{
		stud = head->data;
		delete head;
		head = NULL;
		tail = NULL;
	}
	else
	{
		while(cursor->next != tail)
		{
			cursor = cursor->next;
		}
		stud = tail->data;
		tail = cursor;
		delete cursor->next;
		tail->next = NULL;
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////////
// von vorne nach hinten ausgeben
void List::ausgabevorwaerts()
{
	ListElem* cursor = head;
	while (cursor != NULL)
	{
		cout << cursor->data.name << ", MatNr. " << cursor->data.matNr << " geb. am " 
			 << cursor->data.gebDatum << " wohnhaft in " << cursor->data.adresse << endl;
		cursor=cursor->next;
	}
}

//////////////////////////////////////////////////////////////////////////////
// von hinten nach vorne ausgeben
void List::ausgaberueckwaerts()
{
	ListElem* cursor = tail;
	while (cursor != NULL)
	{
		cout << cursor->data.name << ", MatNr. " << cursor->data.matNr << " geb. am "
			 << cursor->data.gebDatum << " wohnhaft in " << cursor->data.adresse << endl;
		cursor = cursor->prev;
	}
}

