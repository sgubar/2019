#pragma once
#include "tool.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
triangle* createTriang(Point *A, Point *B, Point *C) //создаем треугольник по точкам
{

	if (proverka(A, B, C) == 1)
	{
		triangle* theresult = NULL;
		if (A != NULL && B != NULL && C != NULL)
		{
			theresult = (triangle*)malloc(sizeof(triangle));
			if (theresult != NULL)
			{
				theresult->A = copyPointWithPoint(A);
				theresult->B = copyPointWithPoint(B);
				theresult->C = copyPointWithPoint(C);
			}
		}
		return theresult;
	}
	else
	{
		printf("triangle was not created\n");
		return NULL;
	}
}
Point *copyPointWithPoint(Point *aPoint)//копирует коорд т.к. она может менятся
{
	Point *theresult = (Point*)malloc(sizeof(Point));
	if (theresult != NULL)
	{
		theresult->x = aPoint->x;
		theresult->y = aPoint->y;
	}
	return theresult;
}

triangle* createTriangWithCoordinate(int xA, int xB, int xR, int yA, int yB, int yR)//треугольник через коорд
{
	if (proverka(creatPointWithCoordinate(xR, yR), creatPointWithCoordinate(xA, yA), creatPointWithCoordinate(xB, yB)) == 1)
	{
		triangle* theresult = (triangle*)malloc(sizeof(triangle));
		if (theresult != NULL)
		{
			theresult->A = creatPointWithCoordinate(xA, yA);
			theresult->B = creatPointWithCoordinate(xB, yB);
			theresult->C = creatPointWithCoordinate(xR, yR);
		}
		return theresult;
	}
	else
	{
		printf("triangle with coordinate was not created\n");
		return NULL;
	}
}


Point *creatPointWithCoordinate(int x, int y)//преобразует в точки
{
	Point *theresult = (Point*)malloc(sizeof(Point));
	if (theresult != NULL)
	{
		theresult->x = x;
		theresult->y = y;
	}
	return theresult;
}


triangle* createTriangwithArray(Point *arr)//треугольник через массив
{
	if (proverka(&arr[0], &arr[1], &arr[2]) == 1) {
		triangle* theResult = NULL;
		if (arr != NULL)
		{
			theResult = (triangle*)malloc(sizeof(triangle));
			if (theResult != NULL)
			{
				theResult->A = copyPointWithPoint(&arr[0]);
				theResult->B = copyPointWithPoint(&arr[1]);
				theResult->C = copyPointWithPoint(&arr[2]);
			}
		}
		return theResult;
	}
	else
	{
		printf("triangle with array was not created\n");
		return NULL;
	}
}

void printTriangle(triangle *aTriang)
{
	if (aTriang != NULL)
	{
		printf("[Elips].\nA([%d][%d]),\nB([%d][%d]),\nR([%d][%d])\n", aTriang->A->x,
			aTriang->A->y, aTriang->B->x, aTriang->B->y, aTriang->C->x, aTriang->C->y);
	}
}
void destroyTriangle(triangle *aTriang)
{
	if (aTriang != NULL)
	{
		free(aTriang->A);
		free(aTriang->B);
		free(aTriang->C);
		free(aTriang);
	}
}
double areaTriangle(triangle *aTriang)//площадь
{
	double theResult = 0.0;
	if (aTriang != NULL) {
		double ab = sqrt(abc((aTriang->B->x - aTriang->A->x) ^ 2 + (aTriang->B->y - aTriang->A->y) ^ 2));
		double ac = sqrt(abc((aTriang->C->x - aTriang->A->x) ^ 2 + (aTriang->C->y - aTriang->A->y) ^ 2));
		double bc = sqrt(abc((aTriang->C->x - aTriang->B->x) ^ 2 + (aTriang->C->y - aTriang->B->y) ^ 2));
		double perim = ab + ac + bc;
		theResult = sqrt(perim*(perim - ab)*(perim - ac)*(perim - bc));
	}
	return theResult;
}
int proverka(Point *A, Point *B, Point *C)//проверка
{
	int k = 0;
	double ab = 0.0;
	double ac = 0.0;
	double bc = 0.0;
	
	ab = sqrt(abc((B->x - A->x) ^ 2 + (B->y - A->y) ^ 2));
	ac = sqrt(abc((C->x - A->x) ^ 2 + (C->y - A->y) ^ 2));
	bc = sqrt(abc((C->x - B->x) ^ 2 + (C->y - B->y) ^ 2));
	if ((ab < (ac + bc)) && (ac < (ab + bc)) && (bc < (ac + ab)))
		k = 1;
	else
		k = 2;
	return k;
}

double abc(int x)//модуль
{
	if (x < 0)
		x = -x;
	return x;
}