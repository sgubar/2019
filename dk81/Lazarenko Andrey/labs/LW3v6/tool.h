#pragma once

int lengthOfFile(char *name);
char *readStrFromFile(void);
void writeStrToFile(char *Srt);

void selectionSort(int length, char *anArray);
void bubbleSort(int length, char *anArray);
void insertionSort(int length, char *anArray);


int binarySearch(int length, char *anArray, char find);

void quickSort(char *anArray, int aLeftIndex, int aRightIndex);
int partitionIt(char *anArray, int aLeftIndex, int aRightIndex, int aPivot);