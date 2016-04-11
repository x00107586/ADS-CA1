//Michael Smith x00107586
//Adam Flood x00110480

#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include "MyTransform.cpp"
#include <fstream>

using namespace std;
int main() {


	ifstream file("Poem.txt");
	string str;
	string file_contents;
	while (getline(file, str))
	{
		file_contents += str;
		file_contents.push_back('\n');
	}



	/***************************************************************************************
	*    Title: <Rosetta Code Cryptography>
	*    Author: <rosetta Code>
	*    Date: <04/04/2016>
	*    Code version: <2.0 c++>
	*    Availability: <http://www.rosettacode.org/wiki/Caesar_cipher#C.2B.2B>
	*
	*************************************************************/

	string input;
	input = file_contents;
	cout << "shift ?\n";
	int myshift = 0;
	cin >> myshift;
	cout << "Before encryption:\n" << input << endl;
	transform(input.begin(), input.end(), input.begin(), //using an iterator to print out the file contents.
		MyTransform(myshift)); //calling the transform method in myTransform to transform myshift.
	cout << endl;
	cout << "encrypted:\n";
	cout << input << endl;
	myshift *= -1; //decrypting again
	transform(input.begin(), input.end(), input.begin(),//using an iterator to print out the file contents.
		MyTransform(myshift));  //calling the transform method in myTransform to transform myshift.
	cout << endl;
	cout << "Decrypted again:\n";
	cout << input << endl;

	system("pause");
	return 0;
}