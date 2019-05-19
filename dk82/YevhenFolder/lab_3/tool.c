#include <stdio.h>
#include <time.h>
#include "tool.h"



void fillArray(int arr[], int length) {

	srand(time(NULL));
	fopen_s(&fo, "D:\\sort.txt", "at");

	for (int i = 0; i < length; i++)
	{
		arr[i] = rand() % 10000;
		fprintf(fo, "%i,", arr[i]);

	}
	fprintf(fo, "\n");
	fclose(fo);
}




void printArray(int arr[], int length) {
	for (int i = 0; i < length; i++)
	{
		printf(" %d ", arr[i]);
	}
}


void printFail(int arr[], int length) {
	fopen_s(&fo, "D:\\sort.txt", "wt");

	for (int i = 0; i < length; i++)
	{
		fprintf(fo, "%i,", arr[i]);

	}
	fprintf(fo, "\n");
	fclose(fo);
}


void shellSort(int arr[], int length)
{
	int l, m, n;
	int t;
	for (n = length / 2; n > 0; n /= 2)
		for (l = n; l < length; l++)
		{
			m = arr[l];
			for (m = l; m >= n; m -= n)
			{
				if (m < arr[m - n])
					arr[m] = arr[m - n];
				else
					break;
			}
			arr[m] = m;
		}
}

	int linSearch(int arr[], int length,  int key)
{
		

		for (int i = 0; i < length; i++)
		{
			if (arr[i] == key)
				return i;
		}
		return -1;
}
