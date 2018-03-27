/*
 * hashChecker.cpp
 *
 *  Created on: Mar 27, 2018
 *      Author: taeyun
 */

#include "hashChecker.h"

//string delimeter = ":";


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


//return 1 if equal, 0 otherwise
int checkIfCorrect(char pwd[], unsigned char answer[]) {
	int result = 1;
	size_t i;
	unsigned char* out;
	out = (unsigned char *) malloc(sizeof(unsigned char) * KEK_KEY_LEN);
	printf("pass: %s\n", pwd);
	printf("ITERATION: %u\n", ITERATION);
	printf("salt: ");
	for (i = 0; i < sizeof(salt_value); i++) {
		printf("%02x", salt_value[i]);
	}
	printf("\n");
	if (PKCS5_PBKDF2_HMAC_SHA1(pwd, strlen(pwd), salt_value, sizeof(salt_value),
			ITERATION, KEK_KEY_LEN, out) != 0) {
		printf("out: ");
//		for (i = 0; i < KEK_KEY_LEN; i++) {
//			printf("%02x", out[i]);
//			if(out[i] != answer[i]){
//
//				//printf("result = ");
//				result = 0;
//				break;
//			}
//
//		}
//
//		unsigned int a = 240;
//		unsigned int b = 15;

//		for (int j =0; j< NUMCHARS; j++){
//			//printf("bitwise result = %02x", (out[j] >> 4));
//			printf("out[j] = %02x\n", out[j] );
//			//cout << "answer[j] = " << answer[j]<<endl;
//			//cout << "answer[j] int value = " << answer[j] - '0' << endl;
////			cout << "out[j] = " << out[j] << endl;
//			//cout << "out[j] int value = " << (int) out[j] << endl;
//		}

		for (i = 0; i < (NUMCHARS / 2); i++) {

			//2*i   2*i + 1

			int temp =	retunInt(answer[(2*i)], answer[(2*i + 1)]);

			//cout << "answer[i] int value = " << temp<< endl;



			printf("%02x", out[i]);
//			if(out[i] != answer[i]){
//
//				//printf("result = ");
//				result = 0;
//				break;
//			}

			if(temp != (int) out[i]){
				result = 0;
				break;

			}

		}

//		//
//		result = strcmp(out, answer);
//		//

		printf("\n");
	} else {
		fprintf(stderr, "PKCS5_PBKDF2_HMAC_SHA1 failed\n");
	}
	free(out);
	//free(pwd);

	return result;
}