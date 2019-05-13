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
    Point *D;
}Rectangle;   //Triangle


Rectangle *createRectangle(Point *A, Point *B, Point *C, Point *D);

int CheckRectangle(Rectangle* rec);

void printRectangle(Rectangle* rec);

void destroyRectangle(Rectangle* rec);

#endif // HEADER_H
