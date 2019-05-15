#include "dk_tools.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>

void shellSort(Array *anArray)
{
	if(NULL != anArray)
	{
		int i;
		int j;
		int H = 1; 
	Trapeze* temp;
		while (H <= anArray->number/3)
		{
		H = H*3 + 1; 
		}

		while (H > 0)
		{
			for (i = H; i < anArray->number; i ++)
			{
				j = i;
		
				while (j > 0 && squareTrapeze(anArray->trapezes[j-1]) > squareTrapeze(anArray->trapezes[j]))
				{
					temp = anArray->trapezes[j-1];
					anArray->trapezes[j-1] = anArray->trapezes[j];
					anArray->trapezes[j] = temp;
					j--;
				}
			}
			H = (H - 1) / 3; 
		}
	}
}

void bubbleSort(Array *anArray)
	{
		int i, j;
		Trapeze* temp;
		
		for(i = anArray->number - 1; i>0; i--)
			{
				for(j = 0; j<i; j++)
					{
						if (squareTrapeze(anArray->trapezes[j]) > squareTrapeze(anArray->trapezes[j+1]))
							{
								temp = anArray->trapezes[j];
								anArray->trapezes[j] = anArray->trapezes[j+1];
								anArray->trapezes[j+1] = temp;
							}
					}
			}
	}
	
void selectionSort(Array *anArray)
	{
		int i, j;
		Trapeze* temp;
		int minIndex;
		
		for (i = 0; i < anArray->number - 1; i++)
			{
				minIndex = i;
				
				for (j = i + 1; j < anArray->number; j++)
					{
						if (squareTrapeze(anArray->trapezes[j]) < squareTrapeze(anArray->trapezes[minIndex]))
							{
								minIndex = j;
							}
					}
				temp = anArray->trapezes[i];
				anArray->trapezes[i] = anArray->trapezes[minIndex];
				anArray->trapezes[minIndex] = temp;
			}
	}

void insertionSort(Array *anArray)
	{
		int i, j;
		Trapeze* temp;
	
		for (i = 1; i < anArray->number; i++)
		{
			j = i;
			while (j > 0 && squareTrapeze(anArray->trapezes[j-1]) > squareTrapeze(anArray->trapezes[j]))
			{
				temp = anArray->trapezes[j-1];
				anArray->trapezes[j-1] = anArray->trapezes[j];
				anArray->trapezes[j] = temp;
				j--;
			}
		}
	}
	

