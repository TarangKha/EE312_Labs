/*Khandpur, Tarang
tk8435
15980
EE312-Assignment 3
*/

#include <stdio.h>


/*
* return 1 if the ASCII interpretation of
* c is an upper case letter.
* return 0 otherwise
*/
int isUpperCase(char c) {
	if (c >= 'A' && c <= 'Z') {
		return 1;
	}
	else {
		return 0;
	}
}

/*
* return 1 if the ASCII interpretation of
* c is a lower case letter.
* return 0 otherwise
*/
int isLowerCase(char c) {
	if (c >= 'a' && c <= 'z') {
		return 1;
	}
	else {
		return 0;
	}
}

/*
* return 1 c is an Alphabet.
* return 0 otherwise
*/
int isAlphabet(char c) {
	return isUpperCase(c) || isLowerCase(c);
}

/*
* if the ASCII interpretation of c is a letter, then
* return a number between 0 and 25 indicating which letter of
* the alphabet c represents.  For example, if c is the ASCII
* encoding for 'A', then we should return 0.  If c is the
* ASCII encoding for 'e', then we should return 4.
* if the ASCII interpretation of c is not a letter, then
* return -1.
*/
int ASCII2Int(char c) {
	if (isUpperCase(c)) {
		return c - 'A';
	}
	else if (isLowerCase(c)) {
		return c - 'a';
	}
	else {
		return -1;
	}
}
int ASCII2IntUpper(char c) {
	if (isUpperCase(c)) {
		return c - 'A';
	}
	else {
		return -1;
	}
}
int ASCII2IntLower(char c) {
	if (isLowerCase(c)) {
		return c - 'a';
	}
	else {
		return -1;
	}
}

/*
* assumes i is between 0 and 25 inclusive
*/
char int2UpperCase(int i) {
	char c = 'A' + i;
	return c;
}

/*
* assumes i is between 0 and 25 inclusive
*/
char int2LowerCase(int i) {
	char c = 'a' + i;
	return c;
}

/*
* This function takes in a message and computes the frequencies of all the alphabets
*/
void buildHistogram(char message[], int messageLength, int histogram[], int histogramLength) {
	for (int i = 0; i < histogramLength; i++) {
		for (int j = 0; j < messageLength; j++) {
			if (i == ASCII2Int(message[j])) {
				histogram[i] = histogram[i] + 1;
			}
		}
	}
}

/*
* This function takes in a message and computes the frequencies of all the alphabets
*/
void buildHistogramUpper(char message[], int messageLength, int histogram[], int histogramLength) {
	for (int i = 0; i < histogramLength; i++) {
		for (int j = 0; j < messageLength; j++) {
			if (i == ASCII2IntUpper(message[j])) {
				histogram[i] = histogram[i] + 1;
			}
		}
	}
}
void buildHistogramLower(char message[], int messageLength, int histogram[], int histogramLength) {
	for (int i = 0; i < histogramLength; i++) {
		for (int j = 0; j < messageLength; j++) {
			if (i == ASCII2IntLower(message[j])) {
				histogram[i] = histogram[i] + 1;
			}
		}
	}
}

/*
* This function computes the maximum value in an array and returns the index location\
* for which the maximum value occured
*/

int maxIndex(int myArray[], int arrayLength) {
	int maxLocation = 0;
	for (int i = 0; i < arrayLength; i++) {
		if (myArray[i] > myArray[maxLocation]) {
			maxLocation = i;
		}
	}
	return maxLocation;
}

/*
* Encrypt the string s using the rotation cypher
* Each letter in s should be shifted "shift" letters to the
* right.  For example, if "shift" is 2, then "a zebra" should be
* changed to "c bgdtc".  Note that when shifting past the end
* of the alphabet, we wrap around again to a.
*
* Only change the letters in s.  Do not change spaces, punctuation
* or numbers in s.
* For full credit, you should keep upper case letters as
* upper case, and leave lower case letters as lower case.  So, if
* s had been the string "a ZeBra", you should change s to be
* "c BgDtc".
*/
void encrypt(char message[], int messageLength, int shift) {
	for (int i = 0; i < messageLength; i++) {
		int j = ASCII2Int(message[i]);
		if (j >= 0) {
			j = j + shift;
			if (j <= 25) {
				message[i] = message[i] + shift;
			}
			else {
				j = j - shift;
				j = j - (j + shift - 25) + 1;
				message[i] = message[i] - j;
			}
		}
	}
}

/*
* return a number between 0 and 25 indicating which letter
* of the alphabet is most common in the string s
*/
int mostFrequentLetter(char message[], int messageLength) {
	/*
	* Build the histogram and get the index of most frequent alphabet
	*/
	int histogramLength = 52;
	int histogram[52];
	for (int i = 0; i < histogramLength; i++) {
		histogram[i] = 0;
	}
	int mostFrequentIndex = 0;
	buildHistogram(message, messageLength, histogram, histogramLength);
	for (int i = 0; i < histogramLength; i++) {
		if (histogram[i] > histogram[mostFrequentIndex]) {
			mostFrequentIndex = i;
		}
	}
	char rebuildHistogramUpper = 'F';
	for (int i = mostFrequentIndex + 1; i < histogramLength; i++) {
		if (histogram[i] == histogram[mostFrequentIndex]) {
			rebuildHistogramUpper = 'T';
		}
	}
	if (rebuildHistogramUpper == 'T') {
		for (int i = 0; i < histogramLength; i++) {
			histogram[i] = 0;
		}
		mostFrequentIndex = 0;
		buildHistogramUpper(message, messageLength, histogram, histogramLength);
		for (int i = 0; i < histogramLength; i++) {
			if (histogram[i] > histogram[mostFrequentIndex]) {
				mostFrequentIndex = i;
			}
		}

	}
	char rebuildHistogramLower = 'F';
	for (int i = mostFrequentIndex + 1; i < histogramLength; i++) {
		if (histogram[i] == histogram[mostFrequentIndex]) {
			rebuildHistogramLower = 'T';
		}
	}
	if (rebuildHistogramLower == 'T') {
		for (int i = 0; i < histogramLength; i++) {
			histogram[i] = 0;
		}
		mostFrequentIndex = 0;
		buildHistogramLower(message, messageLength, histogram, histogramLength);
		for (int i = 0; i < histogramLength; i++) {
			if (histogram[i] > histogram[mostFrequentIndex]) {
				mostFrequentIndex = i;
			}
		}

	}

	return mostFrequentIndex;
}

void decrypt(char cypher[], int cypherLength, int common) {
	int mostFrequentIndex2 = mostFrequentLetter(cypher, cypherLength);
	int shift = mostFrequentIndex2 - common;
	int shiftTemp = shift;
	//	printf("%d ; %d \n", mostFrequentIndex2, common);
	for (int i = 0; i < cypherLength; i++) {
		int j = ASCII2Int(cypher[i]);
		if (j >= 0) {
			j = j - shift;
			if (j < 0) {
				j = j + 26;
			}
			if (j > 25) {
				j = j - 26;
			}
			//			printf("%d", cypher[i]);
			if (isUpperCase(cypher[i])) {
				cypher[i] = int2UpperCase(j);
			}
			else {
				cypher[i] = int2LowerCase(j);
			}
			//			printf("%d ;", cypher[i]);
		}
	}
	printf("\n");
}


