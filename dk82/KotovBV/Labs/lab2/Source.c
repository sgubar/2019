#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "simpleSort.h"
#pragma warning(disable:4996)


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	int count;
	printf("Enter count of the array:");
	scanf_s("%d", &count);
	fillAr(count);
	char* arr1 = getArr(count);
	char* arr2 = getArr(count);
	char* arr3 = getArr(count);
	print(arr1,count);

	clock_t Start = clock();
	selectionSort(arr1,count);
	clock_t End = clock();
	printf("\nTime of selection sorting: %f seconds\nTime of selection sorting: %d steps\n\n",
		(double)(End - Start) / CLOCKS_PER_SEC, End - Start);
	print(arr1,count);
	

	Start = clock();
	bubbleSort(arr2, count);
	End = clock();
	printf("\nTime of bubble sorting: %f seconds\nTime of bubble sorting: %d steps\n\n",
		(double)(End - Start) / CLOCKS_PER_SEC, End - Start);
	print(arr2, count);


	Start = clock();
	insertSort(arr3, count);
	End = clock();
	printf("\nTime of insert sorting: %f seconds\nTime of insert sorting: %d steps\n\n",
		(double)(End - Start) / CLOCKS_PER_SEC, End - Start);
	print(arr3, count);
	
	
	fillFile(arr1, count);
	system("pause");
	return 0;
}