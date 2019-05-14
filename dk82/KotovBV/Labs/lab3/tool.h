#pragma once
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#pragma warning(disable:4996)

FILE* fo;

void fillAr(int count);
char* getArr(int count);
void fillFile(char* anArr, int count);
void print(char* arr, int count);
void shellSort(int anArray[], int aCount);
int binarysearch(int a, int mass[], int n);