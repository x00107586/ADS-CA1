// Michael Smith x00107586

#pragma once
#include <string>
#include <iostream>
using namespace std;

class HuffmanNode
{
	friend class HuffmanCode;
	friend class NodeComparison;

private:
	char letter;
	string code;
	int frequency;

	HuffmanNode *rPtr, *lPtr;	// Pointers to the left and right nodes
	HuffmanNode *root; // Pointer to root node

public:
	HuffmanNode();
	HuffmanNode(char letter, int freq);
	HuffmanNode(HuffmanNode *, HuffmanNode *);
	HuffmanNode(HuffmanNode *node);
	~HuffmanNode();

	void setHuffmanCode(string s);
	char getLetter();
};

//http://stackoverflow.com/questions/15646451/stl-priority-queue-and-overloading-with-pointers
class NodeComparison
{
	friend class HuffmanCode;
public:
	bool operator()(HuffmanNode *a, HuffmanNode *b);
};