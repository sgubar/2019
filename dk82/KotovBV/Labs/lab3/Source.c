#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tool.h"
#pragma warning(disable:4996)


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	int count,index=0;
	printf("Enter count of the array:");
	scanf_s("%d", &count);
	fillAr(count);
	char* arr1 = getArr(count);
	print(arr1, count);

	clock_t Start = clock();
	shellSort(arr1, count);
	clock_t End = clock();

	index = binarysearch('1', arr1, count);

	printf("\nTime of selection sorting: %f seconds\nTime of selection sorting: %d steps\n\n",
		(double)(End - Start) / CLOCKS_PER_SEC, End - Start);

	print(arr1, count);
	
	printf("\n\nindex=%d", index);
	fillFile(arr1, count);

	system("pause");
	return 0;
}