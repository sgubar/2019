#include "sort.h"

void fileerror()
{
	printf("###ERROR###\n\n\tFile could not be opened or created.\n\n");
}

char *copyArray(char *target, int size)
{
	char *copy = (char*)malloc(size*sizeof(char));
	char *p_copy;
	p_copy = copy;
	if (NULL != copy)
	{
		for (int i = 0; i < size; i++)
			copy[i] = target[i];
	}
	return p_copy;
}

int chaosfillFile(FILE *file, const char filepath[], int lineSize)
{
	
	/*if ((file = fopen(filepath, "a+")) == NULL){
		fileerror();
		return -1;
	}*/
	
	//wreaks havoc
	for (int i = 0; i < lineSize; i++)
	{
		int letterType = 0 + rand() % 2;
			
		if (letterType == 0)
		{
			fprintf(file, "%c", ('A' + rand() % ('Z' - 'A' + 1)));
		}
		else
		{
			fprintf(file, "%c", ('a' + rand() % ('z' - 'a' + 1)));
		}
	}
	fprintf(file, "\n\n");
	return 0;
}

int printResults(FILE *file, const char filepath[], const char name[], char *array, int size, double time)
{
	/*if ((file = fopen(filepath, "a+")) == NULL){
		fileerror();
		return -1;
	}*/
	
	fprintf(file, "Sort type: %s\nResult: ", name);
	for (int i = 0; i < size; i++)
	{
		fprintf(file, "%c", *array);
		array++;
	}
	fprintf(file, "\n");
	
	fprintf(file, "Time used in seconds: %f [ln(t) = %.2f]\nArray size: %d\n\n",
						(time/CLOCKS_PER_SEC), log((time/CLOCKS_PER_SEC)), size);
	
	return 0;
}

//sorting algorithms
void bubbleSort(char *array, int size)
{
	char *temp_c;
	temp_c = (char*)malloc(sizeof(char));
	
	for (int i = 0; i < size; i++)
	{		
		for (int j = size - 1; j > 0; j--)
		{
			if (array[j - 1] < array[j]) //< down, > up
			{
				*temp_c = array[j - 1];
				array[j - 1] = array[j];
				array[j] = *temp_c;
			}
		}
	}
}

void selectionSort(char *array, int size)
{
	char *temp_c;
	temp_c = (char*)malloc(sizeof(char));
	
	for (int i = 0; i < size - 1; i++)
	{
		int i_min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (array[j] > array[i_min]) //< down, > up
			{
				i_min = j;
			}
		}
		
		if (i_min != i)
		{			
			*temp_c = array[i];
			array[i] = array[i_min];
			array[i_min] = *temp_c;
			i_min = i;
		}
	}
}

void insertionSort(char *array, int size)
{
	char *temp_c;
	temp_c = (char*)malloc(sizeof(char));
	
	for (int i = 1; i < size; i++)
	{	
		*temp_c = array[i];
		
		for (int j = i - 1; j >= 0 && array[j] < *temp_c; j--) //< down, > up
		{
			array[j + 1] = array [j];
			array[j] = *temp_c;
		}
	}
}



