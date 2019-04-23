#include "tool.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

int binarySearch(char key, char *anArray, int lenght)
{
	int lowerBound = 0;
	int upperBound = lenght-1;
	int curIn = (lowerBound + upperBound)/2;
	int result = -1;
	
	while (1)
	{
		curIn = (lowerBound + upperBound)/2;
		if (anArray[curIn] == key)
		{
			result = curIn;
			break;
		}
		if (key < anArray[curIn])
		{
			lowerBound = curIn + 1;
		}
		if (key > anArray[curIn])
		{
			upperBound = curIn - 1;
		}
		if (lowerBound > upperBound)
		{
			break;
		}
	}
	return result;
}

void shellSort(char *anArray, int lenght)
{
	int theInner = 0;
	int theOuter = 0;
	int theH = 1; // start h = 1
	
	//1. Calculate start value of h
	while (theH <= lenght/3)
	{
		theH = theH*3 + 1; // 1, 4, 13, 40, 121, ...
	}

	//2. Sequental decrease h to 1
	while (theH > 0)
	{
		for (theOuter = theH; theOuter < lenght; theOuter ++)
		{
			char theTmp = anArray[theOuter];
			theInner = theOuter;
		
			// the first sub-array {0, 4, 8}
			while (theInner > theH-1 && anArray[theInner - theH] <= theTmp)
			{
				anArray[theInner] = anArray[theInner - theH];
				theInner -= theH;
			}
		
			anArray[theInner] = theTmp;
		}
	
		theH = (theH - 1) / 3; //decrease h
	}
}

void fillArray(char *dir, int lenght)
	{
		FILE *fo = fopen(dir, "w+");
		int i;
		int flag;
		
		srand (time(NULL));
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

char *getArray(char *dir, int lenght)
	{
		FILE *fo = fopen(dir, "rt");
		int i = 0;
		char *array = malloc(sizeof(char)*lenght);
		//fo = fopen("test.txt", "rt");
		while(i<lenght)
			{
				fscanf(fo, "%c", &array[i]);
				//printf("%c", array[i]);
				i++;
			}
		//printf("\n");
		fclose(fo);
		return array;
	}
	
void writeArray(char *dir, char *array, int lenght)
	{
		FILE *fo = fopen(dir, "at");
		fprintf(fo, "\nSorted array:\n");
		int i = 0;
		for(i; i<lenght; i++)
			{
				fprintf(fo, "%c", array[i]);
				//printf("%c", array[i]);
			}
			
		printf("\n\n\n");
		fclose(fo);
	}
