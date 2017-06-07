/*************************************************************************
 * AUTHOR        : Cameron Walters
 * Assignment 	 : Project 5 Linked Lists
 * Class         : CS 301
 ************************************************************************/

#ifndef NODETYPE_H_
#define NODETYPE_H_

#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <limits>
#include <ios>
using namespace std;

class NodeType
{

public:
   NodeType( int = 0 );  		// constructor with default value for
								// info field
   int info;                 	// data
   NodeType * nextPtr; 			// pointer to next node in the list
};


#endif /* NODETYPE_H_ */
