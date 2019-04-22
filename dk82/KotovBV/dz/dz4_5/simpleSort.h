#pragma once
#include "eArray.h"
#include "ellipse.h"
void bubbleSort(eArr* anArr);
void selectionSort(eArr* anArr);
void insertSort(eArr* anArr);
void swap(eArr* anArr, int a, int b);

void quickSort2(eArr* anArr, int aLeftIndex, int aRightIndex);
int m_partitionIt(eArr* anArr, int aLeftIndex, int aRightIndex, float aPivot);
void findArr(eArr* anArr, int area);