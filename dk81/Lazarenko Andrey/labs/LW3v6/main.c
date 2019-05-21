#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tool.h"
#include <time.h>
#include <string.h>

int main(int argc, const char * argv[])
{
	int lengthOfString = lengthOfFile("dataR.txt");
	printf("Length: %d\n\n", lengthOfString);
	
	char *String_one = readStrFromFile();//1
	if (NULL != String_one)
	{
		bubbleSort(lengthOfString, String_one);
	}

	char *String_two = readStrFromFile();//2
	if (NULL != String_two)
	{
		selectionSort(lengthOfString, String_two);
	}

	char *String_three = readStrFromFile();//3
	if (NULL != String_three)
	{
		insertionSort(lengthOfString, String_three);
	}

	char *String_four = readStrFromFile();//4
	if (NULL != String_four)
	{
		clock_t begin = clock();
		quickSort(String_four, 0, lengthOfString);
		clock_t end = clock();
		
		printf("Time quicksort = %f\n", (double)(end - begin) / CLOCKS_PER_SEC);
		/*writeStrToFile(String_four);*/
	}
	

	char *String_five = readStrFromFile();//5
	if (NULL != String_five)
	{
		clock_t start_t = clock();
		int result = binarySearch(lengthOfString, String_four, 'z');
		clock_t end_t = clock();
		printf("\nBinaryresult: %d", result);
		printf("\nTime = %f\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);
	}

	FILE *fp = fopen("dataW.txt", "w");
	fputs(String_one, fp);
	fclose(fp);
	
	free(String_one);
	free(String_two);
	free(String_three);
	free(String_four);
	free(String_five);
	
	system("pause");
	return 0;
}