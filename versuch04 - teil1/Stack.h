/**
 * Praktikum Informatik 1
 * Versuch 4.1: Dynamische Datenstrukturen

 * Datei:  Stack.h
 * Inhalt: Stack mit Push-, Pop- und Ausgabe-Funktion
 */

#ifndef STACK_H_
#define STACK_H_

/* includes */
#include <iostream>
#include <string>
#include "Student.h"

using namespace std;


/**
 * \brief Stack ADT to store Students
 */
struct Stack
{
	/**
	 * \brief Constructor
	 *
	 * Initialize list pointers
	 */
	Stack();

	/**
	 * \brief Prints stack as list on screen
	 */
	void ausgabe();

	/**
	 * \brief Add Student to stack
	 */
	void push(const Student& stud);

	/**
	 * \brief Pops Student from stack
	 */
	bool pop(Student& stud);

	/**
	 * /brief Stack Element
	 */
	struct ListElem
	{
		/**
		 * \brief Contains data of the Stack Element
		 */
		Student data;

		/**
		 * \brief Pointer to next Pointer Element
		 *
		 * Can be NULL to identify the stack end
		 */
		ListElem* next;
	};

	/**
	 * \brief Pointer to first element in stack
	 */
	ListElem* head;

	/**
	 * \brief Pointer to last element in stack
	 */
	ListElem* tail;
};

#endif /*STACK_H_*/
