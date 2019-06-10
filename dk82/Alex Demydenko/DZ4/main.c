#include "sort.h"

int main(int argc, char **argv)
{	
	int size = getSize();
	srand(time(NULL));
	
	Array *array = createCircleArray(size);                               
	
	for (int i = 0; i < size; i++)
	{
		Point A = {0 + rand() % 10, 0 + rand() % 10};
		Circle *OA = createCircleWithPoint(&A);
	
		addElement(array, OA);
	}
	
	printCircleArray(array);
	selectionSort(array, size);
	printCircleArray(array);
	
	destroyCircleArray(array); 
	
	return 0;
}
