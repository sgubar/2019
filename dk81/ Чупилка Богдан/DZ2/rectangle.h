#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tagPoint
{
	int x;
	int y;
} Point;

typedef struct tagRectangle
{
	Point *A;
	Point *B;
	Point *C;
	Point *D;
} Rectangle;


Rectangle *createRectangle (Point *A, Point *B, Point *C, Point *D);
void destroyRectangle (Rectangle *aRectangle);

float areaRectangle (Rectangle *aRectangle);
void printRectangle (Rectangle *aRectangle);

void Enter_Coordinate (int *X, int *Y);
void Enter_Coordinate_Point_C (int *X, int *Y, int A_x, int A_y, int B_x, int B_y);

#endif


