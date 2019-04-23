#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#ifndef __SORT_H
#define __SORT_H

int getSize();
char *copyArray(char *array, char *arraycopy, int size);
void randomArray(FILE *unsortedarr, int arraysize);
void printOnScreen(char array[], int arraysize, double time);
void printToFile(FILE *sorted, char array[], int arraysize, double time);

void bubbleSort(char array[], int arraysize);
void selectionSort(char array[], int arraysize);
void insertionSort(char array[], int arraysize);
//void copyarray( char* array, char* arraycopy,int arraysize)

#endif
