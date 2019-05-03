#include "tool.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>

void bubbleSort(Array *anArray)
	{
		if(NULL != anArray)
		{
		int i, j;
		Square* temp;
		
		for(i = anArray->number - 1; i>0; i--)
			{
				for(j = 0; j<i; j++)
					{
						if (areaOfsquare(anArray->squares[j]) > areaOfsquare(anArray->squares[j+1]))
							{
								temp = anArray->squares[j];
								anArray->squares[j] = anArray->squares[j+1];
								anArray->squares[j+1] = temp;
							}
					}
			}
		}
	}
	
void selectionSort(Array *anArray)
	{
		if(NULL != anArray)
		{
		int i, j;
		Square* temp;
		int minIndex;
		
		for (i = 0; i < anArray->number - 1; i++)
			{
				minIndex = i;
				
				for (j = i + 1; j < anArray->number; j++)
					{
						if (areaOfsquare(anArray->squares[j]) < areaOfsquare(anArray->squares[minIndex]))
							{
								minIndex = j;
							}
					}
				temp = anArray->squares[i];
				anArray->squares[i] = anArray->squares[minIndex];
				anArray->squares[minIndex] = temp;
			}
		}
	}

void insertionSort(Array *anArray)
	{
		if(NULL != anArray)
		{
		int i, j;
		Square* temp;
	
		for (i = 1; i < anArray->number; i++)
		{
			j = i;
			while (j > 0 && areaOfsquare(anArray->squares[j-1]) < areaOfsquare(anArray->squares[j]))
			{
				temp = anArray->squares[j-1];
				anArray->squares[j-1] = anArray->squares[j];
				anArray->squares[j] = temp;
				j--;
			}
		}
		}
	}

void shellSort(Array *anArray, int aCount)
{
	if(NULL != anArray)
	{
	int theInner = 0;
	int theOuter = 0;
	int theH = 1; // start h = 1
	
	//1. Calculate start value of h
	while (theH <= aCount/3)
	{
		theH = theH*3 + 1; // 1, 4, 13, 40, 121, ...
	}

	//2. Sequental decrease h to 1
	while (theH > 0)
	{
		for (theOuter = theH; theOuter < aCount; theOuter ++)
		{
			Square* theTmp = anArray->squares[theOuter];
			theInner = theOuter;
		
			// the first sub-array {0, 4, 8}
			while (theInner > theH-1 && areaOfsquare(anArray->squares[theInner - theH]) <= areaOfsquare(theTmp))
			{
				anArray->squares[theInner] = anArray->squares[theInner - theH];
				theInner -= theH;
			}
		
			anArray->squares[theInner] = theTmp;
		}
	
		theH = (theH - 1) / 3; //decrease h
	}
	}
}
