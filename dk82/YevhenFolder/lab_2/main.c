#include <stdio.h>
#include <stdlib.h>
#include "tool.h"
#include <time.h>
#define length 10000

int main()
{
	int arr1[length];

	fillArray(arr1, length);


	//Metod bulbashki//
	

	clock_t Start = clock();
	BubbleSort(arr1, length);
	clock_t End = clock();

	printArray(arr1, length);
	printf("\nTime of bubble sorting: %f seconds\n", (double)(End - Start) / CLK_TCK);
	printFail(arr1, length);
	


	//Metod viboru//
	
	/*
	clock_t Start = clock();
	ChoiceSort(arr1, length);
	clock_t End = clock();

	printArray(arr1, length);
	printf("\nTime of choice sorting: %f seconds\n", (double)(End - Start) / CLK_TCK);
	printFail(arr1, length);
	*/
	


	
	//Metod vstavki//	
	/*
	clock_t Start = clock();
	InsertSort(arr1, length);
	clock_t End = clock();

	printArray(arr1, length);
	printf("\nTime of insert sorting: %f seconds\n", (double)(End - Start) / CLK_TCK);
	printFail(arr1, length);
	
	*/

	system("PAUSE");



	return 0;

}
