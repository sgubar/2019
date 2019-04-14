#include "Sort.h"


void bubbleSort(void *base, size_t baseSize, size_t elemSize, int (*comparator)(void *base, int indexA, int indexB)) {
	

	if (base == NULL || comparator == NULL || elemSize <= 0) {
		return ERROR;
	}

	if (baseSize == 0) {
		return;
	}


	for (int i = 0; i < baseSize - 1 ; i++)
	{
		for (int j = i; j < baseSize - 1; j++)
		{
			//printf(" i = %i, j = %i\n",i, j);
			if ((*comparator)(base,j,j+1) == 1) {
				if (swap(base, j, j + 1, elemSize) == ERROR) {
					printf("ERROR with bubbleSort\n");
					return ERROR;
				}
			}
		}
	}
}


void selectionSort(void *base, size_t baseSize, size_t elemSize, int(*comparator)(void *base, int indexA, int indexB)) {
	if (base == NULL || comparator == NULL || elemSize <= 0) {
		return ERROR;
	}

	if (baseSize == 0) {
		return;
	}

	int minIndex;

	for (int i = 0; i < baseSize - 1; i++)
	{
		minIndex = i;
		for (int j = i; j < baseSize; j++)
		{
			if ((*comparator)(base, i, j) == 1) {
				if (swap(base, i, j, elemSize) == ERROR) {
					printf("ERROR with bubbleSort\n");
					return ERROR;
				}
			}
		}
		swap(base,i,minIndex,elemSize);
	}
}

	void insertionSort(void *base, size_t baseSize, size_t elemSize, int(*comparator)(void *base, int indexA, int indexB)) {
		//printf("--------------DEBUG--------------\n");
		for (int i = 1; i < baseSize; i++)
		{
			int j = i;		
			//printf("\n%i\n", i);

			while (j > 0 && comparator(base,j-1,j) >= 0)
			{
				//printf("- ( %i ", j);
				swap(base, j, j - 1, elemSize);
				--j;
				//printf("- %i ) ", j);
			}
		}
	//	printf("\n---------------------------------\n");
	}


int swap(void *base, int indexA, int indexB, size_t elementSize) {
	if (base == NULL || indexA < 0 || indexB < 0 || elementSize <= 0) {
		return ERROR;
	}

	char *temp = malloc(elementSize);
	char *basePtr = (char*)base;

	memcpy(temp, (basePtr + elementSize * indexA), elementSize);
	memcpy((basePtr + elementSize * indexA), (basePtr + elementSize * indexB), elementSize);
	memcpy((basePtr + elementSize * indexB), temp, elementSize);

	return 1;
}
