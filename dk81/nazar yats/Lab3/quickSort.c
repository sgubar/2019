
#include "quickSort.h"

static void swap(int anArray[], int aLeftIndex, int aRightIndex);
static int mediana(int anArray[], int aLeftIndex, int aRightIndex);
static int m_partitionIt(int anArray[], int aLeftIndex, int aRightIndex, int aPivot);
static void m_manualSort(int anArray[], int aLeftIndex, int aRightIndex);



int partitionIt(int anArray[], int aLeftIndex, int aRightIndex, int aPivot)
{
	int theLeft = aLeftIndex - 1;
	int theRight = aRightIndex;
	
	while (1)
	{
		////////////
		while (anArray[++theLeft] < aPivot);
	
		while (theRight > 0 && anArray[--theRight] > aPivot);
	///////////
		if (theLeft >= theRight) 
		{
			break;
		}
		else
		{
			int theTmp = anArray[theLeft];
			anArray[theLeft] = anArray[theRight];
			anArray[theRight] = theTmp;
		}
	}

	int theTmp = anArray[theLeft];
	anArray[theLeft] = anArray[aRightIndex];
	anArray[aRightIndex] = theTmp;
	
	return theLeft; 
}


void quickSort(int anArray[], int aLeftIndex, int aRightIndex)
{
	if (aRightIndex - aLeftIndex <= 0)
	{
		return; 
	}
	
	int thePivot = anArray[aRightIndex];
	int thePartitionIndex = partitionIt(anArray, aLeftIndex, aRightIndex, thePivot);
	
	quickSort(anArray, aLeftIndex, thePartitionIndex - 1);
	
	quickSort(anArray, thePartitionIndex + 1, aRightIndex);
}

void swap(int anArray[], int aLeftIndex, int aRightIndex)
{
	int theTmp = anArray[aLeftIndex];
	anArray[aLeftIndex] = anArray[aRightIndex];
	anArray[aRightIndex] = theTmp;
}

int mediana(int anArray[], int aLeftIndex, int aRightIndex)
{
	int theCenter = (aLeftIndex + aRightIndex) / 2;
	
	if (anArray[aLeftIndex] > anArray[theCenter])
	{
		swap(anArray, aLeftIndex, theCenter);
	}

	if (anArray[aLeftIndex] > anArray[aRightIndex])
	{
		swap(anArray, aLeftIndex, aRightIndex);
	}

	if (anArray[theCenter] > anArray[aRightIndex])
	{
		swap(anArray, theCenter, aRightIndex);
	}
	
	swap(anArray, theCenter, aRightIndex - 1);
	
	return anArray[aRightIndex - 1];
}

int m_partitionIt(int anArray[], int aLeftIndex, int aRightIndex, int aPivot)
{
	int theLeft = aLeftIndex;
	int theRight = aRightIndex - 1;
	
	while (1)
	{
		/////////////
		while (anArray[++theLeft] < aPivot);
	
		while (anArray[--theRight] > aPivot);
	//////////////////
	
		if (theLeft >= theRight)  
		{
			break;
		}
		else
		{
			swap(anArray, theLeft, theRight);
		}
	}

	swap(anArray, theLeft, aRightIndex - 1);
	
	return theLeft;
}

void quickSort2(int anArray[], int aLeftIndex, int aRightIndex)
{
	int theSize = aRightIndex - aLeftIndex + 1;
	
	if (theSize <= 3)
	{
		m_manualSort(anArray, aLeftIndex, aRightIndex);
	}
	else
	{
		int thePivot = mediana(anArray, aLeftIndex, aRightIndex);
		int thePartitionIndex = m_partitionIt(anArray, aLeftIndex, aRightIndex, thePivot);
		
		quickSort(anArray, aLeftIndex, thePartitionIndex - 1);
		
		quickSort(anArray, thePartitionIndex + 1, aRightIndex);
	}
}



void m_manualSort(int anArray[], int aLeftIndex, int aRightIndex)
{
	int theSize = aRightIndex - aLeftIndex + 1;
	
	if (theSize <= 1)
	{
		return;
	}
	
	if (2 == theSize)
	{
		if (anArray[aLeftIndex] > anArray[aRightIndex])
		{
			swap(anArray, aLeftIndex, aRightIndex);
		}
		return ;
	}
	else
	{
		// 3 elementes
		if (anArray[aLeftIndex] > anArray[aRightIndex - 1])
		{
			swap(anArray, aLeftIndex, aRightIndex - 1);
		}
	
		if (anArray[aLeftIndex] > anArray[aRightIndex])
		{
			swap(anArray, aLeftIndex, aRightIndex);
		}

		if (anArray[aRightIndex - 1] > anArray[aRightIndex])
		{
			swap(anArray, aRightIndex - 1, aRightIndex);
		}
	}
}
