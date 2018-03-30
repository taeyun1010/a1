#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <ctime>
#include <map>

using namespace std;

enum { KEYLENGTH = 16 };

#define NUMCHARS 8

string delimeter = ":";

ofstream outputfile;

int numfound = 0;

map<string,string> hashmap;
//load maps to memory
void initialize(){
	//clock_t begin = clock();

	ifstream myfile ("dictionaries/processed_account_pw_withhash.txt");
	if (myfile.is_open())
	{
		string hashfromfile;
		size_t pos = 0;
		string token = "";
		string pwd = "";
		string thishash = "";

		while (getline (myfile,hashfromfile) )
		{

			pos = 0;

			while ((pos = hashfromfile.find(delimeter)) != std::string::npos) {

				token = hashfromfile.substr(0, pos);

				pwd = token;
				thishash = hashfromfile.substr((pos+1));


				//to get rid of the newline character at the end
				thishash = thishash.substr(0, thishash.length()-1);


				hashmap.insert(pair<string,string>(thishash,pwd));

				hashfromfile.erase(0, pos + delimeter.length());

			}



		}

		myfile.close();

	}
	else cout << "Unable to open file";



}

void crackUsingHashMap(string number, string username, unsigned char hash[NUMCHARS]){

	string hashfromfile;
	char* tab2 = (char*) malloc(100);
	strcpy(tab2, "");
	string thisstring = "";


	for (int i = 0; i <NUMCHARS; i++){

		thisstring += hash[i];
	}

	string pwd = "";


	if(hashmap.find(thisstring) != hashmap.end()){
		pwd = hashmap.find(thisstring)->second;
		strcpy(tab2, pwd.c_str());
	}


	if (strcmp(tab2, "") != 0)
			numfound++;

	outputfile << number << ":" << username << ":" << tab2 << "\n";

	free(tab2);


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

			}

			for (int i =0; i< NUMCHARS; i++){
				//hash[i] = line[i];
				hash[i] = line[i];
			}

			crackUsingHashMap(number,username,hash);

		}

	}

	else cout << "Unable to open file";


	outputfile.close();

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	cout << "numfound = " << numfound << endl;
	cout << "eplased_secs = " << elapsed_secs << endl;

	return 0;
}
