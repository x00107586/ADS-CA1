// Michael Smith x00107586
// Adam Flood x00110480

#include "HuffmanCode.h"

int main()
{
	HuffmanCode huffmanCA;

	huffmanCA.readFromFile();
	huffmanCA.getFrequencyTable();
	huffmanCA.createPriorityQueue();
	huffmanCA.getHuffmanTable();
	huffmanCA.encode();
	huffmanCA.decode();
	huffmanCA.compressToASCII();
	huffmanCA.decompressASCII();

	system("pause");
	return 0;
}