#include "sort.h"

int getSize()
{
	int size;
	do
	{
		printf("Enter array size:\n");
		scanf("%d", &size);
		printf("\n");
	}
	while (size <= 0);
	return size;
}

char *copyArray(char *array, char *arraycopy, int size)
{
	if (NULL != array && NULL != arraycopy)
	{
		for (int i = 0; i < size; i++)
			arraycopy[i] = array[i];
	}
	return arraycopy;
}

void randomArray(FILE *unsortedarr, int arraysize)
{	
	for (int i = 0; i < arraysize; i++)
	{
		int type = 0 + rand() % 2;
			
		if (type == 0)
		{
			fprintf(unsortedarr, "%c", ('A' + rand() % ('Z' - 'A' + 1)));
		}
		else
		{
			fprintf(unsortedarr, "%c", ('a' + rand() % ('z' - 'a' + 1)));
		}
	}
	fprintf(unsortedarr, "\n");
}


void bubbleSort(char *array, int arraysize)
{
	char temporary_c;
	
	for (int i = 0; i < arraysize; i++)
	{		
		for (int j = arraysize - 1; j > 0; j--)
		{
			if (array[j - 1] < array[j]) 
			{
				temporary_c = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temporary_c;
			}
		}
	}
}

void selectionSort(char *array, int arraysize)
{
	char temporary_c;
	
	for (int i = 0; i < arraysize - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < arraysize; j++)
		{
			if (array[j] > array[minIndex]) 
			{
				minIndex = j;
			}
		}
		
		if (minIndex != i)
		{			
			temporary_c = array[i];
			array[i] = array[minIndex];
			array[minIndex] = temporary_c;
			minIndex = i;
		}
	}
}

void insertionSort(char *array, int arraysize)
{
	char temporary_c;
	
	for (int i = 1; i < arraysize; i++)
	{	
		temporary_c = array[i];
		
		for (int j = i - 1; j >= 0 && array[j] > temporary_c; j--) 
		{
			array[j + 1] = array [j];
			array[j] = temporary_c;
		}
	}
}

void printOnScreen(char *array, int arraysize, double time)
{	
	printf("Array: ");
	for (int i = 0; i < arraysize; i++)
		printf("%c", array[i]);
		
	printf("\n");
	printf("Time: %f\n\n", (time/CLOCKS_PER_SEC));
}

void printToFile(FILE *sorted, char *array, int arraysize, double time)
{	
	fprintf(sorted, "Array: ");
	for (int i = 0; i < arraysize; i++)
		fprintf(sorted, "%c", array[i]);
		
	fprintf(sorted, "\n");
	fprintf(sorted, "Time: %f\n\n", (time/CLOCKS_PER_SEC));
}
