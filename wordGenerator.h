#ifndef WORDGENERATOR_H
#define WORDGENERATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <openssl/evp.h>
#include <fstream>
#include <string.h>
#include "PasswordCrackwithMake.h"


#define NUMCHARS 16

void tryWords(char* pwd, unsigned char hash[NUMCHARS]);

#endif
