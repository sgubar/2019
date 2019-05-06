#ifndef array_h
#define array_h

#include <stdio.h>
#include "tool.h"

FILE* fo;

typedef struct tagTrapArray
{
	int number;
	int count;

	Trapeze **traps;
}TrapArray;

TrapArray *createArray(int aNumber);
int addElement(TrapArray* anArray, Trapeze* aTrap);
void printArray(TrapArray* anArray);
void writeArrayToJSON(FILE* fo, TrapArray* anArray);
void freeArray(TrapArray* anArray);
void freeArray(TrapArray *anArray);
void bubblesort(TrapArray* anArray);


#endif
