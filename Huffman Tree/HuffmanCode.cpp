// Michael Smith x00107586

#include <fstream>
#include "HuffmanCode.h"
using namespace std;

void HuffmanCode::huffmanEncoding(HuffmanNode* root, string code)
{
	if (root == NULL)
	{
		cout << "Empty tree" << endl;
	}
	else if (root->lPtr == NULL)
	{
		root->setHuffmanCode(code);
		huffmanMap.insert(pair<char, string>(root->letter, code));
	}
	else
	{
		huffmanEncoding(root->lPtr, code + "0");
		huffmanEncoding(root->rPtr, code + "1");
	}
}


//void HuffmanCode::readFromFile()
//{
//	char c;
//	fstream infile("Text.txt", fstream::in);
//	// Do not skip whitespaces
//	while (infile >> noskipws >> c)
//	{
//		cout << c;
//	}
//}


void HuffmanCode::getFrequencyTable()
{
	ifstream infile("Text.txt");
	string content((istreambuf_iterator<char>(infile)), (istreambuf_iterator<char>()));

	for (size_t i = 0; i < content.length(); i++)
	{
		char c = content.at(i);

		if (frequency.find(content.at(i)) == frequency.end()) 
		{
			frequency.insert(pair<char, int>(c, 1));
		}
		else 
		{
			frequency[c]++;
		}
	}

	cout << "-------------------" << endl;
	cout << "  Frequency Table" << endl;
	cout << "-------------------" << endl;
	cout << "Letter" << "   " << "Frequency" << endl;
	cout << "------" << "   " << "---------" << endl;
	for (it = frequency.begin();it != frequency.end();it++)
	{
		cout << "   " << it->first << "   ->   " << it->second << endl;
	}
	cout << endl;
	//// use frequency.clear() to empty the map

	infile.close();
}


void HuffmanCode::createPriorityQueue()
{
	// Fill priority_queue with elements from frequency map
	for (it = frequency.begin(); it != frequency.end(); it++)
	{
		// Use push to add a new node containing the letter and its frequency to the queue
		queue.push(new HuffmanNode(it->first, it->second));
	}
	// Once the Queue is filled we will now build the Huffman tree from the queue.
	// While there is more than one element in the priority queue
	cout << "-------------------" << endl;
	cout << "  Priority Queue" << endl;
	cout << "-------------------" << endl;
	while (queue.size() != 1)	// Could be changed!!
	{
		HuffmanNode *leftSide = new HuffmanNode(queue.top());	 //		Create a new node containing the element in the top of the queue 
		queue.pop();	 // Remove the element from the top of the queue 

		HuffmanNode *rightSide = new HuffmanNode(queue.top());	//	Create a new node containing the element in the top of the queue
		queue.pop();	// Remove the element from the top of the queue

		HuffmanNode *newNode = new HuffmanNode(leftSide, rightSide);	// Create a new node and add the 2 nodes from the left side and right side
		queue.push(newNode);	 // Insert the new element back into the queue, the frequencies of the 2 nodes will be added together and the new node will be pushed back into the queue. 
		//	The process of popping and then pushing the nodes will continue as long as the while loop contains more than one node in the queue
		//	Once only one node remains program will exit the while loop
		
		cout << "Node: " << leftSide->letter << endl << "Frequency: " << leftSide->frequency << endl << "Added together with " << endl <<"Node: " << rightSide->letter << endl << "Frequency: " << rightSide->frequency << endl << "Comes to: " << newNode->frequency << endl << endl;
	}
	
	root = queue.top();		// Set the root node created in HuffmanCode.h as the root node of the tree
	cout << "Root Node Total: " << queue.top()->letter << " " << queue.top()->frequency << endl << endl;	// The total number of the frequencies added together in the final Huffman tree
	queue.pop();	// Remove the tree from the queue
}

void HuffmanCode::displayHuffmanTable()
{
	huffmanEncoding(root, "");
	cout << "-------------------" << endl;
	cout << "   Huffman Table" << endl;
	cout << "-------------------" << endl;
	cout << "Letter" << "    " << "Frequency" << endl;
	cout << "------" << "    " << "---------" << endl;
	map<char, string>::iterator iteratorS;
	for (iteratorS = huffmanMap.begin();iteratorS != huffmanMap.end();iteratorS++)
	{
		cout << "   " << iteratorS->first << "   ->   " << iteratorS->second << endl;
	}
}