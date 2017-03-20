#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdint.h>

#define MEM_SIZE 10000
#define sz sizeof(int)

char slab[MEM_SIZE] = { 0 }; // Memory that's being used

void init_array(char slab[]);
char *my_malloc(char slab[], int numbytes);
void my_free(char slab[], char *p);
int wordsAvailable(char[], int);

int main() {
	init_array(slab);
	wordsAvailable(slab, 1);
	char* cPtr1 = my_malloc(slab, 5);
	wordsAvailable(slab, 1);
	char* cPtr2 = my_malloc(slab, 10);
	wordsAvailable(slab, 1);
	my_free(slab, cPtr1);
	wordsAvailable(slab, 1);
	char* cPtr3 = my_malloc(slab, 15);
	wordsAvailable(slab, 1);
	char* cPtr4 = my_malloc(slab, 9999);
	wordsAvailable(slab, 1);
	char* cPtr5 = my_malloc(slab, 8000);
	wordsAvailable(slab, 1);
	char* cPtr6 = my_malloc(slab, 5000);
	wordsAvailable(slab, 1);
	my_free(slab, cPtr5);
	wordsAvailable(slab, 1);
	my_free(slab, cPtr2);
	wordsAvailable(slab, 1);
	init_array(slab);
	wordsAvailable(slab, 1);
	char* cPtr7 = my_malloc(slab, 5000);
	wordsAvailable(slab, 1);
	my_free(slab, cPtr7);
	wordsAvailable(slab, 1);
	char* cPtr8 = my_malloc(slab, 9984);
	wordsAvailable(slab, 1);
	my_free(slab, cPtr8);
	wordsAvailable(slab, 1);
	cPtr1 = my_malloc(slab, 5);
	cPtr2 = my_malloc(slab, 15);
	cPtr3 = my_malloc(slab, 25);
	cPtr4 = my_malloc(slab, 35);
	cPtr5 = my_malloc(slab, 45);
	wordsAvailable(slab, 1);
	my_free(slab, cPtr2);
	my_free(slab, cPtr4);
	wordsAvailable(slab, 1);
	my_free(slab, cPtr3);
	wordsAvailable(slab, 1);
	cPtr6 = my_malloc(slab, 9672);
	wordsAvailable(slab, 1);
	cPtr7 = my_malloc(slab, 112);
	wordsAvailable(slab, 1);
	init_array(slab);
	wordsAvailable(slab, 1);
	cPtr1 = my_malloc(slab, 9999);
	wordsAvailable(slab, 1);
	cPtr1 = my_malloc(slab, 9995);
	wordsAvailable(slab, 1);
	cPtr1 = my_malloc(slab, 9990);
	wordsAvailable(slab, 1);
	printf("\n *************************************** \n");
	init_array(slab);
	wordsAvailable(slab, 1);
	cPtr1 = my_malloc(slab, 4);
	cPtr2 = my_malloc(slab, 8);
	cPtr3 = my_malloc(slab, 12);
	cPtr4 = my_malloc(slab, 16);
	cPtr5 = my_malloc(slab, 20);
	cPtr6 = my_malloc(slab, 24);
	cPtr7 = my_malloc(slab, 28);
	wordsAvailable(slab, 1);
	cPtr8 = my_malloc(slab, 9760);
	wordsAvailable(slab, 1);
	my_free(slab, cPtr6);
	wordsAvailable(slab, 1);
	cPtr1 = my_malloc(slab, 24);
	wordsAvailable(slab, 1);
	my_free(slab, cPtr1);
	wordsAvailable(slab, 1);
	cPtr1 = my_malloc(slab, 20);
	wordsAvailable(slab, 1);
	my_free(slab, cPtr1);
	wordsAvailable(slab, 1);
	cPtr1 = my_malloc(slab, 16);
	wordsAvailable(slab, 1);
	my_free(slab, cPtr1);
	wordsAvailable(slab, 1);
	cPtr1 = my_malloc(slab, 12);
	wordsAvailable(slab, 1);
	my_free(slab, cPtr1);
	wordsAvailable(slab, 1);
	cPtr1 = my_malloc(slab, 8);
	wordsAvailable(slab, 1);
	my_free(slab, cPtr1);
	wordsAvailable(slab, 1);
	cPtr1 = my_malloc(slab, 4);
	wordsAvailable(slab, 1);
	my_free(slab, cPtr1);
	wordsAvailable(slab, 1);

	printf("\n ***** START **** \n");
	init_array(slab);
	char* cPtr11 = my_malloc(slab, 9982);
	int64_t int64i = 0;
	int64_t int64j = 0;
	int64_t int64k = 0;
	int64_t* int64TopMetadataPtr = (int64_t*)(cPtr11 + 1);
	int64k = *int64TopMetadataPtr;
	if (int64k < 0) {
		int64k = int64k * (-1);
	}
	int64_t* int64BottomMetadataPtr = (int64_t*)(cPtr11 + 1 - (int64k * 4 + 8));
	int64i = *int64TopMetadataPtr;
	int64j = *int64BottomMetadataPtr;
	printf("\nTop Metadata Value %d ", int64i);
	printf("\nBottom Metadata value %d ", int64j);
	my_free(slab, cPtr11);
	int64i = *int64TopMetadataPtr;
	int64j = *int64BottomMetadataPtr;
	printf("\nTop Metadata Value %d ", int64i);
	printf("\nBottom Metadata value %d ", int64j);
	printf("\n ***** END ***** \n");
}