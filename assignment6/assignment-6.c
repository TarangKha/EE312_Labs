#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MEM_SIZE 10000

extern char slab[MEM_SIZE]; // Memory that's being used

/*
One Word - 4 bytes
Each char / int takes 1 byte
Array is 10,000 bytes or 2500 words
Memory is allocated in words (chunks of 4 bytes)
Metadata takes up 2 words, since there are 2 metadata for each data block so each data block needs 4 words or 16 bytes
Thus to store 3 chracters we need 3 bytes and 3%4 + 1 = 1 word, so total 2+2+1 = 5 words
so the heap array will become
from
[0][1][2][3][4][5][6][7] ....     [9992][9993][9994][9995][9996][9997][9998][9999]
 0  0  0  0  2  4  9  6  all zeros  0     0     0     0     2     4     9     6
 to
 0 0 0 0 0 0 0 2    0 0 0 3    0 0 0 0 0 0 0 2    0 0 0 0 2 4 9 1  all zeros  0 0 0 0 2 4 9 1
 /

/* You shouldn't try to call malloc in your
my_malloc function */

void storeIntAsCharArray(int64_t, char*);
int64_t convertCharArrayToInt(char*);
int wordsAvailable(char[], int);
char* exactBlockAvailable(char[], int);

void *malloc(size_t n) {
	printf("Cheater!\n");
	return NULL;
}

//Initialize the starting point of the array
void init_array(char slab[]) {
	printf("\nInit called");
	for (int i = 0; i < MEM_SIZE; i++) {
		slab[i] = 0;						//initializes all elements in slab array to zeros
	}
	int metadataWords = (MEM_SIZE / sizeof(int) - 4);  //converts availabe bytes to words . the -4 is for each block overhead (2 in the start and e2 in the end)
	char* metadataPtr = slab + MEM_SIZE - 8;
	storeIntAsCharArray((int64_t) metadataWords, metadataPtr); //stores the integer as a character with a +/- sign in the 8 bytes available starting from the 1st bytes whose address is passed to the function
	return;
}

//Allocate requested memory
char* my_malloc(char slab[], int numBytes) {
//get the number of words needed to store numBytes
	int64_t numWords = numBytes / 4;
	if (numBytes % 4 > 0) {
		numWords++;
	}
	printf("\nMy malloc called with bytes/words %i/%i", numBytes, numWords);
	int64_t i = MEM_SIZE - 8;
	int64_t j = 0;
	char* topMetaDataPtr = slab + i;
	int maxWords = MEM_SIZE / 4 - 4;
	if (numWords > maxWords) {
		printf("\nCannot allocate - requested space is more than the maximum possible");
		return NULL;
	}
	if (numWords < 1) {
		printf("\nCannot allocate - Invalid amount of space requested");
		return NULL;
	}
/*
	if (numWords == maxWords) {
		storeIntAsCharArray((int64_t)(numWords * (-1)), slab + i);
		return (slab + i - 1);
	}
*/
	int k = wordsAvailable(slab, 0);
	if (numWords > k) {
		printf("\nCannot allocate - requested space is more than the maximum available");
		return NULL;
	}
	char* exactBlockPtr = exactBlockAvailable(slab, numWords);
/*
	if (exactBlockPtr != NULL) {
		storeIntAsCharArray((int64_t)numWords * (-1), exactBlockPtr); 
		return(exactBlockPtr);
	}
*/
	while (i >= 0) {
		j = convertCharArrayToInt(slab + i);
		if (j >= numWords && j <= numWords + 4) {
			storeIntAsCharArray(j * (-1), slab + i); 
			return(slab + i - 1);
		}
		if (j >= (numWords + 5)) {		//the 16 is added because for each block of bytes we need 16 bytes for metadata. check to see if the block has space for numBytes with metadata
			j = j - (numWords + 2 + 2);  //the existing blocks metadata value is reduced by number of Words requested + 4 for the additional metadata
			storeIntAsCharArray(j, slab + i); // change the metadata for the existing block
			storeIntAsCharArray((int64_t) (numWords * (-1)), slab + i - (j * 4 + 16)); // change metadata for the new block. use the -ve sign to indicate it is not free
			return (slab + i - (j * 4 + 16) - 1); //so that topMetaDataPtr pooints to the start of the data
		}
		if (j >= 0) {
			i = i - (j * 4 + 16); // move to the array location of the next starting metadata. each metadata take s 8 bytes and each memory block needs 2 metadata
		}
		else {
			i = i - (j * 4 * (-1) + 16); // move to the array location of the next starting metadata. each metadata take s 8 bytes and each memory block needs 2 metadata
		}
	}
	printf("\nSorry nothing is available!");
	return NULL;
}

//Deallocate requested 
void my_free(char slab[], char* p) {
	char *slabBottomPtr = slab;
	char *slabTopPtr = slab + MEM_SIZE - 8;
	printf("\nMy free called %i", p - slab + 1);
// check to make sure that the pointer passed is within the array
// the pointer should point to the first bytes of the data so -8 will make it point to the 1st byte of metadata
// +12 assumes that the if pointer were to point to data the index of the last byte of the end metadata woould be 3 words (12 bytes away)
	int i = 0;
	char *ptrTop = p + 1;
	if (ptrTop < slabBottomPtr || ptrTop > slabTopPtr) {
		printf("\n2.Invalid Pointer passed to free block");
		return;
	}
	int64_t j = convertCharArrayToInt(ptrTop);
// if j is +ve means the pointer points to a free block
	if (j >= 0) {
		printf("\n1.Invalid Pointer passed to free block");
		return;
	}
	j = j * (-1);
	storeIntAsCharArray(j, ptrTop);
// below is the logic to find and merge empty blocks which are adjacent to the block being freed.
	char *ptrBottom = ptrTop - ( 8 + j * 4);
	int64_t aboveBlockFree = 0;
	if ((ptrTop + 8) <= slabTopPtr) {
		aboveBlockFree = convertCharArrayToInt(ptrTop + 8);
	}
	int64_t belowBlockFree = 0;
	if ((ptrTop - (j * 4 + 16)) >= slabBottomPtr) {
		belowBlockFree = convertCharArrayToInt(ptrTop - (j * 4 + 16));
	}
	if (aboveBlockFree > 0 || belowBlockFree > 0) {
		if (aboveBlockFree > 0 && belowBlockFree > 0) {
			storeIntAsCharArray(j + aboveBlockFree + 4 + belowBlockFree + 4, ptrTop + 16 + aboveBlockFree * 4);
			return;
		}
		if (aboveBlockFree > 0) {
			storeIntAsCharArray(j + aboveBlockFree + 4, ptrTop + 16 + aboveBlockFree * 4);
			return;
		}
		else {
			storeIntAsCharArray(j + belowBlockFree + 4, ptrTop);
			return;
		}
	}
}

int64_t convertCharArrayToInt(char* p) {

	int64_t* j = (int64_t*)p;		
	int64_t k = *j;
	return k;
/*
	int64_t i = 0;
	memcpy(&i, p, 8);
	return i;
*/
}

void storeIntAsCharArray(int64_t i, char* p) { 
	int64_t* j = (int64_t*)p;		//cast the char pointer as a int64 pointer and assign the address to j. j is a int64 pointer
	*j = i;							// now j pointer's memory location contains the value of i. int64 takes up 8 bytes in increasing order of the address
	if (i >= 0) {
		p = p - (i * 4 + 8);		// change the value of the pointer p to point to the bottom metadata of the same block
	}
	else {
		p = p - (i * 4 * (-1) + 8);
	}
	j = (int64_t*)p;
	*j = i;

/*
	memcpy(p, &i, 8);
	if (i >= 0) {
		memcpy(p - (i * 4 + 8), &i, 8);
	}
	else {
		memcpy(p - (i * 4 * (-1) + 8), &i, 8);
	}
*/

}
int wordsAvailable(char slab[], int print) {
// this function is just used for testing and calls to this function from the main.c can be commented out.
// this function counts all the available and used block and the metadata information in each block. it also prints the array index of the starting byte of each block
	int64_t i = MEM_SIZE - 8;
	int64_t j = 0;
	int j2 = 0;
	int64_t k = 0;
	int wordsUsed = 0;
	int wordsAvailable = 0;
	int maxWordsAvailableInBlock = 0;
	int blocksUsed = 0;
	int blocksAvailable = 0;
	while (i >= 0) {
		j = convertCharArrayToInt(slab + i);
		if (j >= 0) {
			if (print == 1) {
				printf("\nIndex and Metadata values %i/", i);
				printf("%i", (int)j);
			}
			blocksAvailable++;
			wordsAvailable = wordsAvailable + j;
		}
		else {
			if (print == 1) {
				printf("\nIndex and Metadata values %i/", i);
				printf("%i", (int)j);
			}
			j = j * (-1);
			blocksUsed++;
			wordsUsed = wordsUsed + j;
		}
		i = i - (j * 4 + 16);
		if (maxWordsAvailableInBlock < wordsAvailable) {
			maxWordsAvailableInBlock = wordsAvailable;
		}
	}
	if (print == 1) {
		printf("\nAvailable Blocks/Words %i/%i Used Blocks/Words %i/%i in Slab.%i", blocksAvailable, wordsAvailable, blocksUsed, wordsUsed, blocksAvailable * 4 + wordsAvailable + blocksUsed * 4 + wordsUsed);
	}
	return maxWordsAvailableInBlock;
}

char* exactBlockAvailable(char slab[], int numWords) {
	int64_t i = MEM_SIZE - 8;
	int64_t j = 0;
	while (i >= 0) {
		j = convertCharArrayToInt(slab + i);
		if ((int64_t)numWords == j) {
			return (slab + i);
		}
		if (j >= 0) {
			i = i - (j * 4 + 16);
		}
		else {
			i = i - (j * 4 * (-1) + 16);
		}
	}
	return NULL;
}
