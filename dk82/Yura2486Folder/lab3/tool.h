#ifndef tool_h
#define tool_h
#include <stdio.h>
//FILE *fo;

void fillArray(char *dir, int lenght);
void shellSort(char *anArray, int lenght);
char *getArray(char *dir, int lenght);
int binarySearch(char key, char *anArray, int lenght);
void writeArray(char *dir, char *array, int lenght);

#endif

