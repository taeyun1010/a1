#include "HashTry.h"

#define NUMCHARS 8

using namespace std;


enum { KEYLENGTH = 16 };

//unsigned char answer[] = "451126c581dc3c15f15a111013808610";

#define KEY_LEN      32
//#define KEK_KEY_LEN  16
#define KEK_KEY_LEN  4
#define ITERATION    500

// if this number of chars of hash are equal ( 2chars = 1byte), assume whole hash are equal
#define NUMCHARS 8

unsigned char salt_value2[] = { 's', 'e', 'c', 'l', 'a', 'b' };

string delimeter2 = ":";

char* tryKnownHash(unsigned char hash[NUMCHARS]){

	string hashfromfile;
	char* tab2 = (char*) malloc(100);
	strcpy(tab2, "");

	ifstream myfile ("dictionaries/processed_account_pw_withhash.txt");
	if (myfile.is_open())
	{
		//int index = 0;
		size_t pos = 0;
		string token = "";
		string pwd = "";
		string thishash = "";
		int compareresult = 1;

		while (getline (myfile,hashfromfile) )
		{
			compareresult = 1;
			//index = 0;
			pos = 0;

			//hash = "";

			while ((pos = hashfromfile.find(delimeter2)) != std::string::npos) {


				token = hashfromfile.substr(0, pos);
				//std::cout << token << std::endl;

				pwd = token;
				thishash = hashfromfile.substr((pos+1));

//				if(index == 0){
//					pwd = token;
//
//				}
//				else if(index == 1){
//					thishash = token;
//				}

				hashfromfile.erase(0, pos + delimeter2.length());
				//index++;
				//cout << "doing a while loop" << endl;
			}

			//cout << "pwd = " << pwd << endl;
			//cout << "thishash = " << thishash << endl;

			for (int i = 0; i <NUMCHARS; i++){
//				cout << "hash[i] = " << hash[i] << endl;
//				cout << "thishash.at(i) = " << thishash.at(i) << endl;
				if (hash[i] != thishash.at(i)){
					compareresult = 0;
					//cout <<"was not equal";
					break;
				}

			}
			if (compareresult == 1){
				break;
			}


		}

		myfile.close();
		if(compareresult == 1){
//			char tab2[1024];
			strcpy(tab2, pwd.c_str());
			//return tab2;
		}
	}
	else cout << "Unable to open file";





	return tab2;

}
