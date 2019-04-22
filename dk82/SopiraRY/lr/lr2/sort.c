#include "sort.h"

void fileerror()
{
	printf("###ERROR###\n\n\tFile could not be opened or created.\n\n");
}

char *copyArray(char *target, int size)
{
	char *copy = (char*)malloc(size*sizeof(char));
	if (NULL != copy)
	{
		for (int i = 0; i < size; i++)
			copy[i] = target[i];
	}
	return copy;
}

int chaosfillFile(FILE *file, const char filepath[], int lineSize)
{
	//wreaks havoc
	for (int i = 0; i < lineSize; i++)
	{
		int letterType = 0 + rand() % 2;
			
		if (letterType == 0){
			fprintf(file, "%c", ('A' + rand() % ('Z' - 'A' + 1)));
		}
		else{
			fprintf(file, "%c", ('a' + rand() % ('z' - 'a' + 1)));
		}
	}
	fprintf(file, "\n\n");
	return 0;
}

int printResults(FILE *file, const char filepath[], const char name[], char *array, int size, double time)
{
	fprintf(file, "Sort type: %s\nResult: ", name);
	for (int i = 0; i < size; i++)
	{
		fprintf(file, "%c", *array);
		array++;
	}
	fprintf(file, "\n");
	
	fprintf(file, "Array size: %d\nTime used in seconds: %f\n\n",
						size, (time/CLOCKS_PER_SEC));
	
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
			if (array[j] < array[i_min]) //< down, > up
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



