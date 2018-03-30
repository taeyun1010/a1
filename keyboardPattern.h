/*
 * keyboardPattern.h
 *
 *  Created on: Mar 29, 2018
 *      Author: taeyun
 */

#ifndef KEYBOARDPATTERN_H_
#define KEYBOARDPATTERN_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <openssl/evp.h>
#include <fstream>
#include <string.h>
#include "PasswordCrackwithMake.h"

#define NUMCHARS 8

char* tryKeyboard(unsigned char hash[NUMCHARS]);


#endif /* KEYBOARDPATTERN_H_ */
