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
#define NUMCHARS 8

//ofstream outputfile;


//return 1 if pw is found, 0 otherwise
char* tryWords(char* pwd, unsigned char hash[NUMCHARS]){

	//outputfile.open ("Passwords.txt");
	//pwd = "";

	char* localpwd= (char*) malloc(100);
	strcpy(localpwd, "");

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
			strcpy(localpwd, line.c_str());
			cout << "result = " << result << endl;

			cout << "localpwd before returning = " << localpwd << endl;

			//outputfile << ":" << ":" << localpwd << "\n";

			return localpwd;
			//return returnValue;
		}


		cout << "localpwd before returning = " << localpwd << endl;
		//outputfile << ":" << ":" << localpwd << "\n";
	}
	else cout << "Unable to open file";

	//pwd = line;


	return localpwd;
	//return returnValue;

	//
//	cout << "matched? = " << result << endl;

}


