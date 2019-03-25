#ifndef tool_h
#define tool_h
#include <stdio.h>

FILE *fo;

typedef struct
	{
	int timeOfExecution;
	int *result;
	}Result;

void fillArray();
char bubbleSort(char *array1);
char selectionSort(char *array2);
char insertionSort(char *array);
char *getArray();
void writeArray(char *array);





#endif
