#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dz5.h"

#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

void shellSort(Array *CircleArray, int size);
int linearSearch(Array *CircleArray, int size, const double keyArea);

double getKey();

#endif

