#include "sort.h"

void fileerror()
{
	printf("###ERROR###\n\n\tFile could not be opened or created.\n\n");
}

char *copyArray(char *target, int size)
{
	char *copy = (char*)malloc(size*sizeof(char));
	if (NULL != copy)
	{
		for (int i = 0; i < size; i++)
			copy[i] = target[i];
	}
	return copy;
}

//sorting algorithms
/*
void bubbleSort(Array *aTriangleArray, int size)
{
	Triangle *temp_triangle;
	temp_triangle = (Triangle*)malloc(sizeof(Triangle));
	
	for (int i = 0; i < size; i++)
	{		
		for (int j = size - 1; j > 0; j--)
		{
			if (array[j - 1] < array[j]) //< down, > up
			{
				*temp_triangle = aTriangleArray[j - 1];
				aTriangleArray[j - 1] = array[j];
				aTriangleArray[j] = *temp_triangle;
			}
		}
	}
}
*/

void selectionSort(Array *aTriangleArray, int size)
{
	Triangle *temp_triangle;
	//temp_triangle = (Triangle*)malloc(sizeof(Triangle));
	
	for (int i = 0; i < size - 1; i++)
	{
		int i_min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (triangleArea(aTriangleArray->array[j]) < triangleArea(aTriangleArray->array[i_min])) //< down, > up
			{
				i_min = j;
			}
		}
		
		if (i_min != i)
		{			
			temp_triangle = aTriangleArray->array[i];
			aTriangleArray->array[i] = aTriangleArray->array[i_min];
			aTriangleArray->array[i_min] = temp_triangle;
			i_min = i;
		}
	}
}

/*
void insertionSort(Array *aTriangleArray, int size)
{
	Triangle *temp_triangle;
	temp_triangle = (Triangle*)malloc(sizeof(Triangle));
	
	for (int i = 1; i < size; i++)
	{	
		*temp_triangle = aTriangleArray[i];
		
		for (int j = i - 1; j >= 0 && aTriangleArray[j] < *temp_triangle; j--) //< down, > up
		{
			aTriangleArray[j + 1] = aTriangleArray[j];
			aTriangleArray[j] = *temp_triangle;
		}
	}
}
*/
