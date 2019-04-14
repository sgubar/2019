#include "tool.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>

void bubbleSort(Array *anArray)
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
	
void selectionSort(Array *anArray)
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

void insertionSort(Array *anArray)
	{
			int i, j;
		Square* temp;
	
		for (i = 1; i < anArray->number; i++)
		{
			j = i;
			while (j > 0 && areaOfsquare(anArray->squares[j-1]) > areaOfsquare(anArray->squares[j]))
			{
				temp = anArray->squares[j-1];
				anArray->squares[j-1] = anArray->squares[j];
				anArray->squares[j] = temp;
				j--;
			}
		}
	}
