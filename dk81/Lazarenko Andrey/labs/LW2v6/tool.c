#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tool.h"
#include <time.h>

int lengthOfFile(char *aFile)
{
	FILE *fp= fopen(aFile, "r");
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
			if (anArray[theIn] < anArray[theMinIndex])
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
			if (anArray[theIn] > anArray[theIn + 1])
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

void writeStrToFile(char *Srt)
{
	FILE *fp = fopen("dataW.txt", "w");
	fputs(Srt, fp);
	fclose(fp);
}