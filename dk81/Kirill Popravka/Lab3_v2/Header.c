#include "Header.h"

char randLetter(void)
{
	char base = 'A' + rand() % 26;
	if (rand() % 2) base = base + 32;
	
	return base;
}

char* randArray (int aSize) 
{
	srand(time(NULL));
	char* anArray = (char*) malloc( (aSize) * sizeof(char) );
	if (anArray != NULL)
	{
		for (int i = 0; i < aSize; i++) anArray[i] = randLetter();
		anArray[aSize] = '\0';
	}
	return anArray;
}

char* selectSort(char* anArray, int aSize)
{;
	for (int theOut = 0; theOut < aSize - 1; theOut++)
	{
		int theMinIndex = theOut;
		for (int theIn = theOut + 1; theIn < aSize; theIn++)
		{
			if (anArray[theIn] < anArray[theMinIndex])
			{
				theMinIndex = theIn;
			}
		}
		int theTmp = anArray[theOut];
		anArray[theOut] = anArray[theMinIndex];
		anArray[theMinIndex] = theTmp;
	}
	return anArray;
}

int binSearch(char* anArray, int aSize, char toFind)
{
	int left = 0;
	int right = aSize - 1;
	int middle = 0;

	while (left <= right)
	{
		int middle = (left + right) / 2;

		if (toFind < anArray[middle]) right = middle - 1;
		else if (toFind > anArray[middle]) left = middle + 1;
		else
		{
			return middle;
			break;
		}

		if (left > right) {
			return -1;
			printf("Are you alive ?\n");
		}
	}
}

void fileWrite(char* anArray, int id)
{	
	FILE* aFile;

	fopen_s(&aFile, "array.txt", "w+");

	if (NULL != aFile) {
		fprintf(aFile, "%s", anArray);
		fprintf(aFile, "\nBinary search id = %i", id);
		fclose(aFile);
	}
	else return;
}

void freeArray(char* anArray)
{
	if (NULL != anArray)
	{
		free(anArray);
	}
}
