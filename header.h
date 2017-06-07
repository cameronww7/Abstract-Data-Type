/*************************************************************************
 * AUTHOR        : Cameron Walters
 * Assignment 	 : Project 5 Linked Lists
 * Class         : CS 301
 ************************************************************************/

#ifndef HEADER_H_
#define HEADER_H_

#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <limits>
#include <ios>

#include "List.h"

using namespace std;

int NumberError(const string MENU_FORMAT,	// IN & OUT		- output string
		 	 	const int IN_MIN,			// IN & OUT		- minimum option
		 	 	const int IN_MAX);			// IN & OUT		- maximum option
void DeletePrompt(List &list);
void PrintListInMain(List &list);

#endif /* HEADER_H_ */
