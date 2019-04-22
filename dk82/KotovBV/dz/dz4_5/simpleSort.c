#include "eArray.h"
#include "ellipse.h"
#include "simpleSort.h"


void bubbleSort(eArr* anArr)
{
	//Elips* anElips=NULL;
	for (int i = 0; i < anArr->count; i++)
	{
		for (int j = 1 ; j < anArr->count-i; j++)
		{
			if (areaElips(anArr->ellipses[j - 1]) < areaElips(anArr->ellipses[j]))
			{
				swap(anArr, j - 1, j);
			}
		}
	}
	printf("sorted");
}


void selectionSort(eArr* anArr)
{
	//Elips* anElips = NULL;
	for (int i = 0; i < anArr->count; i++)
	{
		int min = i;

		for (int j = 1+i; j < anArr->count; j++)
		{
			if (areaElips(anArr->ellipses[min]) > areaElips(anArr->ellipses[j]))
				min = j;
		}
		swap(anArr, i, min);
	}
}

void insertSort(eArr* anArr)
{
	Elips* anElips = NULL;
	for (int i = 1; i < anArr->count; i++)
	{
		int j = i;
		anElips = anArr->ellipses[i];
		while (j>0 && areaElips(anElips)< areaElips(anArr->ellipses[j-1]))
		{
			anArr->ellipses[j] = anArr->ellipses[j-1];
			j--;
		}
		anArr->ellipses[j] = anElips;
	}
}

void swap(eArr* anArr,int a,int b)
{
	Elips* anElips = NULL;
	anElips = anArr->ellipses[a];
	anArr->ellipses[a] = anArr->ellipses[b];
	anArr->ellipses[b] = anElips;
}





void quickSort2(eArr* anArr, int aLeftIndex, int aRightIndex)
{
	int theSize = aRightIndex - aLeftIndex + 1;

	if (theSize <= 1)
		return;
	float thePivot = 0.0;
	thePivot = areaElips(anArr->ellipses[aRightIndex]);
	int thePartitionIndex = m_partitionIt(anArr, aLeftIndex, aRightIndex, thePivot);

	//left part sorting
	quickSort2(anArr, aLeftIndex, thePartitionIndex - 1);

	//right part sorting
	quickSort2(anArr, thePartitionIndex + 1, aRightIndex);
	
	
}

int m_partitionIt(eArr* anArr, int aLeftIndex, int aRightIndex, float aPivot)
{
	if (aLeftIndex < aRightIndex)
	{
		int theLeft = aLeftIndex-1;
		int theRight = aRightIndex+1;

		while (1)
		{
			while (theLeft < aRightIndex && areaElips(anArr->ellipses[++theLeft]) < aPivot);
			while (theRight > 0 && areaElips(anArr->ellipses[--theRight]) > aPivot);

			if (theLeft >= theRight )
				break;
			else
				swap(anArr, theLeft, theRight);
		}
		return theLeft;
	}
	
}


void findArr(eArr* anArr,int area)
{
	_Bool a = 0;
	int coord = 0;
	for(int i=0;i<anArr->count;i++)
		if ((int)(areaElips(anArr->ellipses[i])) == area)
		{
			coord = i;
			a = 1;
		}
	if (a)
		printf("element is exist(%d)\n", coord);
	
}