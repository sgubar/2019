#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char randLetter (void);
char* randArray (int);
char* selectSort(char*);
int binSearch(char*, int, char);
void fileWrite(char*);
void freeArray(char*);