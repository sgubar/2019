#include <stdio.h>
#include <stdlib.h>
#include "tool.h"
#include <time.h>
#define length 30000

int main()
{
	int arr1[length];
	int key = 8;

	fillArray(arr1, length);
	
	clock_t start = clock();
	shellSort(arr1, length );
	clock_t end = clock();
	printArray(arr1, length);
	printf("\nTime of shell sorting: %f seconds\n",(float)(end - start) / CLK_TCK);
	printFail(arr1, length);
	

	
	int result = linSearch(arr1, length, key);

	linSearch(arr1, length, key);

	if (result != -1)
	{
		printf("Znachennya : %d\n", result + 1);
	}
	else
	{
		printf("Element ne naydeno\n");
	}

	

	system("PAUSE");



	return 0;

}
