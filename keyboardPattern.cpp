#include "keyboardPattern.h"

#define NUMCHARS 8

using namespace std;

char* tryKeyboard(unsigned char hash[NUMCHARS]){



	char* localpwd= (char*) malloc(100);



	strcpy(localpwd, "aaaa");
	int result = checkIfCorrect(localpwd, hash);
	if (result == 1){

	}

	return localpwd;

}
