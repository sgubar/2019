#pragma once
#ifndef quickSort_h
#define quickSort_h

#include <stdio.h>

int partitionIt(char* anArray, int aLeftIndex, int aRightIndex, int aPivot);
void quickSort(char* anArray, int aLeftIndex, int aRightIndex);
void quickSort2(char* anArray, int aLeftIndex, int aRightIndex);

#endif /* quickSort_h */