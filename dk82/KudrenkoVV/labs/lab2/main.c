#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tool.h"


int main()
{
	char * cArray;
	cArray = (char *)malloc(sizeof(char) * 100);
	
	int i, counter = 0;

	FILE *stream;
	fopen_s(&stream, "write.txt", "w");
	
	counter = fillArray(cArray, 100);
	
	printf("%s", cArray);
	printf("\ncounter: %i \n", counter);
	
	clock_t inStart = clock();
	
//	bubbleSort(cArray, counter);
//	printf("Bubble sort: %s", cArray);
//	fprintf(stream, "Buble sort: %s", cArray);
	
//	shellSort(cArray, counter);
//	printf("Shell sort: %s", cArray);
//	fprintf(stream, "Shell sort: %s", cArray);
	
	insertionSort(cArray, counter);
	printf("Insertion sort: %s\n", cArray);
	fprintf(stream, "Insertion sort: %s\n", cArray);
	

	clock_t inEnd = clock();
	printf("Time of bubble sorting: %f seconds\nTime of bubble sorting: %d steps\n\n",
		(double) (inEnd-inStart)/CLOCKS_PER_SEC, inEnd-inStart);


	fclose(stream);
}	
