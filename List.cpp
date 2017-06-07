/*************************************************************************
 * AUTHOR        : Cameron Walters
 * Assignment 	 : Project 5 Linked Lists
 * Class         : CS 301
 ************************************************************************/


#include "List.h"

List::List()
{
	head     = NULL;
	current  = NULL;
	previous = NULL;
	position = 1;
}

List::~List()
{
	makeEmpty();
}

bool List::isEmpty()
{
	bool empty = false;

	if(head == NULL)
	{
		cout << "\n\t>> List is Empty << \n";
		empty = true;
	}

	return empty;
}

bool List::isAtEnd()
{
	bool resault = false;

	if(current == NULL)
	{
		resault = true;
	}

	return resault;
}

void List::makeEmpty ()
{
	if(!isEmpty())
	{
		while(head != NULL)
		{
			current = head;
			head    = head->nextPtr;
			cout << "\n\tDeleting -> " << current->info;
			delete current;
		}
		cout << endl;

		head     = NULL;
		current  = NULL;
		previous = NULL;
		position = 1;
	}

}

void List::goToStart()
{
	if(!isEmpty())
	{
		current  = head;
		previous = NULL;
		position = 1;
	}
}

void List::goToNext()
{
	if(!isEmpty() && !isAtEnd())
	{
			previous = current;
			current  = current->nextPtr;
			position++;
	}
}

void List::insert(ItemType InNewItem)
{
	NodeType * newItem;

	newItem = new NodeType;

	newItem->info    = InNewItem;

	if(current == head)
	{
		newItem->nextPtr = head;
		head     = newItem;
		current  = head;
		previous = NULL;
	}
	else
	{
		newItem->nextPtr  = current;
		previous->nextPtr = newItem;
		current = newItem;
	}
}

void List::deleteCurrentItem()
{

	if(current == head)
	{
		head = head->nextPtr;
		cout << "\n\tDeleting -> " << current->info << endl;
		delete current;
		current = head;
	}
	else if(!isAtEnd())
	{
		NodeType * removePtr;

		removePtr = current;
		previous->nextPtr = current->nextPtr;
		current = current->nextPtr;

		cout << "\n\tDeleting -> " << removePtr->info << endl;
		delete removePtr;
	}
}

int  List::currentPosition()
{
	return position;
}

ItemType List::CurrentItem()
{
	if(!isEmpty() && !isAtEnd())
	{
		return current->info;
	}
	else
	{
		return -9999;
	}
}

void List::PrintList()
{
	NodeType *curPtr; //A pointer pointing at something
	int       index = 0;

	curPtr = head;

	//prints the list from head to NULL
	cout << "\n\tPrinting the List \n";
	while(curPtr != NULL)
	{
		cout << "\tIndex " << ++index << " : " <<  curPtr->info << endl;
		curPtr = curPtr->nextPtr;
	}
}
