// Michael Smith x00107586
//Adam Flood x00110480
#include <fstream>
#include <bitset>
#include <sstream>
#include "HuffmanCode.h"
using namespace std;

void HuffmanCode::readFile() //simple method to read any file
{
	string line;
	ifstream infile("Text.txt"); //file to be read

	if (infile.is_open()) //if the file opens
	{
		while (getline(infile, line))
		{
			cout << line << '\n'; //print out each line in the file
		}
		infile.close(); //close the file when no more lines are to be displayed
	}
	cout << endl;
}

void HuffmanCode::writeToFile(string text, string filename)
{
	//The below code writes to a file of our choice
	//we can pass in any text we want as the first variable 'text'
	//and for 'filename' we enter the name of the file to output the text into
	//we call this method several times within other methods to make writing to a file easier
	ofstream outputFile;
	outputFile.open(filename); //opens file we passed into the method
	outputFile << text; //passes the text into the file
	outputFile.close(); //closes the file
}

void HuffmanCode::getFrequencyTable()
{
	ifstream infile("Text.txt"); //assigning the text.txt to the variable infile.
	string content((istreambuf_iterator<char>(infile)), (istreambuf_iterator<char>())); //an iterator that gets each char in the file is stored in a string called content

	for (size_t i = 0; i < content.length(); i++)
	{
		char c = content.at(i); //storing the 'content' or value at position i and assigning it into the c variable.

		if (frequency.find(content.at(i)) == frequency.end()) //if the 'content' at position i is equal to the end of frequency enter the if statement
		{
			frequency.insert(pair<char, int>(c, 1)); //insert the pair containing c 'letter' and the value of 'frequency' 1 into the frequency map.
		}
		else
		{
			frequency[c]++; //increment frequency
		}
	}

	cout << "-------------------" << endl;
	cout << "  Frequency Table" << endl;
	cout << "-------------------" << endl;
	cout << "Letter" << "   " << "Frequency" << endl;
	cout << "------" << "   " << "---------" << endl;
	for (it = frequency.begin();it != frequency.end();it++) // frequency is a Map that will store the letter and frequency
															//once begin is not equal to end continue the loop
	{														//it is an iterator to iterate through the map
		cout << "   " << it->first << "   ->   " << it->second << endl;
	}
	cout << endl;
	//// use frequency.clear() to empty the map

	infile.close(); //closing the file
}

void HuffmanCode::displayHuffmanTable()
{
	huffmanEncoding(root, "");
	cout << "-------------------" << endl;
	cout << "   Huffman Table" << endl;
	cout << "-------------------" << endl;
	cout << "Letter" << "    " << "Frequency" << endl;
	cout << "------" << "    " << "---------" << endl;
	map<char, string>::iterator iteratorS; //iteratorS is an iterator that will iterate through the huffman map
	for (iteratorS = huffmanMap.begin();iteratorS != huffmanMap.end();iteratorS++) //once begin is not equal to end continue the loop
	{
		cout << "   " << iteratorS->first << "   ->   " << iteratorS->second << endl;
	}
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

		cout << "Node: " << leftSide->letter << endl << "Frequency: " << leftSide->frequency << endl << "Added together with " << endl << "Node: " << rightSide->letter << endl << "Frequency: " << rightSide->frequency << endl << "Comes to: " << newNode->frequency << endl << endl;
	}

	root = queue.top();		// Set the root node created in HuffmanCode.h as the root node of the tree
	cout << "Root Node Total: " << queue.top()->letter << " " << queue.top()->frequency << endl << endl;	// The total number of the frequencies added together in the final Huffman tree
	queue.pop();	// Remove the tree from the queue
}

void HuffmanCode::huffmanEncoding(HuffmanNode* root, string code)
{
	if (root == NULL) //if the root is null the tree is empty.
	{
		cout << "Empty tree" << endl;
	}
	else if (root->lPtr == NULL)
	{
		root->setHuffmanCode(code);
		huffmanMap.insert(pair<char, string>(root->letter, code)); //inserting a pair into the huffmanMap that contains a letter which is the root and the code.
	}
	else
	{
		huffmanEncoding(root->lPtr, code + "0");
		huffmanEncoding(root->rPtr, code + "1");
	}
}

void HuffmanCode::encode()
{
	fstream infile;
	infile.open("Text.txt", ios::in);
	string file;
	string info = " ";

	if (infile)
	{
	getline(infile, file);
	}

	for (unsigned i = 0;i < file.size();i++)
	{
		
		code += huffmanMap.find(file[i])->second;	// Read the huffmanMap and find the value of either 0 or 1 for each letter and store it all in a string code;
		
	}

	writeToFile(code, "Huffman Code.txt"); //calling previously defined writeToFile method to write the encoded text to "Huffman Code.txt"
	
	cout << "-------------------" << endl;
	cout << "   Encoded Text" << endl;
	cout << "-------------------" << endl;
	cout << code << endl;
}

void HuffmanCode::decode()
{
	fstream infile;
	infile.open("Huffman Code.txt", ios::in);
	string file;
	string message;
	HuffmanNode* nodePtr = root; //making the node point to the root

	if (infile) //if infile opens
	{
		getline(infile, file); //get each line in the file
	}

	for (int i = 0; i != file.size();i++)
	{
		if (file[i] == '0')
		{
			nodePtr = nodePtr->lPtr; //make node pointer point to the left
		}
		else
		{
			nodePtr = nodePtr->rPtr; //make node pointer point to the right
		}

		if (nodePtr->lPtr == NULL && nodePtr->rPtr == NULL) //if either node points to NULL the below code is executed
		{
			message += nodePtr->letter; //assign the current letter to the message string variable
			nodePtr = root; //reset the node pointer so it points back to the root
		}
	}
	cout << endl;
	cout << "-------------------" << endl;
	cout << "   Decoded Text" << endl;
	cout << "-------------------" << endl;
	cout << message << endl;

	writeToFile(message, "Decoded Huffman.txt"); //calling our writeToFile method so we can pass 'message' into the "Decoded Huffman.txt" file
}
