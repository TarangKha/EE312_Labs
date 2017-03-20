#include <stdio.h>
#include <string.h>
void printParans(char output[], int index, int openIdx, int closeIdx, int numParan);
void generateAllPalindromicDecompositions(char str[]);
void genPalin(char outArr[], int startDecompose, int palinLen, char str[]);
int arrayAddPalin(char outArr[], int startDecompose, int toAddStartIdx, int toAddEndIdx, char str[]);
int isPalindrome(char str[], int low, int high);
void arrayPopPalin(char outArr[], char str[]);

void generateAllMatchedParens(int n) {
	if (n < 1) {
		return;
	}
	char* output = calloc(2 * n);
	output[0] = '(';
	output[1] = ')';
	printParans(output, 1, n - 1, n, n);
	fprintf(stdout, "\n");
	return;
}

void printParans(char output[], int index, int openIdx, int closeIdx, int numParan) {
	int i;
	if (index == 2 * numParan) {
		for (i = 0; i < 2 * numParan; i++) {
			fprintf(stdout, "%c", output[i]);
		}
		fprintf(stdout, "\n");
		return;
	}
	if (openIdx != 0) {
		output[index] = '(';
		printParans(output, index + 1, openIdx - 1, closeIdx, numParan);
	}
	if ((closeIdx != 0) && (numParan - closeIdx + 1 <= numParan - openIdx)) {
		output[index] = ')';
		printParans(output, index + 1, openIdx, closeIdx - 1, numParan);
	}
	return;
}

void generateAllPalindromicDecompositions(char str[]) {
	int n = strlen(str);
	char* outArr = calloc(2 * sizeof(str));
	genPalin(outArr, 0, 1, str); 		
}

void genPalin(char outArr[], int startDecompose, int palinLen, char str[]) {
	int startIdx = strlen(outArr);
	int strLen = strlen(str);
	if (startDecompose >= strLen) {
		int outArrIdx = 2 * strlen(str);
		for (; outArr[outArrIdx] == 0 && outArrIdx >= 0; outArrIdx--) {
		}
		if (outArrIdx > 0) {
			for (int i = 1; i <= outArrIdx; i++) {
				if (outArr[i] != 0) {
					fprintf(stdout, "%c", outArr[i]);
				}
				else {
					fprintf(stdout, " ");
				}
			}
		}
		fprintf(stdout, "\n");
		return;
	}
	for (int i = startDecompose; i < strLen; i++)	{
		if (isPalindrome(str, startDecompose, i)) {
			int startIdx = arrayAddPalin(outArr, startDecompose, startDecompose, i, str);
			genPalin(outArr, i + 1, strlen(str), str);
			arrayPopPalin(outArr, str);
		}
	}
}
void arrayPopPalin(char outArr[], char str[]) {
	int outArrIdx = 2 * strlen(str);
	for (; outArr[outArrIdx] == 0 && outArrIdx >= 0; outArrIdx--) {
	}
	if (outArrIdx > 0) {
		for (; outArr[outArrIdx] != 0 && outArrIdx >= 0; outArrIdx--) {
			outArr[outArrIdx] = 0;
		}
	}
}



int arrayAddPalin(char outArr[], int startDecompose, int toAddStartIdx, int toAddEndIdx, char str[]) {
	int outArrIdx = 2 * strlen(str);
	int startIdx = 0;
	for (; outArr[outArrIdx] == 0 && outArrIdx >= 0; outArrIdx--) {
	}
	startIdx = outArrIdx;
	outArrIdx++;
	outArr[outArrIdx] = 0;
	for (int i = toAddStartIdx; i <= toAddEndIdx; i++) {
		outArrIdx++;
		outArr[outArrIdx] = str[i];
	}
	return startIdx;
}

int isPalindrome(char str[], int low, int high) {
	while (low < high) 	{
		if (str[low] != str[high]) {
			return 0;
		}
		low++;
		high--;
	}
	return 1;
}


