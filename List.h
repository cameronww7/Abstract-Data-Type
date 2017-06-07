/*************************************************************************
 * AUTHOR        : Cameron Walters
 * Assignment 	 : Project 5 Linked Lists
 * Class         : CS 301
 ************************************************************************/

#ifndef LIST_H_
#define LIST_H_

#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <limits>
#include <ios>

using namespace std;

#include "NodeType.h"

typedef int ItemType;

class List
{
public:
	 List();
	 ~List();
	 bool isEmpty();
	 bool isAtEnd();
	 void makeEmpty();
	 void goToStart();
	 void goToNext();
	 void insert(ItemType InNewItem);
	 void deleteCurrentItem();
	 int  currentPosition();
	 ItemType CurrentItem();

	 void PrintList();


private:
		NodeType * head;
		NodeType * current;
		NodeType * previous;
		int position;
};


#endif /* LIST_H_ */
