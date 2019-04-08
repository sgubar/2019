#ifndef ARRAY_H
#define ARRAY_H

#include "header.h"

typedef struct tagTriangleArray
{
    int number;
    int count;

    Triangle **triang;
}TriangleArray;



TriangleArray *createArray(int anumber);
void destroyArray(TriangleArray *array);



int addTriang(TriangleArray *NTriang, Point *A, Point *B, Point *C);



int printArray(TriangleArray *Array);
void writeJSON(FILE *file, TriangleArray *array);


#endif // ARRAY_H
