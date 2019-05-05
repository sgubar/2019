#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef __SORT_H
#define __SORT_H

void fileerror();

char *copyArray(char *target, int size);
int chaosfillFile(FILE *file, const char filepath[], int lineSize);
char randomLetter();
int sortResults(FILE *file, const char filepath[], const char name[], char *array, int size, double time);
int searchResults(FILE *file, const char filepath[], const char name[], const char key, int idx, double time);

int linearSearch(char *array, int size, char key);

void quickSort(char *array, int start, int end);
int partition(char *array, int start, int end);

#endif
