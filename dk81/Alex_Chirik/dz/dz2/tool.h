#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef struct tagpoint
{
	int x;
	int y;
}Point;


typedef struct tagtriangle
{
	Point *A;
	Point *B;
	Point *C;
}triangle;

triangle *createTriang(Point *A, Point *B, Point *C);
Point *copyPointWithPoint(Point *aPoint);
triangle *createTriangWithCoordinate(int xA, int xB, int xR, int yA, int yB, int yR);
Point *creatPointWithCoordinate(int x, int y);
triangle *createTriangwithArray(Point *arr);


void printTriangle(triangle *aTriang);
void destroyTriangle(triangle *aTriang);
double areaTriangle(triangle *Triang);
double abc(int x);
int proverka(Point *A, Point *B, Point *C);