// Michael Smith x00107586
//Adam Flood x00110480
#include "HuffmanCode.h"

int main()
{
	HuffmanCode test;

	test.readFile();
	test.getFrequencyTable();
	test.createPriorityQueue();
	test.displayHuffmanTable();
	test.encode();
	test.decode();

	system("pause");
	return 0;
}