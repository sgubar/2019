
#include <stdlib.h>
#include "sort.h"


int main(int argc, char **argv)
{
	int arrsize = getSize();
	
	char *array, *arrcopy;
	array = (char*)malloc(arrsize*sizeof(char));
	arrcopy = (char*)malloc(arrsize*sizeof(char));
	
	clock_t start, end;
	
	FILE *unsortedFile;
	if ((unsortedFile = fopen("unsorted.txt", "w")) == NULL){	
		return -57;
	}
	
	srand(time(NULL));
	randomArray(unsortedFile, arrsize);
	fclose(unsortedFile);
	
	if ((unsortedFile = fopen("unsorted.txt", "r")) == NULL	){
		return -57;
	}
	
	FILE *sortedFile;
	if ((sortedFile = fopen("sorted.txt", "w")) == NULL){
		return -57;
	}
	
	
	for (int i = 0; i < arrsize; i++){
		fscanf(unsortedFile, "%c", &array[i]);
	}
	
	printf("Bubble Sort\n");
	copyArray(array, arrcopy, arrsize);
	start = clock();
	bubbleSort(arrcopy, arrsize);
	end = clock();
	printOnScreen(arrcopy, arrsize, (double)(end - start));
	printToFile(sortedFile, arrcopy, arrsize, (double)(end - start));
	
	printf("Selection Sort\n");
	copyArray(array, arrcopy, arrsize);
	start = clock();
	selectionSort(arrcopy, arrsize);
	end = clock();
	printOnScreen(arrcopy, arrsize, (double)(end - start));
	printToFile(sortedFile, arrcopy, arrsize, (double)(end - start));
	
	printf("Insertion Sort\n");
	copyArray(array, arrcopy, arrsize);
	start = clock();
	insertionSort(arrcopy, arrsize);
	end = clock();
	printOnScreen(arrcopy, arrsize, (double)(end - start));
	printToFile(sortedFile, arrcopy, arrsize, (double)(end - start));
	
	free(array);
	free(arrcopy);
	fclose(unsortedFile);
	fclose(sortedFile);
	return 0;
}

