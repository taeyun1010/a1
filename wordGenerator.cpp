//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//#include <openssl/evp.h>
//#include <fstream>
//#include <string.h>
//#include <mutex>
#include "wordGenerator.h"
//#include <thread>
using namespace std;

// if this number of chars of hash are equal ( 2chars = 1byte), assume whole hash are equal
#define NUMCHARS 16

//return 1 if pw is found, 0 otherwise
int tryWords(char* pwd, unsigned char hash[NUMCHARS]){

	//pwd = "";

	int returnValue = 0;



	//const char *c = new char[100];

	int result = 0;

	//open dictionary
	string line;
	ifstream myfile ("dictionaries/passwords.txt");
	if (myfile.is_open())
	{
		int index = 0;
		size_t pos = 0;
		string token;
		string number;
		string username;
		//unsigned char hash[NUMBYTES];

		//cout << "hash[0] = " << hash[0] << endl;

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

		if (returnValue == 1){

			strcpy(pwd, line.c_str());
			cout << "result = " << result << endl;

			cout << "pwd before returning = " << pwd << endl;


			return returnValue;
		}
	}
	else cout << "Unable to open file";

	//pwd = line;


	return returnValue;

	//
//	cout << "matched? = " << result << endl;

}


