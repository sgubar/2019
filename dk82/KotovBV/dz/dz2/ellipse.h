#pragma once
#include <stdio.h>

typedef struct tagpoint
{
	int x;
	int y;
}Point;


typedef struct tagElips
{
	Point *A;
	Point *B;
	Point *R;
}Elips;

Elips *createElips(Point *A, Point *B, Point *R);
Point *copyPointWithPoint(Point *aPoint);

void printElips(Elips *aElips);
void destroyElips(Elips *aElips);
float areaElips(Elips *aElips);
float abc(int x);