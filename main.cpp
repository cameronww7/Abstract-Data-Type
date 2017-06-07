/*************************************************************************
 * AUTHOR        : Cameron Walters
 * Assignment 	 : Project 5 Linked Lists
 * Class         : CS 301
 ************************************************************************/


#include "header.h"
#include "NodeType.h"
#include "List.h"


/************************************************************************
 *
 * _______________________________________________________________________
 *
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *
 * POST-CONDITIONS
 *
 ************************************************************************/
int main()
{
	List list;   //First node in list
	int  option; //Users menu choice
	int  value;  //value to be stored

	option = NumberError("\n\t1 for Insert\n"
						   "\t2 for Delete\n"
						   "\t3 for Go to Start\n"
						   "\t4 for Go to Next\n"
						   "\t5 for Current Position\n"
						   "\t6 for Current Item Value\n"
						   "\t7 for Print list\n"
						   "\t0 for Quit\n"
						   "\tEnter your Choice : ",
								  0, 7);

	while(option != 0)
	{
		switch(option)
		{
			// Adds a new node to the list
			case 1 : value = NumberError("\tEnter any Integer "
										   "(between 0-1000): ",
													 0, 1000);
					    list.insert(value);
				break;
			// Deletes Either the entire list or the current position
			case 2 : if(!list.isEmpty())
					 {
						 DeletePrompt(list);
					 }
				break;
			// Makes current inside the list return to the start
			case 3 : list.goToStart();
				break;
			// Makes Current inside the list move to the next node
			case 4 : list.goToNext();
				break;
			// Says what the current Position in the list
			case 5 : cout << "\n\tThe Current Position is "
					      << list.currentPosition() << endl;
				break;
			// Says the current value of current
			case 6 : cout << "\n\tThe Current Position's Value is "
					      << list.CurrentItem() << endl;
				break;
			// Prints the entire list for the user
			case 7 : cout << "\n\tPrinting List\n";
					 if(!list.isEmpty())
					 {
						PrintListInMain(list);
					 }
				break;
		}

		option = NumberError("\n\t1 for Insert\n"
							   "\t2 for Delete\n"
							   "\t3 for Go to Start\n"
							   "\t4 for Go to Next\n"
							   "\t5 for Current Position\n"
							   "\t6 for Current Item Value\n"
							   "\t7 for Print list\n"
							   "\t0 for Quit\n"
							   "\tEnter your Choice : ",
									  0, 7);
	}


	cout << "\n\nThank You, and Have a Wonderful Day";

	return 0;
}

void DeletePrompt(List &list)
{
	int option;

	cout << "\n\tCurrent Position :  " << list.currentPosition()
		 << " | Value of : " << list.CurrentItem();

	option = NumberError("\n\t1 for Make List Empty\n"
						   "\t2 for Delete Current Item\n"
						   "\tEnter your Choice : ",
										1, 2);
	switch(option)
	{
		//
		case 1 : list.makeEmpty();
			break;
		//
		case 2 : list.deleteCurrentItem();
			break;
	}
}

void PrintListInMain(List &list)
{
	int oldPosition;

	oldPosition = list.currentPosition();

	list.goToStart();

	while(!list.isAtEnd())
	{
		 cout << "\n\tIndex " << list.currentPosition() << " : "
			  << list.CurrentItem();
		 list.goToNext();
	}
	cout << endl;

	list.goToStart();

	while(oldPosition != list.currentPosition())
	{
		list.goToNext();
	}

}




/************************************************************************
 *  int NumberError
 * _______________________________________________________________________
 * This function outputs the menu and tracks if the user inputs an
 *	invaild character or number within the range that was passed.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		MENU_FORMAT : menu format needs to be predetermined
 *		IN_MIN 		: minimum input option needs to be predetermined
 *		IN_MAX		: maximum input option needs to be predetermined
 * POST-CONDITIONS
 * 		Returns a valid user choice (option) to the calling function
 ************************************************************************/
int NumberError(const string MENU_FORMAT,	// IN & OUT		- output string
		 	 	const int IN_MIN,			// IN & OUT		- minimum option
		 	 	const int IN_MAX)			// IN & OUT		- maximum option
{
	bool someBool;					// PROCESSING	- determines whether
									// 				  the menu is output
	int option;						// IN & OUT		- user input choice

	do
	{
		someBool = false;

		// OUTPUT - the menu
		cout << MENU_FORMAT;

		/*****************************************************************
		 * This is a check for the user's input. It will first check
		 * 	if the user has put in a vaild number, if invaild it will
		 *	clear the input then reoutput the menu until and do the
		 *	check's until the user puts in a vaild entry.
		 *****************************************************************/
		if(!(cin >> option))
		{
			cout << "\n**** Please input a NUMBER between " << IN_MIN
				 << " and " << IN_MAX << " ****";
			cin.clear();

			someBool  = true;
			cout << endl << endl;
		}
		else if (option > IN_MAX || option < IN_MIN)
		{
			cout << endl;
			cout << "**** The number " << option << " is an invalid "
					"entry     ****\n";
			cout << "**** Please input a number between "
				 << IN_MIN << " and " << IN_MAX << " ****\n";
			cout << endl;
			someBool = true;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}while(someBool);

	return option;
}


