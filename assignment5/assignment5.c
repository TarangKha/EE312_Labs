	/*
	* Tarang Khandpur
	* TK8435
	* Course 15980
	* assignment5.c
	* SpellCheck
	*/

#include <stdio.h> // provides declarations for printf and putchar
#include <stdint.h> // provides declarations for int32_t uint32_t and the other (new) standard C types
#include <stdlib.h>

	/* All of your code must be in this file. Please no #includes other than standard system headers (ie.., stdio.h, stdint.h)
	*
	* Many students find it helpful to declare global variables (often arrays). You are welcome to use
	* globals if you find them helfpul. Global variables are by no means necessary for this project.
	*/

	/* You must write this function (spellCheck). Do not change the way the function is declared (i.e., it has
	* exactly two parameters, each parameter is a standard (mundane) C string (see SpellCheck.pdf).
	* You are expected to use reasonable programming style. I strongly encourage you to avoid big functions
	* (while there are always exceptions, a good rule of thumb is about 15 lines in a function).
	* So, plan on implementing spellCheck by writing two or three other "support functions" that
	* help make the actual spell checking easier for you.
	* There are no explicit restictions on using functions from the C standard library. However,
	* for this project you should avoid using functionality from the C++ standard libary. You will
	* almost certainly find it easiest to just write everything you need from scratch!
	*/

	//TODO:
#define ONEMB2 (1 << 20)
#define BUFFERSIZE2 ONEMB2

int misspelled(int, int, char[], char[]);
void storeWord(int, int, char[]);
char convertLowerToUpper(char);
void printWord();
char wordOut[BUFFERSIZE2];
// char articleWord[BUFFERSIZE2];
char inWordArray[BUFFERSIZE2];
int startWordOut = 0;
int endWordOut = 0;

void spellCheck(char article[], char dictionary[]) {
	for (int i = 0; wordOut[i] != 0; i++) {
		wordOut[i] = 0;
	}
	startWordOut = 0;
	endWordOut = 0;
	int StartingWordIndex = 0;
	int EndingWordIndex = 0;
	int InWord = 0;
	int OutWord = 0;
	int elementsArticle = sizeof(article) / sizeof(char);
	/*
	printf("Article = ");
	for (int i = 0; article[i] != 0; i++) {
	elementsArticle = i + 1;
	printf("%c", article[i]);
	}
	printf("\nDictionary = ");
	for (int i = 0; dictionary[i] != 0; i++) {
	printf("%c", dictionary[i]);
	if (dictionary[i] == 10) {
	printf("             ");
	}
	}
	printf("\n");
	*/
	for (int i = 0; article[i] != 0; i++) {
		elementsArticle = i + 1;
	}
	if (elementsArticle < 2) {
	}

	for (int ArrayIndex = 0; ArrayIndex <= elementsArticle; ArrayIndex++) {
		if (isAlphabet(article[ArrayIndex])) {
			if (InWord == 1) {
				continue;
			}
			else {
				InWord = 1;
				StartingWordIndex = ArrayIndex;
			}
		}
		else {
			if (InWord == 1) {
				InWord = 0;
				EndingWordIndex = ArrayIndex;
				if ((EndingWordIndex - StartingWordIndex) > 1) {
					if (isMisspelled(StartingWordIndex, EndingWordIndex, article, dictionary)) {
						storeWord(StartingWordIndex, EndingWordIndex, article);
					}
				}
			}
		}
	}
	if (EndingWordIndex > 0) {
		printWord();
	}
}

int isMisspelled(int i, int j, char article[], char dictionary[]) {
/*
	for (int r = 0; articleWord[r] != 0; r++) {
		articleWord[r] = 0;
	}
	for (int m = i; m < j; m++) {
		if (isLowerCase(article[m])) {
			articleWord[m - i] = convertLowerToUpper(article[m]);
		}
		else {
			articleWord[m - i] = (article[m]);
		}

	}
*/
	int startWordDictionaryIndex = 0;
	int endWordDictionaryIndex = 0;
	int wordMisspelled = 1;
	int inDictWord = 0;
	int elementsDictionary = sizeof(dictionary) / sizeof(char);
	for (int i1 = 0; dictionary[i1] != 0; i1++) {
		elementsDictionary = i1 + 1;
	}
	for (int k = startWordDictionaryIndex; (k <= elementsDictionary || dictionary[k] == 0); k++) {
		if (dictionary[k] == 10) {
			endWordDictionaryIndex = k;
			int wordMatched = 0;
			/*
			if (articleWord[0] < convertLowerToUpper(dictionary[startWordDictionaryIndex])) {
			break;
			}
			if (articleWord[0] > convertLowerToUpper(dictionary[startWordDictionaryIndex])) {
			continue;
			}
			*/

//			int n = 0;
			int n = i;
			wordMatched = 1;
			for (int m = startWordDictionaryIndex; m < endWordDictionaryIndex; m++) {
				if (isAlphabet(dictionary[m])) {
//					if (convertLowerToUpper(dictionary[m]) != articleWord[n]) {
					if (convertLowerToUpper(dictionary[m]) != convertLowerToUpper(article[n])) {
						wordMatched = 0;
						break;
					}
				}
				n++;
			}
			if ((j - i) == (endWordDictionaryIndex - startWordDictionaryIndex)) {
				if (wordMatched == 1) {
					wordMisspelled = 0;
					return(wordMisspelled);
				}
			}
			startWordDictionaryIndex = k + 1;
			continue;
		}
	}
	return(wordMisspelled);
}

void storeWord(int i, int j, char article[]) {
	int startStoreWord = 0;
	int newWord = 1;
	int sizeInWord = 0;
	for (int r = 0; inWordArray[r] != 0; r++) {
		inWordArray[r] = 0;
	}
	int n = 0;
	for (n = 0; n < (j - i); n++) {
		inWordArray[n] = article[i + n];
	}
	sizeInWord = n;
	inWordArray[n] = 10;

	int sizeWordOut = 0;
	for (int k = 0; wordOut[k] != 0; k++) {
		sizeWordOut++;
	}
	int m = 0;
	int allCharMatched = 0;
	for (int n = 0; wordOut[n] != 0; n++) {
		if (wordOut[n] == 10) {
			allCharMatched = 1;
			for (int m = startStoreWord; m < n; m++) {
				if (inWordArray[m - startStoreWord] != wordOut[m]) {
					allCharMatched = 0;
					break;
				}
			}
			if ((n - startStoreWord) == sizeInWord) {
				if (allCharMatched == 1) {
					return;
				}
			}
			startStoreWord = n + 1;
		}
	}
	for (n = 0; (n < (j - i)); n++) {
		wordOut[n + sizeWordOut] = inWordArray[n];
	}
	wordOut[n + sizeWordOut] = 10;
}

void printWord() {
	for (int i = 0; wordOut[i] != 0; i++) {
		printf("%c", wordOut[i]);
	}
}


char convertLowerToUpper(char c) {
	if (isUpperCase(c)) {
	}
	else {
		c = c - 32;
	}
	return c;
}
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
