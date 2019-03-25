#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tool.h"


int main(int argc, char *argv[]) {
	
	fillArray();
	
	char *array1 = getArray();
	char *array2 = getArray();
	char *array3 = getArray();
	
	clock_t inStart = clock();
	*array1 = bubbleSort(array1);
	clock_t inEnd = clock();
	printf("Time of bubble sorting: %f seconds\nTime of bubble sorting: %d steps\n\n",
		(double) (inEnd-inStart)/CLOCKS_PER_SEC, inEnd-inStart);
	writeArray(array1);


	inStart = clock();
	*array2 = selectionSort(array2);
	inEnd = clock();
	printf("Time of selection sorting: %f seconds\nTime of selection sorting: %d steps\n\n",
		(double) (inEnd-inStart)/CLOCKS_PER_SEC, inEnd-inStart);
	writeArray(array2);
	
	
	inStart = clock();
	*array3 = insertionSort(array3);
	inEnd = clock();
	printf("Time of insertion sorting: %f seconds\nTime of insertion sorting: %d steps\n\n",
		(double) (inEnd-inStart)/CLOCKS_PER_SEC, inEnd-inStart);
	writeArray(array3);

	free(array1);
	free(array2);
	free(array3);
	return 0;
}
