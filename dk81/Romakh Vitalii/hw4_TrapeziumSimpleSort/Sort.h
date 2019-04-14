#include <stdio.h>
#include "Meta.h"

void bubbleSort(void *base, size_t baseSize, size_t elemSize, int(*comparator)(void *base, int indexA, int indexB));
void selectionSort(void *base, size_t baseSize, size_t elemSize, int(*comparator)(void *base, int indexA, int indexB));
void insertionSort(void *base, size_t baseSize, size_t elemSize, int(*comparator)(void *base, int indexA, int indexB));

int  swap(void *base, int indexA, int indexB, size_t elementSize);
int change(void *base, int indexA, int indexB, size_t elementSize);