#ifndef LUNA_TOOL_H_INCLUDED
#define LUNA_TOOL_H_INCLUDED
#include <stdio.h>
#include <time.h>


void Type_chooser( int mass[], int quantity, int type);
clock_t Bubble(int mass[], int quantity);
clock_t Select(int mass[], int quantity);
clock_t Insert(int mass[], int quantity);
void swap (int *x, int *y);
void random(int mass [], int quantity);
void Filewriter(int mass[], int quantity, char* name);


#endif // LUNA_TOOL_H_INCLUDED
