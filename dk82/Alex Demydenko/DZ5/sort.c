#include "sort.h"

void shellSort(Array *CircleArray, int size) 
{ 
    for (int h = 1; h < size; h = 3*h + 1)
    {
        for (int i = h; i < size; i++)
        {
            Circle *temp_circle = CircleArray->array[i];
            
            int j;             
            for (j = i; j >= h && circleArea(CircleArray->array[j - h]) > circleArea(temp_circle); j -= h)
            {
                CircleArray->array[j] = CircleArray->array[j - h];
			}
              
            CircleArray->array[j] = temp_circle;
        }
    }
}

int linearSearch(Array *CircleArray, int size, const double keyArea)
{
	for (int i = 0; i < size; i++)
	{
		if (keyArea == circleArea(CircleArray->array[i]))
		{
			return i;
		}
	}
	return -1;
}

double getKey()
{
	double key;
	printf("Enter key:\n");
	do
	{
		scanf("%lf", &key);
	}
	while (key < 0);
	return key;
}
