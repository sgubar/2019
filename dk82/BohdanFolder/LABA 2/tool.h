#ifndef tool_h
#define tool_h
#include <stdio.h>

FILE* fo;

void bubbleSort(char* array);
void selectionSort(char* array);
void insertionSort(char* array);
char* getArray(char* path_to_file);
void writeArray(char* array, char* path_to_file);

#endif