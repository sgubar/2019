#include "tool.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define lenght 10

void fillArray()
	{
		int i;
		int flag;
		
		srand (time(NULL));
		fo = fopen("array.txt", "wt");
		//fprintf(fo, "[Unsorted array]\n\n");
		for(i = 0; i<lenght; i++)
			{
				flag = rand() % 2;
				if (flag == 0)
					{
						fprintf(fo, "%d", rand() % 10);
					}
				if (flag == 1)
					{
						fprintf(fo, "%c", rand()%26+97);
					}
				
			}
		fprintf(fo, "\n");
		fclose(fo);
	}

char *getArray()
	{
		int i = 0;
		char *array = malloc(sizeof(char)*lenght);
		fo = fopen("array.txt", "rt");
		while(i<lenght)
			{
				fscanf(fo, "%c", &array[i]);
				//printf("%c", array[i]);
				i++;
			} 
		fclose(fo);
		//printf("\n");
		return array;
	}
	
void writeArray(char *array)
	{
		int i;
		fo = fopen("array.txt", "at");
		for(i = 0; i<lenght; i++)
			{
				fprintf(fo, "%c", array[i]);
				printf("%c", array[i]);
			}
			
		fprintf(fo, "\n");
		printf("\n");
		fclose(fo);
	}
	
	

void bubbleSort(char *array1)
	{
		int i, j;
		char temp;
		
		for(i = lenght-1; i>0; i--)
			{
				for(j = 0; j<i; j++)
					{
						if (array1[j] < array1[j+1])
							{
								temp = array1[j];
								array1[j] = array1[j+1];
								array1[j+1] = temp;
							}
					}
			}
	}
	
void selectionSort(char *array2)
	{
		int i, j;
		char temp;
		int minIndex;
		
		for (i = 0; i < lenght - 1; i++)
			{
				minIndex = i;
				
				for (j = i + 1; j < lenght; j++)
					{
						if (array2[j] > array2[minIndex])
							{
								minIndex = j;
							}
					}
				temp = array2[i];
				array2[i] = array2[minIndex];
				array2[minIndex] = temp;
			}
	}

void insertionSort(char *array3)
{
	int i, j;
	char temp;
	
	for (i = 0; i < lenght; i++)
	{
		temp = array3[i];
		j = i-1;
		while (j >= 0 && array3[j] < temp)
		{
			array3[j+1] = array3[j];
			j--;
		}

		array3[j+1] = temp;
	}

}

