// Michael Smith x00107586
// Adam Flood x00110480

#pragma once
#include "HuffmanNode.h"
#include <map>
#include <queue>

using namespace std;

class HuffmanCode
{
private:
	int addedZeros;	// Integer to count the number of added 0s int the encoding	
	string encodedText;	// String to hold encoded message
	map<char, int> frequency;	// Map that will store the letter and frequency
	map<char, string> huffmanTable;	// Map containing the Huffman codes for each letter
	map<char, int>::iterator it;	// Iterator to iterate through the map


	/***************************************************************************************
	*    Title: STL priority queue and overloading with pointers
	*    Author: Andy Prowl
	*    Date: Mar 2013
	*    Code version: 1.0
	*    Availability: http://stackoverflow.com/questions/15646451/stl-priority-queue-and-overloading-with-pointers
	*
	***************************************************************************************/
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, NodeComparison> queue;	// Creating a priority queue of nodes and calling the nodeComparison class to order them by weight

	HuffmanNode *root = NULL;	// Creating a node pointer root;

public:
	void readFromFile();
	void writeToFile(string text, string file);
	void getFrequencyTable();
	void getHuffmanTable();
	void createPriorityQueue();
	void huffmanEncoding(HuffmanNode *, string);
	void encode();
	void decode();
	void compressToASCII();
	void decompressASCII();
	string decodeFile(string);
};
