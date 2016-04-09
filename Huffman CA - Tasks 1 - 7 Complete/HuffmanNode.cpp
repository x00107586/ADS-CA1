// Michael Smith x00107586
// Adam Flood x00110480


/***************************************************************************************
*    Based on:-
*	 Title: Dream.In.Code -> An In-Depth Look At Huffman Encoding
*    Author: KYA
*    Date Accessed: March 2016
*    Availability: http://www.dreamincode.net/forums/blog/324/entry-3150-an-in-depth-look-at-huffman-encoding/
*
***************************************************************************************/


#include "HuffmanNode.h"
using namespace std;

void HuffmanNode::setHuffmanCode(string s)	// Setter method to set string
{
	code = s;
}

char HuffmanNode::getLetter()	// Getter to return a char
{
	return letter;
}

HuffmanNode::HuffmanNode()	// Default Constructor
{
	letter = ' ';
	frequency = 0;
	lPtr = NULL;
	rPtr = NULL;
}

HuffmanNode::HuffmanNode(char l, int f)	// Constructor assigning variable
{
	letter = l;
	frequency = f;
	lPtr = NULL;
	rPtr = NULL;
}

HuffmanNode::HuffmanNode(HuffmanNode *left, HuffmanNode *right)	// Constructor to assign pointers and add the frequencies
{
	letter = NULL;
	lPtr = left;
	rPtr = right;
	frequency = left->frequency + right->frequency;
}

HuffmanNode::HuffmanNode(HuffmanNode * node)	// Constructor to assign current letter & frequency to the node pointer and assign it to letter & frequency variables
{
	letter = node->letter;
	frequency = node->frequency;

	if (node->lPtr != NULL)	// If lPtr is not NULL assign the node->lptr to the lptr
	{
		lPtr = node->lPtr;
	}
	if (node->rPtr != NULL)	// If rptr is not NULL assign the node->rptr to the rptr
	{
		rPtr = node->rPtr;
	}
}

HuffmanNode::~HuffmanNode()	// Deconstructor
{
		if (lPtr != NULL)
		{
			delete lPtr;
		}
		if (rPtr != NULL)
		{
			delete rPtr;
		}
}

bool NodeComparison::operator()(HuffmanNode *a, HuffmanNode *b)		// Method used to organise the priority queue
{
	if (a->frequency > b->frequency)	// If the current frequency that node a in pointing to is greater than the frequency of the node that b is pointing to return true
	{
		return true;
	}
	else 
	{
		return false;
	}
}