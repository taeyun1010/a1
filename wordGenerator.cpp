//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//#include <openssl/evp.h>
//#include <fstream>
//#include <string.h>
#include "wordGenerator.h"
//#include <thread>
using namespace std;

// if this number of chars of hash are equal ( 2chars = 1byte), assume whole hash are equal
#define NUMCHARS 16

//return 1 if pw is found, 0 otherwise
int tryWords(const char* pwd, unsigned char hash[NUMCHARS]){
	int returnValue = 0;

	int result = 0;

	//open dictionary
	string line;
	ifstream myfile ("dictionaries/english.txt");
	if (myfile.is_open())
	{
		int index = 0;
		size_t pos = 0;
		string token;
		string number;
		string username;
		//unsigned char hash[NUMBYTES];
		while (getline (myfile,line) )
		{

			result = checkIfCorrect(line.c_str(), hash);
			if (result == 1){
				returnValue = 1;
				cout << "line.c_str() = " << line.c_str() << endl;
				break;
			}
//			cout << line << endl;


		}
		myfile.close();
	}
	else cout << "Unable to open file";

	pwd = line.c_str();

	cout << "pwd before returning = " << pwd << endl;

	return returnValue;
	//
//	cout << "matched? = " << result << endl;

}
