#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef DZ4_H_INCLUDED
#define DZ4_H_INCLUDED

typedef struct tagPoint
{
	int x;
	int y;
}Point;

typedef struct tagCircle
{
     Point *A;
     double radius;
     //double area;
}Circle;

typedef struct tagArray
{
	int count;
	int size;
	Circle **array;
}Array;

int getSize();

double circleRadius(Circle *aCircle);
double circleArea(Circle *aCircle);
Point *copyPointWithPoint(Point *aPoint);
Circle *copyCircle(Circle *aCircle);
Circle *createCircleWithPoint(Point *aPoint);

Array *createCircleArray(int size);
int addElement(Array *aCircleArray, Circle *aCircle);
int addElementAtIndex(Array *aCircleArray, Circle *aCircle, int index);
void destroyCircleArray(Array *aCircleArray);

void printCircle(Circle *aCircle);
void printCircleArray(Array *aCircleArray);
void destroyCircle(Circle *aCircle);
/*
void writeCircleToJSON(FILE *file, Circle *aCircle);
void writeArrayToJSON(FILE *file, Array *aCircleArray);
*/
#endif

