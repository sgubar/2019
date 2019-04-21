#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#ifndef __SORT_H
#define __SORT_H

void fileerror();
char *copyArray(char *target, int size);
int chaosfillFile(FILE *file, const char filepath[], int lineSize);
int printResults(FILE *file, const char filepath[], const char name[], char *array, int size, double time);
void bubbleSort(char *array, int size);
void selectionSort(char *array, int size);
void insertionSort(char *array, int size);

#endif
