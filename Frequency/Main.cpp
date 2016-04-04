// Michael Smith x00107586

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main()
{
	char nextChar;
	int charCount = 0;
	map<char, int> frequency;
	map<char, int>::iterator it;
	
	ifstream infile;
	infile.open("Text.txt");

	while (!infile.eof())
	{
		infile.get(nextChar);
		frequency.find(nextChar);
		
		if (nextChar)
		{
			frequency[nextChar]++;
		}
		else
		{
			frequency[nextChar] = 1;
		}
		/*cout << nextChar << " : " << frequency[nextChar] << endl;*/
	}

	cout << "Map Size: " << frequency.size() << endl << endl;

	cout << "Frequency Table" << endl;
	cout << "Letter" << "   " << "Frequency" << endl;
	cout << "------" << "   " << "---------";
	for (it = frequency.begin();it != frequency.end();it++)
	{
		cout << "   " << it->first << "   ->   " << it->second << endl;
	}
	// use frequency.clear() to empty the map
	
	infile.close();

	system("pause");
	return 0;
}