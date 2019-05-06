#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#ifndef __SORT_H
#define __SORT_H

void fileerror();

int getSize();
char getElement();

int chaosfillFile(FILE *file, const char filepath[], int lineSize);


void printSortOnScreen(char array[], int arraysize, double time);
void printSortToFile(FILE *sorted, char array[], int arraysize, double time);
void printSearchOnScreen(char element, int find, double time);
void printSearchToFile(FILE *sorted, char element, int find, double time);

int linearSearch(char *array, int size, char element);

void quickSort(char *array, int start, int end);
int partition(char *array, int start, int end);

#endif
