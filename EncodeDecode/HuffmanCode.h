// Michael Smith x00107586
//Adam Flood x00110480
#pragma once
#include "HuffmanNode.h"
#include <map>
#include <queue>

using namespace std;

class HuffmanCode
{
private:
	int padding;
	char c;
	string code;
	map<char, int> frequency;	// Map that will store the letter and frequency
	map<char, string> huffmanMap;	// Map containing the Huffman codes for each letter
	map<char, int>::iterator it;
	//	Comparing the nodes so that they go into the priority queue with the min first
	//	http://stackoverflow.com/questions/15646451/stl-priority-queue-and-overloading-with-pointers
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, NodeComparison> queue;	// Creating a priority queue of nodes

	void huffmanEncoding(HuffmanNode *, string);
	HuffmanNode *root = nullptr;

public:
	void readFile();
	void writeToFile(string textInput, string fileToWrite);
	void getFrequencyTable();
	void displayHuffmanTable();
	void createPriorityQueue();
	void encode();
	void decode();
};