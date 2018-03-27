/*
 * hashChecker.h
 *
 *  Created on: Mar 27, 2018
 *      Author: taeyun
 */

#ifndef HASHCHECKER_H_
#define HASHCHECKER_H_

#define KEY_LEN      32
#define KEK_KEY_LEN  16
#define ITERATION    500

using namespace std;

// if this number of chars of hash are equal ( 2chars = 1byte), assume whole hash are equal
#define NUMCHARS 16

//string delimeter = ":";

unsigned char salt_value[] = { 's', 'e', 'c', 'l', 'a', 'b' };

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <openssl/evp.h>
#include <fstream>
#include <string.h>

int retunInt(char upperChar, char lowerChar);

//return 1 if equal, 0 otherwise
int checkIfCorrect(char pwd[], unsigned char answer[]);

#endif /* HASHCHECKER_H_ */
