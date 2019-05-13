#include "tool.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>


int lenght = 10000;

char* getArray(char* path_to_file)
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

void ShellSort(char* array)
{
	int i, j, step;
	int tmp;
	for (step =	lenght / 2; step > 0; step /= 2)
		for (i = step; i < lenght; i++)
		{
			tmp = array[i];
			for (j = i; j >= step; j -= step)
			{
				if (tmp < array[j - step])
					array[j] = array[j - step];
				else
					break;
			}
			array[j] = tmp;
		}
}

int linSearch(char* array, char key)
{
	for (int i = 0; i < lenght; i++)
	{
		if (array[i] == key)
			return i;
	}
	return -1;
}

