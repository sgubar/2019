#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tool.h"
#include <time.h>

int lengthOfFile(char *aFile)
{
	FILE *fp = fopen(aFile, "r");
	if (fp != NULL)
	{
		int aSmb;
		int length = 0;
		do
		{
			aSmb = fgetc(fp);
			if (islower(aSmb) || isupper(aSmb))
			{
				length++;
			}
		} while (aSmb != EOF);
		fclose(fp);

		return length;
	}
	else
	{
		printf("File don't open\n");
		return 0;
	}
}

void selectionSort(int length, char *anArray)
{
	int theOut;
	clock_t begin = clock();
	for (theOut = 0; theOut < length - 1; theOut++)
	{
		int theMinIndex = theOut;
		int theIn;
		for (theIn = theOut + 1; theIn < length; theIn++)
		{
			if (anArray[theIn] > anArray[theMinIndex])
			{
				theMinIndex = theIn;
			}
		}

		char theTmp = anArray[theOut];
		anArray[theOut] = anArray[theMinIndex];
		anArray[theMinIndex] = theTmp;
	}
	clock_t end = clock();
	double ptr = end - begin;
	printf("Time selection sorting: %0.10lf\n", ptr / CLOCKS_PER_SEC);
}

void bubbleSort(int length, char *anArray)
{
	int theOut;
	clock_t begin = clock();
	for (theOut = length - 1; theOut > 0; theOut--)
	{
		int theIn;
		for (theIn = 0; theIn < theOut; theIn++)
		{
			if (anArray[theIn] < anArray[theIn + 1])
			{
				char theTmp = anArray[theIn];
				anArray[theIn] = anArray[theIn + 1];
				anArray[theIn + 1] = theTmp;
			}
		}
	}
	clock_t end = clock();
	double ptr = end - begin;
	printf("Time bubble sorting: %0.10lf\n", ptr / CLOCKS_PER_SEC);
}

void insertionSort(int length, char *anArray)
{
	int theOut;
	clock_t begin = clock();
	for (theOut = 1; theOut < length; theOut++)
	{
		char theTmp = anArray[theOut];
		int theIn = theOut;
		while (theIn > 0 && (anArray[theIn - 1] >= theTmp))
		{
			anArray[theIn] = anArray[theIn - 1];
			--theIn;
		}
		anArray[theIn] = theTmp;
	}
	clock_t end = clock();
	double ptr = end - begin;
	printf("Time insertion sorting: %0.10lf\n", ptr / CLOCKS_PER_SEC);
}

char *readStrFromFile(void)
{
	int length = lengthOfFile("dataR.txt");
	FILE *fp = fopen("dataR.txt", "r");

	char *str = (char *)malloc(sizeof(char)*(length + 1));
	int Smb;
	int index = 0;
	do
	{
		Smb = fgetc(fp);
		if (islower(Smb) || isupper(Smb))
		{
			str[index] = (char)Smb;
			index++;

		}
	} while (Smb != EOF);
	str[index] = '\0';
	fclose(fp);

	return str;
}

int binarySearch(int length, char *anArray, char find)
{
	int Left = 0;
	int Right = length;
	int middle = 0;
	int Result = -1;
	while (Left < Right)
	{
		middle = (Left + Right) / 2;
		if (anArray[middle] == find)
		{
			Result = middle;
			break;
		}
		else
		{
			if (anArray[middle] > find)
			{
				Right = middle - 1;
			}
			else
			{
				Left = middle + 1	;
			}
		}
	}
	return Result;
}

int partitionIt(char *anArray, int aLeftIndex, int aRightIndex, int aPivot)
{
	int theLeft = aLeftIndex - 1;
	int theRight = aRightIndex;

	while (1)
	{
		// search the bigest element
		while (anArray[++theLeft] < aPivot);

		// search the lowest element
		while (theRight > 0 && anArray[--theRight] > aPivot);

		if (theLeft >= theRight) // pointer are the same 
		{
			break;
		}
		else
		{
			//lets to swap elements
			int theTmp = anArray[theLeft];
			anArray[theLeft] = anArray[theRight];
			anArray[theRight] = theTmp;
		}
	}

	//lets to swap elements
	int theTmp = anArray[theLeft];
	anArray[theLeft] = anArray[aRightIndex];
	anArray[aRightIndex] = theTmp;

	return theLeft; // return break position
}

void quickSort(char *anArray, int aLeftIndex, int aRightIndex)
{
	if (aRightIndex - aLeftIndex <= 0)
	{
		return; // the array size equals to 1 - the array is fully sorted
	}

	int thePivot = anArray[aLeftIndex];
	int thePartitionIndex = partitionIt(anArray, aLeftIndex, aRightIndex, thePivot);

	//left part sorting
	quickSort(anArray, aLeftIndex, thePartitionIndex - 1);

	//right part sorting
	quickSort(anArray, thePartitionIndex + 1, aRightIndex);
}
	
void writeStrToFile(char *Srt)
{
	FILE *fp = fopen("dataW.txt", "w");
	fputs(Srt, fp);
	fclose(fp);
}