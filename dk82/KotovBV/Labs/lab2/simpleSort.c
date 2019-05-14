#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "simpleSort.h"
#pragma warning(disable:4996)

void fillAr(int count)
{
	int rnd ;
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
	char* arr = (char*)malloc(sizeof(char)*count);
	int i = 0;
	fo = fopen("arr.txt", "rt");
	while (i!=count)
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
	printf("SORTED");
	for (int i = 0; i < count; i++)
		fprintf(fo, "%c", anArr[i]);
	printf("\n\n");
	fclose(fo);
}

void bubbleSort(char* anArr, int count)
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 1 ; j < count-i; j++)
		{
			if (anArr[j - 1] > anArr[j])
			{
				swap(anArr, j - 1, j);
			}
		}
	}
	printf("sorted\n");
}


void selectionSort(char* anArr, int count)
{
	for (int i = 0; i < count; i++)
	{
		int min = i;

		for (int j = 1 + i; j < count; j++)
		{
			if (anArr[min] > anArr[j])
				min = j;
		}
		swap(anArr, i, min);
	}
	printf("sorted\n");
}

void insertSort(char* anArr, int count)
{
	char theArr=' ';
	for (int i = 1; i < count; i++)
	{
		int j = i;
		theArr = anArr[i];
		while (j > 0 && theArr < anArr[j - 1])
		{
			anArr[j] = anArr[j - 1];
			j--;
		}
		anArr[j] = theArr;
	}
	printf("sorted\n");
}

void swap(char* anArr, int a, int b)
{
	char theArr;
	theArr = anArr[a];
	anArr[a] = anArr[b];
	anArr[b] = theArr;
}

void print(char* arr, int count)
{
	for (int i = 0; i < count; i++)
		printf("%c", arr[i]);
	printf("\n\n");
}