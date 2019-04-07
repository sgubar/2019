#include <stdio.h>
#include "ellipse.h"
#include "eArray.h"

eArr* createArray(int number)
{
	eArr* theResult = NULL;
	if (number > 0)
	{
		theResult = (eArr*)malloc(sizeof(eArr));
		if (theResult != NULL)
		{
			theResult->ellipses = (Elips * *)malloc(sizeof(Elips*) * number);
			if (theResult->ellipses != NULL)
			{
				theResult->number = number;
				theResult->count = 0;
			}
		}
		else
		{
			free(theResult);
			theResult = NULL;
		}
	}
	return theResult;
}


int addElement(eArr* anArray, Elips* aElips)
{
	int theResult = -1;
	if (anArray != NULL && aElips != NULL && anArray->count < anArray->number)
	{
		anArray->ellipses[anArray->count] = createElips(aElips->A, aElips->B, aElips->R);
		theResult = anArray->count;
		anArray->count++;
	}
	return theResult;
}


int addElInd(eArr* anArray, Elips* aElips, int numb)//добавить по индексу
{
	int theResult = -1;
	if (anArray != NULL && aElips != NULL && anArray->count < anArray->number && numb>=0 && numb<=anArray->count)
	{

		if (anArray->ellipses[anArray->count] == NULL)
		{
			anArray->ellipses[anArray->count] = createElips(aElips->A, aElips->B, aElips->R);
			theResult = anArray->count;
			anArray->count++;
		}
		else
		{

			for (int i = 0; i < (anArray->count - numb); i++)
			{
				anArray->ellipses[anArray->count - i] = anArray->ellipses[anArray->count - i - 1];
			}
			anArray->ellipses[numb] = createElips(aElips->A, aElips->B, aElips->R);
			anArray->count++;
		}
	}
	return theResult;
}


void writeArrayToJSON(FILE* aFile, eArr* anArray)
{
	if (aFile == NULL || anArray == NULL)
		return;
	fprintf(aFile, "{\n\"number\" : %d,\n\"count\" : %d,\n",
		anArray->number, anArray->count);
	fprintf(aFile, "\"ellipses\" : \n[\n");

	for (int i = 0; i < anArray->count; i++)
	{
		writeElipsToJSON(aFile, anArray->ellipses[i]);

		if (i < anArray->count - 1)
		{
			fprintf(aFile, ",");
		}
		fprintf(aFile, "\n");
	}

	fprintf(aFile, "]\n}");
}


void printAr(eArr* anArray)
{
	if (anArray != NULL)
	{
		printf("[EA]: number(%d), count(%d)", anArray->number, anArray->count);
		printf(", ellipses: \n");

		for (int i = 0; i < anArray->count; i++)
		{
			printElips(anArray->ellipses[i]);
		}
	}
	else return;
}

void freeArray(eArr* anArray)
{
	if (anArray != NULL)
	{
		for (int i = 0; i < anArray->count; i++)
			destroyElips(anArray->ellipses[i]);
		free(anArray->ellipses);
		free(anArray);
	}
}

