// Michael Smith x00107586

#include "HuffmanNode.h"
using namespace std;

void HuffmanNode::setHuffmanCode(string s)
{
	code = s;
}

char HuffmanNode::getLetter()
{
	return letter;
}

HuffmanNode::HuffmanNode()
{
	letter = ' ';
	frequency = 0;
	lPtr = rPtr = NULL;
	root = NULL;
}

HuffmanNode::HuffmanNode(char l, int f)
{
	letter = l;
	frequency = f;
	lPtr = rPtr = NULL;
}

HuffmanNode::HuffmanNode(HuffmanNode *left, HuffmanNode *right)
{
	letter = NULL;
	lPtr = left;
	rPtr = right;
	frequency = left->frequency + right->frequency;
}

HuffmanNode::HuffmanNode(HuffmanNode * node)
{
	letter = node->letter;
	frequency = node->frequency;

	if (node->lPtr != nullptr)
	{
		lPtr = node->lPtr;
	}
	if (node->rPtr != nullptr)
	{
		rPtr = node->rPtr;
	}
}

HuffmanNode::~HuffmanNode()
{
	while (root != NULL)
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
}

bool NodeComparison::operator()(HuffmanNode *a, HuffmanNode *b)
{
	if (a->frequency > b->frequency)
	{
		return true;
	}
	else {
		return false;
	}
}