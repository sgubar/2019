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
Elips *createElipsWithCoordinate(int xA, int xB, int xR, int yA, int yB, int yR);
Point *creatPointWithCoordinate(int x, int y);
Elips *createElipswithArray(Point *arr);


void printElips(Elips *aElips);
void destroyElips(Elips *aElips);
float areaElips(Elips *aElips);
float abc(int x);
float perp(Point *A, Point *B, Point *C);
void writeElipsToJSON(FILE* aFile, Elips* aElips);
