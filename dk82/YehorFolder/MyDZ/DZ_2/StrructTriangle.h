#ifndef STRUCTTRIAGLE_H_INCLUDED
#define STRUCTTRIAGLE_H_INCLUDED
#define ERROR (-1)

#include <stdio.h>


typedef struct tagPoint
{
    int x;
    int y;
}Point;

typedef struct tagTriangle{
Point *A;
Point *B;
Point *C;
}Triangle;

void printTriangle(Triangle* aTriangle);
void destroyTriangle(Triangle* aTriangle);
Triangle *CreateTriangleByPoints(Point* A,Point* B, Point* C);
Triangle *CreateTriangleByArray(Point* arr);
Triangle *CreateTriangleByCoordinates(int x1,int y1,int x2,int y2,int x3,int y3);
double TriangleSquare(Triangle* aTriangle);

#endif // STRUCTTRIAGLE_H_INCLUDED
