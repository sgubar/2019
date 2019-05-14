#pragma warning(disable:4996)
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tool.h"
void fillAr(int count)
{
	int rnd;
	fo = fopen("arr.txt", "wt");
	//printf("%d", count);
	for (int i = 0; i < count; i++) {
		rnd = 48 + rand() % 72;
		fprintf(fo, "%c", rnd);
		//printf("%c\n", rnd);
	}
	fclose(fo);
}


char* getArr(int count)
{
	char* arr = (char*)malloc(sizeof(char) * count);
	int i = 0;
	fo = fopen("arr.txt", "rt");
	while (i != count)
	{
		fscanf(fo, "%c", &arr[i]);
		i++;
	}

	fclose(fo);
	return arr;
}

void fillFile(char* anArr, int count)
{
	fo = fopen("result.txt", "wt");
	printf("\nSORTED");
	for (int i = 0; i < count; i++)
		fprintf(fo, "%c", anArr[i]);
	printf("\n\n");
	fclose(fo);
}

void print(char* arr, int count)
{
	for (int i = 0; i < count; i++)
		printf("%c", arr[i]);
	printf("\n\n");
}


int binarysearch(char a, char mass[], int n)
{
	int low, high, middle;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		middle = (low + high) / 2;
		if (a < mass[middle])
			high = middle - 1;
		else if (a > mass[middle])
			low = middle + 1;
		else
			return middle+1;
	}
	return -1;
}





void shellSort(char anArray[], int aCount)
{
	int theInner = 0;
	int theOuter = 0;
	int theH = 1; // start h = 1

	//1. Calculate start value of h
	while (theH <= aCount / 3)
	{
		theH = theH * 3 + 1; // 1, 4, 13, 40, 121, ....
	}

	//2. Sequental decrease h to 1
	while (theH > 0)
	{
		for (theOuter = theH; theOuter < aCount; theOuter++)
		{
			int theTmp = anArray[theOuter];
			theInner = theOuter;

			// the first sub-array {0, 4, 8}
			while (theInner > theH - 1 && anArray[theInner - theH] <= theTmp)
			{
				anArray[theInner] = anArray[theInner - theH];
				theInner -= theH;
			}

			anArray[theInner] = theTmp;
		}

		theH = (theH - 1) / 3; //decrease h
	}
}