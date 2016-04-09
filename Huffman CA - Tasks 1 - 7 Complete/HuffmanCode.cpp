// Michael Smith x00107586
// Adam Flood x00110480

#include <fstream>
#include <bitset>
#include <sstream>
#include "HuffmanCode.h"
using namespace std;


/***************************************************************************************
*    Modified:-
*	 Title: Dream.In.Code -> An In-Depth Look At Huffman Encoding
*    Author: KYA
*    Date Accessed: March 2016
*    Availability: http://www.dreamincode.net/forums/blog/324/entry-3150-an-in-depth-look-at-huffman-encoding/
*
***************************************************************************************/

void HuffmanCode::readFromFile() //simple method to read any file
{
	string line;
	ifstream infile; 
	infile.open("Text.txt");	// File to be read

	cout << "-------------------" << endl;
	cout << "   Original Text" << endl;
	cout << "-------------------" << endl;

	if (infile.is_open()) //if the file opens
	{
		while (getline(infile, line))
		{
			cout << line << endl; //print out each line in the file
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

void HuffmanCode::getHuffmanTable()
{
	huffmanEncoding(root, "");
	cout << "-------------------" << endl;
	cout << "   Huffman Table" << endl;
	cout << "-------------------" << endl;
	cout << "Letter" << "    " << "Frequency" << endl;
	cout << "------" << "    " << "---------" << endl;

	map<char, string>::iterator iteratorS; //iteratorS is an iterator that will iterate through the huffman map
	for (iteratorS = huffmanTable.begin();iteratorS != huffmanTable.end();iteratorS++) //once begin is not equal to end continue the loop
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

		cout << "Node: " << leftSide->letter << " Frequency: " << leftSide->frequency << endl << "Added together with " << endl << "Node: " << rightSide->letter << "Frequency: " << rightSide->frequency << endl << "Inserted back into Queue : " << newNode->frequency << endl << endl;
	}

	root = queue.top();		// Set the root node created in HuffmanCode.h as the root node of the tree
	cout << "Root Node Total: " << queue.top()->letter << " " << queue.top()->frequency << endl << endl;	// The total number of the frequencies added together in the final Huffman tree
	queue.pop();	// Remove the tree from the queue
}

void HuffmanCode::huffmanEncoding(HuffmanNode* root, string code)
{
	if (root == NULL)	// If the root is null the tree is empty.
	{
		cout << "There is no tree" << endl;
	}
	else if (root->lPtr == NULL)	// If the root node lptr is NULL
	{
		root->setHuffmanCode(code);	// Call the setter and set the root node to the code entered
		huffmanTable.insert(pair<char, string>(root->letter, code));	//inserting a pair into the huffmanMap that contains a letter which is the root and the code.
	}
	else
	{
		huffmanEncoding(root->lPtr, code + "0");	// If using the left pointer add a 0
		huffmanEncoding(root->rPtr, code + "1");	// If using the right pointer add a 1
	}
}

void HuffmanCode::encode()
{
	string file;

	fstream infile;
	infile.open("Text.txt");

	if (infile)
	{
	getline(infile, file);	// Retrieve each line from the file and store in the string "file"
	}

	for (int i = 0;i < file.size();i++)
	{
		encodedText += huffmanTable.find(file[i])->second;	// Read the huffmanMap and find the value of either 0 or 1 for each letter and store it all in a string code;
	}

	writeToFile(encodedText, "Encoded Text.txt");	//calling previously defined writeToFile method to write the encoded text to "Huffman Code.txt"
	
	cout << "-------------------" << endl;
	cout << "   Encoded Text" << endl;
	cout << "-------------------" << endl;
	cout << encodedText << endl;	// Outputting the string containing the encoded text
}

void HuffmanCode::decode()
{
	string file;
	string originalText;
	int size = 0;
	HuffmanNode* nodePtr = root;	// Creating a node called nodePtr and making it the root

	fstream infile;
	infile.open("Encoded Text.txt");

	if (infile)	//if infile opens
	{
		getline(infile, file);	//get each line in the file
	}

	for (int i = 0; i != file.size();i++)
	{
		if (file[i] == '0')	// If the code in the file is a 0
		{
			nodePtr = nodePtr->lPtr;	// If its a 0 the nodePtr will go left
			size++;
		}
		else
		{
			nodePtr = nodePtr->rPtr;	// It must be a 1 so the nodePtr will go right
			size++;
		}

		if (nodePtr->lPtr == NULL && nodePtr->rPtr == NULL)	// If either node points to NULL the below code is executed
		{
			originalText += nodePtr->letter;	// Assign the current letter to the originalText string variable
			nodePtr = root;	// Make the node pointer point back to the root
		}
	}
	cout << "Size of encoded text: " << size << endl;

	writeToFile(originalText, "Decoded Text.txt");	// Using writeToFile method to write the string originalText to a txt file called "Decoded Huffman.txt"

	cout << endl;
	cout << "-------------------" << endl;
	cout << "   Decoded Text" << endl;
	cout << "-------------------" << endl;
	cout << originalText << endl << endl;
}

void HuffmanCode::compressToASCII()
{
	cout << "---------------------------" << endl;
	cout << "Huffman Compressed to ASCII" << endl;
	cout << "---------------------------" << endl;

	while (encodedText.size() % 8 != 0)	// While the size of the encoded text string mod 8 is not 0,i.e the number of bits is not divisible by 8 without leaving any bits.
	{
		encodedText.append("0");	// Add extra 0s onto the encoded text until divisible by 8 without any remaining bits 
		addedZeros++;	// Increase the integer addedZeros
	}

	string asciiSymbols;	// Create a string to hold the ASCII symbols
	
	// Found out about bitset<8> from the following site 
	/***************************************************************************************
	*    Title: Is it possible to convert bitset<8> to char in c++?
	*    Author: dirkgently
	*    Date: April 2016
	*    Availability: http://stackoverflow.com/questions/11068204/is-it-possible-to-convert-bitset8-to-char-in-c
	*
	***************************************************************************************/

	// and found more information at 
	/***************************************************************************************
	*    Title: bitset - C++ Reference
	*    Author: Cplusplus.com
	*    Date: April 2016
	*    Availability: http://www.cplusplus.com/reference/bitset/bitset/
	*
	***************************************************************************************/

	bitset<8> byte;		// Store bits of 8 into a variable called byte


	/***************************************************************************************
	*    Author: George, T
	*    Date: April 2016
	*    George informed us about stringstream which enables us to treat a string like a stream
	*    This allows us to recieve an unknown number of bytes
	***************************************************************************************/

	stringstream stream(encodedText);	// Creates a stringstream variable of the encoded text
	char character;
	int n = 0;

	cout << "ASCII Symbol" << "         " << "Huffman Code" << endl;
	cout << "------------" << "         " << "------------" << endl;

	while (!stream.eof())	// While not at the end of the file
	{
		stream >> byte;		// The stream will take in the "byte"

		// http://www.cplusplus.com/reference/bitset/bitset/to_ulong/
		character = char(byte.to_ulong());	// The byte will then be converted to an integer the same size as the bitset and then be converted to a char and stored in character variable
		asciiSymbols += character;	// Add the characters to the string

		cout << "     " << character << "        -->      " << encodedText.substr(n, 8) << endl;
		n += 8;	// Move to the next block of 8	
	}
	asciiSymbols.pop_back();	// Gets rid of the extra 0s at the end of the file

	cout << "---------------" << endl;
	cout << "Compressed Text" << endl;
	cout << "---------------" << endl;
	
	cout << asciiSymbols << endl;
	cout << "Size of compressed text: " << asciiSymbols.size() << endl << endl;

	writeToFile(asciiSymbols, "Compressed Text.txt");
}

void HuffmanCode::decompressASCII()
{
	fstream infile;
	infile.open("Compressed Text.txt");
	string compressed;

	bitset<8> byte;
	string decompressed;

	if (infile)	//if infile opens
	{
		getline(infile, compressed);	//get each line in the file
	}

	for (int i = 0;i < compressed.length();i++)
	{
		byte = compressed[i];	// Assigning the int at i to the bitset byte
		decompressed += byte.to_string();	// Converting the byte into a string and storing it in the secompressed string
	}

	cout << "------------------------------" << endl;
	cout << "Converted back to Huffman code" << endl;
	cout << "------------------------------" << endl;
	for (int i = 0;i < decompressed.length();i += 64)
	{
		cout << " " << decompressed.substr(i, 64) << endl;
	}

	cout << "-------------------------------" << endl;
	cout << "Converted back to original text" << endl;
	cout << "-------------------------------" << endl;

	cout << decodeFile(decompressed) << endl;	// Call to a method that reads in a string and decodes it
}

string HuffmanCode::decodeFile(string filename)
{
	string originalText; // String to store the text when it has been decoded
	HuffmanNode* nodePtr = root;

	for (int i = 0; i != filename.size() - addedZeros; i++)
	{
		if (filename[i] == '0')	// If the value at position i of the file is a 0
		{ 
			nodePtr = nodePtr->lPtr;	// nodePtr will go to the left
		}
		else 
		{ 
			nodePtr = nodePtr->rPtr;	// If its not 0 it must be 1 so the nodePtr will go to the right
		}
		
		if (nodePtr->lPtr == NULL && nodePtr->rPtr == NULL)
		{
			originalText += nodePtr->letter;	// Add the letter to the string originalText
			nodePtr = root;		// Set the nodePtr back to root
		}
	}
	return originalText;	// Return the decoded text
}
