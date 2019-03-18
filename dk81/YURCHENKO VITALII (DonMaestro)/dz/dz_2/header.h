#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct tagPoint
{
    int x;
    int y;
}Point;

typedef struct tagLine
{
    Point *A;
    Point *B;
    Point *C;
}Triangle;


Triangle *createTriangle(Point *A, Point *B, Point *C);

int CheckTriangle(Triangle* trian);

void printTriangle(Triangle* trian);

void destroyTriangle(Triangle* trian);

#endif // HEADER_H
