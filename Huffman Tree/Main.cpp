// Michael Smith x00107586

#include "HuffmanCode.h"

int main()
{
	HuffmanCode test;

	test.getFrequencyTable();
	test.createPriorityQueue();
	test.displayHuffmanTable();

	system("pause");
	return 0;
}