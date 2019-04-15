#include "tool.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>


int lenght = 2048;

char* getArray(char *path_to_file)
{
	errno_t err;
	int i = 0;
	char* array = malloc(sizeof(char) * lenght);
	err = fopen_s(&fo, path_to_file, "rt");
	if (err == 0)
	{
		while (i < lenght)
		{
			fscanf_s(fo, "%c", &array[i]);
			i++;
		}

		fclose(fo);
		return array;
	}
	else
	{
		printf("Wrong file path\n");
	}

}


void writeArray(char* array, char* path_to_file)
{
	
	int i;
	fopen_s(&fo, path_to_file, "at");
	
	{
		for (i = 0; i < lenght; i++)
		{
			fprintf(fo, "%c", array[i]);
			printf("%c", array[i]);
		}

		fprintf(fo, "\n");
		printf("\n");
		fclose(fo);
	}

}

void bubbleSort(char* array)
{
	int i, j;
	char temp;

	for (i = lenght - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] < array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void selectionSort(char* array)
{
	int i, j;
	char temp;
	int minIndex;

	for (i = 0; i < lenght - 1; i++)
	{
		minIndex = i;

		for (j = i + 1; j < lenght; j++)
		{
			if (array[j] > array[minIndex])
			{
				minIndex = j;
			}
		}
		temp = array[i];
		array[i] = array[minIndex];
		array[minIndex] = temp;
	}
}

void insertionSort(char* array)
{
	int i, j;
	char temp;

	for (i = 0; i < lenght; i++)
	{
		temp = array[i];
		j = i - 1;
		while (j >= 0 && array[j] < temp)
		{
			array[j + 1] = array[j];
			j--;
		}

		array[j + 1] = temp;
	}

}