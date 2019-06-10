#include "sort.h"

void selectionSort(Array *CircleArray, int size)
{
	Circle *temp_circle;
	
	for (int i = 0; i < size - 1; i++)
	{
		int i_min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (circleArea(CircleArray->array[j]) > circleArea(CircleArray->array[i_min])) 
			{
				i_min = j;
			}
		}
		
		if (i_min != i)
		{			
			temp_circle = CircleArray->array[i];
			CircleArray->array[i] = CircleArray->array[i_min];
			CircleArray->array[i_min] = temp_circle;
			i_min = i;
		}
	}
}
