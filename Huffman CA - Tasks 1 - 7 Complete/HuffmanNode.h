// Michael Smith x00107586
// Adam Flood x00110480

#pragma once
#include <iostream>
using namespace std;

class HuffmanNode
{
	friend class HuffmanCode;
	friend class NodeComparison;

private:
	char letter;
	int frequency;
	string code;

	HuffmanNode *rPtr, *lPtr, *root;	// Pointers to the left, right and root nodes

public:
	HuffmanNode();	// Default Constructor
	HuffmanNode(char letter, int freq);	// Constructor that takes in a char and an int
	HuffmanNode(HuffmanNode *, HuffmanNode *);	// Constructor that takes in 2 pointer to nodes
	HuffmanNode(HuffmanNode *node);	// Constructor that takes in a pointer to a node
	~HuffmanNode();	//Destructor

	void setHuffmanCode(string s);	// Setter method to take in a string
	char getLetter();	// Getter method to retrive a char
};


/***************************************************************************************
*    Title: STL priority queue and overloading with pointers
*    Author: Andy Prowl
*    Date: Mar 2013
*    Code version: 1.0
*    Availability: http://stackoverflow.com/questions/15646451/stl-priority-queue-and-overloading-with-pointers
*
***************************************************************************************/

class NodeComparison	// Class with method to compare nodes
{
	friend class HuffmanCode;
public:
	bool operator()(HuffmanNode *a, HuffmanNode *b);	// Takes in 2 pointers to be compared
};