//============================================================================
// Name        : PasswordCrackwithMake.cpp
// Author      : kty
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//#include <openssl/evp.h>
#include <fstream>
#include <string.h>
#include <vector>
#include <ctime>
#include <map>
//#include <mutex>
//#include "wordGenerator.h"
//#include "keyboardPattern.h"
#include "HashTry.h"
//#include "hashChecker.h"
//#include <thread>

using namespace std;

enum { KEYLENGTH = 16 };

//unsigned char answer[] = "451126c581dc3c15f15a111013808610";

#define KEY_LEN      32
#define KEK_KEY_LEN  16
#define ITERATION    500

// if this number of chars of hash are equal ( 2chars = 1byte), assume whole hash are equal
#define NUMCHARS 8

string delimeter = ":";

//vector<thread> threads;

//mutex m;

ofstream outputfile;

int numfound = 0;

map<string,string> hashmap;
map<string,string>::iterator iter;

unsigned char salt_value[] = { 's', 'e', 'c', 'l', 'a', 'b' };


int retunInt(char upperChar, char lowerChar){
	int result = 0;

	switch(upperChar) {
	case 'a' :
		result = result + 160;
		break;
	case 'b' :
		result = result + 176;
		break;
	case 'c' :
		result = result + 192;
		break;
	case 'd' :
		result = result + 208;
		break;
	case 'e' :
		result = result + 224;
		break;
	case 'f' :
		result = result + 240;
		break;
	case 'A' :
		result = result + 160;
		break;
	case 'B' :
		result = result + 176;
		break;
	case 'C' :
		result = result + 192;
		break;
	case 'D' :
		result = result + 208;
		break;
	case 'E' :
		result = result + 224;
		break;
	case 'F' :
		result = result + 240;
		break;
	default :
		result = result + (upperChar - '0') * 16;
	}

	switch(lowerChar) {
		case 'a' :
			result = result + 10;
			break;
		case 'b' :
			result = result + 11;
			break;
		case 'c' :
			result = result + 12;
			break;
		case 'd' :
			result = result + 13;
			break;
		case 'e' :
			result = result + 14;
			break;
		case 'f' :
			result = result + 15;
			break;
		case 'A' :
			result = result + 10;
			break;
		case 'B' :
			result = result + 11;
			break;
		case 'C' :
			result = result + 12;
			break;
		case 'D' :
			result = result + 13;
			break;
		case 'E' :
			result = result + 14;
			break;
		case 'F' :
			result = result + 15;
			break;
		default :
			result = result + (lowerChar - '0');
	}

	return result;

}

//
////return 1 if equal, 0 otherwise
//int checkIfCorrect(const char pwd[], unsigned char answer[]) {
//
////	if (strcmp (pwd, "Qwerty1") == 0)
////		cout << pwd << endl;
//
//	int result = 1;
//	size_t i;
//	unsigned char* out;
//	out = (unsigned char *) malloc(sizeof(unsigned char) * KEK_KEY_LEN);
//	//printf("pass: %s\n", pwd);
//	//printf("ITERATION: %u\n", ITERATION);
//	//printf("salt: ");
////	for (i = 0; i < sizeof(salt_value); i++) {
////		printf("%02x", salt_value[i]);
////	}
//	//printf("\n");
//	if (PKCS5_PBKDF2_HMAC_SHA1(pwd, strlen(pwd), salt_value, sizeof(salt_value),
//			ITERATION, KEK_KEY_LEN, out) != 0) {
//	//	printf("out: ");
////		for (i = 0; i < KEK_KEY_LEN; i++) {
////			printf("%02x", out[i]);
////			if(out[i] != answer[i]){
////
////				//printf("result = ");
////				result = 0;
////				break;
////			}
////
////		}
////
////		unsigned int a = 240;
////		unsigned int b = 15;
//
////		for (int j =0; j< NUMCHARS; j++){
////			//printf("bitwise result = %02x", (out[j] >> 4));
////			printf("out[j] = %02x\n", out[j] );
////			//cout << "answer[j] = " << answer[j]<<endl;
////			//cout << "answer[j] int value = " << answer[j] - '0' << endl;
//////			cout << "out[j] = " << out[j] << endl;
////			//cout << "out[j] int value = " << (int) out[j] << endl;
////		}
//
//		for (i = 0; i < (NUMCHARS / 2); i++) {
//
//			//2*i   2*i + 1
//
//			int temp =	retunInt(answer[(2*i)], answer[(2*i + 1)]);
//
//			//cout << "answer[i] int value = " << temp<< endl;
//
//
//
//		//	printf("%02x", out[i]);
////			if(out[i] != answer[i]){
////
////				//printf("result = ");
////				result = 0;
////				break;
////			}
//
//			if(temp != (int) out[i]){
//				result = 0;
//				break;
//
//			}
//
////			if (i == ((NUMCHARS / 2) -1)){
////				cout << pwd << endl;
////
////			}
//
//		}
//
////		//
////		result = strcmp(out, answer);
////		//
//
//		//printf("\n");
//	} else {
//		fprintf(stderr, "PKCS5_PBKDF2_HMAC_SHA1 failed\n");
//	}
//	free(out);
//	//free(pwd);
//
//	return result;
//}
//
//
//
//void crack(string number, string username, unsigned char hash[NUMCHARS]){
////	m.lock();
//
//	//thread_local char pwd[100] = "";
//	char pwd[100] = "";
//
////
////				for (int i=0; i<NUMCHARS; i++){
////					cout << "hash[i] = " << hash[i] << endl;
////				}
//
//
////	lock_guard<mutex> lock(m);
//
//
////	if(tryWords(pwd, hash)){
////		//pwd = "found!";
////		cout << "cracked pw = " << pwd << endl;
////
////	}
//
//	//delete[] pwd;
//
////	ofstream myfile;
////	myfile.open ("Passwords.txt");
//
//	char* ans = tryWords(pwd, hash);
//
//	char* ans2 = tryKeyboard(hash);
//
//	//char* ans3 = tryKnownHash(hash);
//
//	//cout << "ans3 = " << ans3 << endl;
//
//	if (strcmp(ans, "") != 0)
//		outputfile << number << ":" << username << ":" << ans << "\n";
//	else
//		outputfile << number << ":" << username << ":" << ans2 << "\n";
//	//else
//	//	outputfile << number << ":" << username << ":" << ans3 << "\n";
//	//
//	free(ans);
//	free(ans2);
//	//free(ans3);
//
//	//	outputfile.close();
//
////	m.unlock();
//
//	//return pwd;
//
//}

//load maps to memory
void initialize(){
	//clock_t begin = clock();

	ifstream myfile ("dictionaries/processed_account_pw_withhash.txt");
	if (myfile.is_open())
	{
		string hashfromfile;
		//int index = 0;
		size_t pos = 0;
		string token = "";
		string pwd = "";
		string thishash = "";

		while (getline (myfile,hashfromfile) )
		{

			//index = 0;
			pos = 0;

			//hash = "";

			while ((pos = hashfromfile.find(delimeter)) != std::string::npos) {


				token = hashfromfile.substr(0, pos);
				//std::cout << token << std::endl;

				pwd = token;
				thishash = hashfromfile.substr((pos+1));


				//to get rid of the newline character at the end
				thishash = thishash.substr(0, thishash.length()-1);

				//cout << "thishash = " << thishash << endl;
				clock_t begin = clock();

				hashmap.insert(pair<string,string>(thishash,pwd));


				clock_t end = clock();
				double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

				//cout << "numfound = " << numfound << endl;
				cout << "eplased_secs = " << elapsed_secs << endl;

				//hashmap[thishash] =pwd;

				hashfromfile.erase(0, pos + delimeter.length());
				//index++;
				//cout << "doing a while loop" << endl;
			}



		}

//		for(map<string, string>::const_iterator it = hashmap.begin();it != hashmap.end(); ++it)
//		{
//		    cout << "hash =" << it->first << "!"<<  "\n";
//		    cout << "pwd =" << it->second << "!"<< "\n";
//		}

//		map<string,string>::iterator it = hashmap.find("db51d96c");
//
//		cout << "hashmap.find = " << it->second << endl;

		//cout << "hashmap.size() is " << hashmap.size() << '\n';

		myfile.close();

	}
	else cout << "Unable to open file";

//	clock_t end = clock();
//
//	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
//
//		cout << "eplased_secs = " << elapsed_secs << endl;


}

void crackUsingHashMap(string number, string username, unsigned char hash[NUMCHARS]){
//	m.lock();

	//thread_local char pwd[100] = "";
	//char pwd[100] = "";

//
//				for (int i=0; i<NUMCHARS; i++){
//					cout << "hash[i] = " << hash[i] << endl;
//				}


//	lock_guard<mutex> lock(m);


//	if(tryWords(pwd, hash)){
//		//pwd = "found!";
//		cout << "cracked pw = " << pwd << endl;
//
//	}

	//delete[] pwd;

//	ofstream myfile;
//	myfile.open ("Passwords.txt");


	char* ans3 = tryKnownHashGivenMap(hashmap, hash);


	if (strcmp(ans3, "") != 0)
			numfound++;

	outputfile << number << ":" << username << ":" << ans3 << "\n";

	free(ans3);

	//	outputfile.close();

//	m.unlock();

	//return pwd;

}


void crackUsingHashes(string number, string username, unsigned char hash[NUMCHARS]){
//	m.lock();

	//thread_local char pwd[100] = "";
	//char pwd[100] = "";

//
//				for (int i=0; i<NUMCHARS; i++){
//					cout << "hash[i] = " << hash[i] << endl;
//				}


//	lock_guard<mutex> lock(m);


//	if(tryWords(pwd, hash)){
//		//pwd = "found!";
//		cout << "cracked pw = " << pwd << endl;
//
//	}

	//delete[] pwd;

//	ofstream myfile;
//	myfile.open ("Passwords.txt");


	char* ans3 = tryKnownHash(hash);


	if (strcmp(ans3, "") != 0)
			numfound++;

	outputfile << number << ":" << username << ":" << ans3 << "\n";

	free(ans3);

	//	outputfile.close();

//	m.unlock();

	//return pwd;

}

int main(void) {

	clock_t begin = clock();

	initialize();

	//read file
	string line;
	ifstream myfile ("hashedPasswords.txt");
	outputfile.open ("Passwords.txt");
	if (myfile.is_open())
	{
		int index = 0;
		size_t pos = 0;
		string token;
		string number;
		string username;
		//unsigned char hash[NUMBYTES];

		//int k = 0;

		while (getline (myfile,line) )
		{
			index = 0;
			pos = 0;
			token = "";
			number = "";
			username = "";
			//hash = "";
			unsigned char hash[NUMCHARS];

			while ((pos = line.find(delimeter)) != std::string::npos) {


			    token = line.substr(0, pos);
			    //std::cout << token << std::endl;
			    if(index == 0){
			    	number = token;

			    }
			    else if(index == 1){
			    	username = token;
			    }

			    line.erase(0, pos + delimeter.length());
			    index++;
			    //cout << "doing a while loop" << endl;
			}

			//cout << line << endl;


			for (int i =0; i< NUMCHARS; i++){
				//hash[i] = line[i];
				hash[i] = line[i];
			}

			//cout << "number = " << number << endl;
			//cout << "username = " << username << endl;
//			for (int i=0; i<NUMCHARS; i++){
//				cout << "hash[i] = " << hash[i] << endl;
//			}

			//char pwd[] = "Qwerty1";
			//tryKeyboard(pwd, hash);
//
//			thread t1 (crack, hash);




			//first try known hashes
			//crackUsingHashes(number, username, hash);

			//cout <<"hashmap found = " << (hashmap.find("62bdf155") != hashmap.end()) << endl;

			crackUsingHashMap(number,username,hash);

			//crack(number, username, hash);
//
//			char pwd2[100] = "";

			//threads.emplace_back(tryWords,new char[100],hash);


//			if (k == 3)
//				break;
//
//			k++;

//			threads.emplace_back(crack,number, username, hash);

//			t1.join();

			//char* ans = crack(hash);

			//delete[] ans;

//			int result = checkIfCorrect(pwd, hash);
//			cout << "result = " << result << endl;

		}

//		for (thread & t : threads) {
//		    t.join();
//		}
//
//		threads.clear();

		//myfile.close();
	}

	else cout << "Unable to open file";
//
////	string line;
//	ifstream myfile2 ("hashedPasswords.txt");
//	//outputfile.open ("Passwords.txt");
//	if (myfile2.is_open())
//	{
//		int index = 0;
//		size_t pos = 0;
//		string token;
//		string number;
//		string username;
//		//unsigned char hash[NUMBYTES];
//
//		//int k = 0;
//
//		while (getline (myfile2,line) )
//		{
//			index = 0;
//			pos = 0;
//			token = "";
//			number = "";
//			username = "";
//			//hash = "";
//			unsigned char hash[NUMCHARS];
//
//			while ((pos = line.find(delimeter)) != std::string::npos) {
//
//
//				token = line.substr(0, pos);
//				std::cout << token << std::endl;
//				if(index == 0){
//					number = token;
//
//				}
//				else if(index == 1){
//					username = token;
//				}
//
//				line.erase(0, pos + delimeter.length());
//				index++;
//				//cout << "doing a while loop" << endl;
//			}
//
//			cout << line << endl;
//
//
//			for (int i =0; i< NUMCHARS; i++){
//				//hash[i] = line[i];
//				hash[i] = line[i];
//			}
//
//			cout << "number = " << number << endl;
//			cout << "username = " << username << endl;
//			//			for (int i=0; i<NUMCHARS; i++){
//			//				cout << "hash[i] = " << hash[i] << endl;
//			//			}
//
//			//char pwd[] = "Qwerty1";
//			//tryKeyboard(pwd, hash);
//			//
//			//			thread t1 (crack, hash);
//
//			//first try known hashes
			//crackUsingHashes(number, username, hash);



//
//			crack(number, username, hash);
//			//
//			//			char pwd2[100] = "";
//
//			//threads.emplace_back(tryWords,new char[100],hash);
//
//
//			//			if (k == 3)
//			//				break;
//			//
//			//			k++;
//
//			//			threads.emplace_back(crack,number, username, hash);
//
//			//			t1.join();
//
//			//char* ans = crack(hash);
//
//			//delete[] ans;
//
//			//			int result = checkIfCorrect(pwd, hash);
//			//			cout << "result = " << result << endl;
//
//		}
//
//		//		for (thread & t : threads) {
//		//		    t.join();
//		//		}
//		//
//		//		threads.clear();
//
//		myfile.close();
//	}
//
//	else cout << "Unable to open file";

	//


	//	char pwd[] = "Qwerty1";
	//	unsigned char answer[] = "451126c581dc3c15f15a111013808610";
	//	int result = checkIfCorrect(pwd, answer);
	//	cout << "result = " << result << endl;

	//free(pwd);

	outputfile.close();


	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	cout << "numfound = " << numfound << endl;
	cout << "eplased_secs = " << elapsed_secs << endl;

	return 0;
}
