//Michael Smith x00107586
//Adam Flood x00110480

#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;
class MyTransform {
private:
	int shift;
public:
	MyTransform(int s) : shift(s) { }


	/***************************************************************************************
	*    Title: <Rosetta Code Cryptography>
	*    Author: <rosetta Code>
	*    Date: <04/04/2016>
	*    Code version: <2.0 c++>
	*    Availability: <http://www.rosettacode.org/wiki/Caesar_cipher#C.2B.2B>
	*
	*************************************************************/



	char operator( )(char c) {
		if (isspace(c))
			return ' '; //if character is a space , return space character.
		else {
			static string letters("abcdefghijklmnopqrstuvwxyz"); //Letters in the alphabet
			string::size_type found = letters.find(tolower(c)); //storing letter to find in found, tolower makes all chars lower case
			int shiftedpos = (static_cast<int>(found) + shift) % 26; //cast found to an int and adding shift to it.
			if (shiftedpos < 0) //in case of decryption possibly. if  the shifted postion is less than 0
				shiftedpos = 26 + shiftedpos;
			char shifted = letters[shiftedpos]; //the letter at the shifted position is assigned to shifted character
			return shifted;
		}
	}
};