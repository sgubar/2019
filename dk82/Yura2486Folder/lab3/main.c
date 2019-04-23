#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tool.h"
//#define lenght 12


int main(int argc, char *argv[]) {
	int lenght = 200000;
	char *dir = "C:/Users/User/Documents/Dev-c++/Lab_rob_3/test.txt";
	
	fillArray(dir, lenght);
	
	char *array1 = getArray(dir, lenght);
	
	clock_t inStart = clock();
	shellSort(array1, lenght);
	clock_t inEnd = clock();
	printf("Time of Shell sorting: %f seconds, %d steps\n\n",
		(double) (inEnd-inStart)/CLOCKS_PER_SEC, inEnd-inStart);
	writeArray(dir, array1, lenght);
	
	char key;
	printf("Enter key to find\n");
	scanf("%c", &key);
	inStart = clock();
	int index = binarySearch(key, array1, lenght);
	inEnd = clock();
	printf("Time of searching: %f seconds, %d steps\n\n",
		(double) (inEnd-inStart)/CLOCKS_PER_SEC, inEnd-inStart);
	
	if (index == -1)
	{
		printf("This element does not exist");
	}
	else
	{
		printf("Element has been found\nIndex: %d\n", index);
	}

	free(array1);
	return 0;
}

