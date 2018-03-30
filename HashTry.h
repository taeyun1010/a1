/*
 * HashTry.h
 *
 *  Created on: Mar 30, 2018
 *      Author: taeyun
 */

#ifndef HASHTRY_H_
#define HASHTRY_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <openssl/evp.h>
#include <fstream>
#include <string.h>
#include "PasswordCrackwithMake.h"

#define NUMCHARS 8

char* tryKnownHash(unsigned char hash[NUMCHARS]);





#endif /* HASHTRY_H_ */
