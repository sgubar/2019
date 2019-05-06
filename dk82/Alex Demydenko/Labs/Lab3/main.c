#include "sort.h"

int main(int argc, char **argv)
{
	int arrsize = getSize();
	
	char *array;
	array = (char*)malloc(arrsize*sizeof(char));
	
	clock_t start, end;
	

	FILE *sortedFile;
	if ((sortedFile = fopen("sort.txt", "w")) == NULL){
		return -57;
	}


	srand(time(NULL));
	chaosfillFile(sortedFile, "sort.txt", arrsize);
	fclose(sortedFile);
	

	if ((sortedFile = fopen("sort.txt", "r")) == NULL){
		return -57;
	}


	for (int i = 0; i < arrsize; i++)
		fscanf(sortedFile, "%c", &array[i]);
	
	fclose(sortedFile);

	if ((sortedFile = fopen("sort.txt", "a+")) == NULL){
		return -57;
	}
	
	printf("Quick Sort\n");
	start = clock();
	quickSort(array, 0, (arrsize - 1));
	end = clock();
	printSortOnScreen(array, arrsize, (double)(end - start));
	printSortToFile(sortedFile, array, arrsize, (double)(end - start));
	
	char element = getElement();
	
	printf("Linear Search\n");
	start = clock();
	int find = linearSearch(array, arrsize, element);
	end = clock();
	printSearchOnScreen(element, find, (double)(end - start));
	printSearchToFile(sortedFile, element, find, (double)(end - start));
	
	
	free(array);
	fclose(sortedFile);
	return 0;
}
