#include "lib.h"

int fileSize(FILE *afile)
{
	int prev = ftell(afile);
	fseek(afile, 0l, SEEK_END);
	int size = ftell(afile);
	fseek(afile, prev, SEEK_SET);
	return size;
}

char* readFile(FILE *afile)
{
	int length = fileSize(afile);
	char* anArray = (char*)malloc(sizeof(char) * length);

	fgets(anArray, length, afile);
	fseek(afile, 0l, SEEK_SET);
		
	return anArray;
}


char* bubbleSort(char* anArray, int aSize)
{
	for (int theOut = aSize - 1; theOut > 1; theOut--)
	{
		for (int theIn = 0; theIn < theOut; theIn++)
		{
			if (anArray[theIn] > anArray[theIn - 1])
			{
				int theTmp = anArray[theIn];
				anArray[theIn] = anArray[theIn - 1];
				anArray[theIn - 1] = theTmp;
			}
		}
	}
	return anArray;
}

