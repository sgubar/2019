#include "array.h"
#include <stdlib.h>


TrapArray* createArray(int aNumber)
{
	TrapArray* theResult = NULL;

	if (aNumber > 0)
	{
		theResult = (TrapArray*)malloc(sizeof(TrapArray));

		if (NULL != theResult)
		{
			theResult->traps = (Trapeze * *)malloc(sizeof(Trapeze*) * aNumber);

			if (NULL != theResult->traps)
			{
				theResult->number = aNumber;
				theResult->count = 0;
			}

			else
			{
				free(theResult);
				theResult = NULL;
			}
		}
	}
	return theResult;
}


int addElement(TrapArray* anArray, Trapeze* aTrap)
{
	int theResult = -1;

	if (anArray->count < anArray->number && NULL != anArray && NULL != aTrap && 1 == checkTrapeze(aTrap))
	{
		anArray->traps[anArray->count] = CreateTrapezeByPoints(aTrap->A, aTrap->B, aTrap->C, aTrap->D);
		theResult = anArray->count;
		anArray->count++;
	}
	return theResult;
}

void printArray(TrapArray* anArray)
{
	int i;
	if (NULL == anArray)
	{
		return;
	}

	printf("[TA]: number(%d), count(%d)", anArray->number, anArray->count);
	printf(", traps: \n");

	for ( i = 0; i < anArray->count; i++)
	{
		printTrapeze(anArray->traps[i]);
	}
}


void freeArray(TrapArray* anArray)
{
	int i;
	if (NULL != anArray)
	{
		for ( i = 0; i < anArray->count; i++)
		{
			destroyTrapeze(anArray->traps[i]);
		}

		free(anArray->traps);
		free(anArray);
	}
}

void writeArrayToJSON(FILE* fo, TrapArray* anArray)
{
	int i;
	if (NULL == anArray || NULL == fo)
	{
		return;
	}

	fprintf(fo, "{\n\"number\" : %d,\n\"count\" : %d,\n",
		anArray->number, anArray->count);
	fprintf(fo, "\"traps\" : \n[\n");

	for ( i = 0; i < anArray->count; i++)
	{
		writeTrapToJSON(fo, anArray->traps[i]);

		if (i < anArray->count - 1)
		{
			fprintf(fo, ",");
		}
		fprintf(fo, "\n");
	}

	fprintf(fo, "]\n}");
}

void bubblesort(TrapArray* anArray)
{
	int theOut;
	int theIn;
	if (NULL == anArray || 0 == anArray->count)
	{
		return;
	}

	for ( theOut = anArray->count - 1; theOut > 1; theOut--)
	{
		for ( theIn = 0; theIn < theOut; theIn++)
		{
			if (TrapezeSquare(anArray->traps[theIn]) > TrapezeSquare(anArray->traps[theIn + 1]))
			{
				Trapeze *theTemp = anArray->traps[theIn];
				anArray->traps[theIn] = anArray->traps[theIn + 1];
				anArray->traps[theIn + 1] = theTemp;
			}
		}
	}
}
