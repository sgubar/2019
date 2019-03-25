#ifndef tool_h
#define tool_h
#include <stdio.h>

FILE *fo;

/*typedef struct
	{
	int timeOfExecution;
	int *result;
	}Result;
*/

void fillArray();
void bubbleSort(char *array1);
void selectionSort(char *array2);
void insertionSort(char *array);
char *getArray();
void writeArray(char *array);





#endif
