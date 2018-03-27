/*
 * PasswordCrackwithMake.h
 *
 *  Created on: Mar 27, 2018
 *      Author: taeyun
 */

#ifndef PASSWORDCRACKWITHMAKE_H_
#define PASSWORDCRACKWITHMAKE_H_

// if this number of chars of hash are equal ( 2chars = 1byte), assume whole hash are equal
#define NUMCHARS 16

int retunInt(char upperChar, char lowerChar);

//return 1 if equal, 0 otherwise
int checkIfCorrect(const char pwd[], unsigned char answer[]);
const char* crack(unsigned char hash[NUMCHARS]);


#endif /* PASSWORDCRACKWITHMAKE_H_ */
