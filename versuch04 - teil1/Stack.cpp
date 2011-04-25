/**
 * Praktikum Informatik 1
 * Versuch 4.1: Dynamische Datenstrukturen

 * Datei:  Stack.cpp
 * Inhalt: Stack mit Push-, Pop- und Ausgabe-Funktion
 */

#include "Stack.h"

Stack::Stack()
{
	head = NULL;
	tail = NULL;
}

void Stack::push(const Student& stud)
{
	ListElem* newStackElem = new ListElem;
	newStackElem->data = stud;

	if (tail == NULL)
	{
		newStackElem->next = NULL;
		tail = newStackElem;
	}
	else
	{
		newStackElem->next = head;
	}

	head = newStackElem;
}

bool Stack::pop(Student& stud)
{
	if (head == NULL) /* stack is empty */
	{
		return false;
	}
	else if (head == tail)
	{
		stud = head->data;
		delete head;

		head = NULL;
		tail = NULL;
	}
	else
	{
		/* fehlerhafter Teil:
		 * Ist der Stack nicht leer und enthält mehr als ein Element,
		 * muss das Element von dem Listenanfang enfernt werden.
		 * Dieser Abschnitt entfernt das Element vom Listenende! */

		/*ListElem* listElementPtr = head;

		while (listElementPtr->next != tail) // looking for new list tail
		{
			listElementPtr = listElementPtr->next;
		}

		stud = tail->data;
		delete tail;

		tail = listElementPtr;
		listElementPtr->next = NULL;*/

		/* korrigierte Version:
		 * Hier wird das Element vom Stackanfang entfernt*/
		ListElem* listElementPtr = head;
		stud = listElementPtr->data;
		head = listElementPtr->next;

		delete listElementPtr;
	}

	return true;
}

void Stack::ausgabe()
{
	if (head == NULL)
		cout << "Der Stack ist leer." << endl;
	else
	{
		ListElem* listElementPtr = head;
		while (listElementPtr != NULL)
		{
			cout << listElementPtr->data.name << ", MatNr. " << listElementPtr->data.matNr << " geb. am "
					<< listElementPtr->data.gebDatum << " wohnhaft in " << listElementPtr->data.adresse << endl;

			listElementPtr = listElementPtr->next;
		}
	}
}

