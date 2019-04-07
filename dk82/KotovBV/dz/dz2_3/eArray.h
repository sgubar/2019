#pragma once
#include <stdio.h>
#include "ellipse.h"



typedef struct ArrayOfEllipse
{
	int number;
	int count;
	Elips **ellipses;
}eArr;

eArr *createArray(int number);
void freeArray(eArr *anArray);
int addElement(eArr* anArray, Elips* aElips);
void writeArrayToJSON(FILE* aFile, eArr* anArray);
void printAr(eArr *anArray);
int addElInd(eArr* anArray, Elips* aElips, int numb);
