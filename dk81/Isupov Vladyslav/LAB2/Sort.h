//
// Created by Владислав on 22.04.2019.
//

#ifndef LAB2_SORT_H
#define LAB2_SORT_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//sort
void bubleSort(char *String);
void choiseSort(char *String);
void insertSort(char *String);
//service
void writeRandTempToFile(int size, FILE *aFile);
void readTempFromFile(char *String, int size, FILE *aFile);
int scanWithChecking();


#endif //LAB2_SORT_H
