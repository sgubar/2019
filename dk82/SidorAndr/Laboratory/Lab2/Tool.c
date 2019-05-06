#include "tool.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>
int lenght = 1000;



char* readFile( char* file)
{
	errno_t arr;
	int i = 0; 
	char* anArray = malloc(sizeof(char) * lenght);
	arr = fopen_s(&fo, file, "rt");
	if (arr == 0)
	{
		while (i < lenght)
		{
			fscanf_s(fo, "%c", &anArray[i], i++);
		}
	fclose(fo);
		return anArray;
	}
	else
	{
		printf("ERROR\n");
	}
}


void writeFile(char* anArray, char* file)
{
	fopen_s(&fo, file, "wt");
	{
		for (int i = 0; i < lenght; i++)
		{
			fprintf(fo, "%c", anArray[i]);
			printf("%c", anArray[i]);
		}
	fprintf(fo, "\n");
	printf("\n");
	fclose(fo);
	}
}

void bubbleSort(char* anArray)
{
	int i, j;
	char temp;
	

	for (i = lenght - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (anArray[j] < anArray[j + 1])
			{
				temp = anArray[j];
				anArray[j] = anArray[j + 1];
				anArray[j + 1] = temp;
			}
		}
	}
}

void vibirSort(char* anArray)
{
	int i, j, minIndex;
	char temp;
	

	for (i = 0; i < lenght - 1; i++)
	{
		minIndex = i;

		for (j = i + 1; j < lenght; j++)
		{
			if (anArray[j] < anArray[minIndex])
			{
				minIndex = j;
			}
		}
		temp = anArray[i];
		anArray[i] = anArray[minIndex];
		anArray[minIndex] = temp;
	}
}

void vstavkaSort(char* anArray)
{
	int i, j;
	char temp;

	for (i = 0; i < lenght; i++)
	{
		temp = anArray[i];
		j = i - 1;
		while (j >= 0 && anArray[j] > temp)
		{
			anArray[j + 1] = anArray[j];
			j--;
		}
	anArray[j + 1] = temp;
	}

}
