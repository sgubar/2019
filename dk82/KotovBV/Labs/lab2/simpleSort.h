#pragma once
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
FILE* fo;

void fillAr(int count);
char* getArr(int count);
void fillFile(char* anArr, int count);
void print(char* arr, int count);
void swap(char* anArr, int a, int b);
void bubbleSort(char* anArr, int count);
void selectionSort(char* anArr, int count);
void insertSort(char* anArr, int count);
