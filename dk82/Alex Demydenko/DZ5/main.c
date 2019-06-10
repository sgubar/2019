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
	shellSort(array, size);
	printCircleArray(array);
	
	int idx = linearSearch(array, size, getKey());
	if (idx != 0)
		printf("Found circle with that area!\nIndex is %d\n", idx);
	else
		printf("There is no circle with that area!\n");
	
	destroyCircleArray(array); 
	
	return 0;
}
