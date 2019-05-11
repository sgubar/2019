#include <stdio.h>
#include <time.h>
#include "tool.h"



void fillArray(int arr[], int length) {

	srand(time(NULL));
	fopen_s(&fo, "D:\\sort.txt", "at");

	for (int i = 0; i < length; i++) 
	{
		arr[i] = rand() % 10000;
		fprintf(fo, "%i", arr[i]);
		
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


void printFail(int arr[], int length){
	fopen_s(&fo, "D:\\sort.txt", "wt");

	for (int i = 0; i < length; i++) 
	{
	fprintf(fo, "%i,", arr[i]);

	}
fprintf(fo, "\n");
fclose(fo);
}


void BubbleSort(int arr[], int length)
{
	int l, m;
	
	for ( l = length - 1; l > 0; l--)
	{
		for (m = 0; m < l; m++)
		{
			if (arr[m] > arr[m + 1])
			{
				int t = arr[m];
				arr[m] = arr[m + 1];
				arr[m + 1] = t;
			}
		}
	}
}




void ChoiceSort(int arr[], int length)
{
	int l, m;
	int t;
	int min;

	for (l = 0; l < length - 1; l++)
	{
		min = l;

		for (m = l + 1; m < length; m++)
		{
			if (arr[m] < arr[min])
			{
				min = m;
			}
		}
		t = arr[l];
		arr[l] = arr[min];
		arr[min] = t;
	}
}


void InsertSort(int arr[], int length)
{
	int l, m;
	int t;

	for (l = 0; l < length; l++)
	{
		t = arr[l];
		m = l - 1;
		while (m >= 0 && arr[m] > t)
		{
			arr[m + 1] = arr[m];
			m--;
		}

		arr[m + 1] = t;
	}

}
