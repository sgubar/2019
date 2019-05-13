#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include "tool.h"

Point *copyPointWithPoint(Point *aPoint);
Point *createPointWithCoordinate(int x, int y);
 
Trapeze *createTrapeze(Point *A, Point *B, Point *C, Point *D)
{
	Trapeze *theresult = NULL;

	if (A != NULL && B != NULL && D != NULL && C != NULL)
	{
		theresult = (Trapeze*)malloc(sizeof(Trapeze));
		
		if (theresult != NULL)
		{
			theresult->A = copyPointWithPoint(A);
			theresult->B = copyPointWithPoint(B);
			theresult->C = copyPointWithPoint(C);
			theresult->D = copyPointWithPoint(D);
		}
	}
	return theresult;
}

Point *copyPointWithPoint(Point *aPoint)
{
	Point *theresult = (Point*)malloc(sizeof(Point));
	
	if (theresult != NULL)
	{
		theresult->x = aPoint->x;
		theresult->y = aPoint->y;
	}
	return theresult;
}

Trapeze *createTrapezeWithCoordinate(int xA, int xB, int xC, int xD, int yA, int yB, int yC, int yD)
{
	Trapeze* theresult = (Trapeze*)malloc(sizeof(Trapeze));
	
	if (theresult != NULL)
	{
		theresult->A = creatPointWithCoordinate(xA, yA);
		theresult->B = creatPointWithCoordinate(xB, yB);
		theresult->C = creatPointWithCoordinate(xC, yC);
		theresult->D = creatPointWithCoordinate(xD, yD);
	}
	return theresult;
}

Point *creatPointWithCoordinate(int x, int y)
{
	Point* theresult = (Point*)malloc(sizeof(Point));
	
	if (theresult != NULL)
	{
		theresult->x = x;
		theresult->y = y;
	}
		return theresult;
}

Trapeze *createTrapezewithArray(Point *array)
{
	Trapeze* theResult = NULL;
	
	if (array != NULL)
	{
		theResult = (Trapeze*)malloc(sizeof(Trapeze));
		
		if (theResult != NULL)
		{
			printf("%d,%d,%d,%d,%d,%d,%d,%d", array[0].x, array[0].y, array[1].x, array[1].y, array[2].x, array[2].y, array[3].x, array[3].y);
			
			theResult->A = copyPointWithPoint(&array[0]);
			theResult->B = copyPointWithPoint(&array[1]);
			theResult->C = copyPointWithPoint(&array[2]);
			theResult->D = copyPointWithPoint(&array[3]);
		}
	}
	return theResult;
}

double Trapeze_square(Trapeze* aTrapeze)
{
	double AB = 0, BC = 0, CD = 0, AD = 0, AC = 0, BD = 0;
	double square;

	double summ_diagonals;
	double sum_sides;
	if (aTrapeze != NULL)
	{
		AB = sqrt((double)pow(aTrapeze->B->x - aTrapeze->A->x, 2) + (double)pow(aTrapeze->B->y - aTrapeze->A->y, 2));//c

		BC = sqrt((double)pow(aTrapeze->C->x - aTrapeze->B->x, 2) + (double)pow(aTrapeze->C->y - aTrapeze->B->y, 2));//b

		CD = sqrt((double)pow(aTrapeze->D->x - aTrapeze->C->x, 2) + (double)pow(aTrapeze->D->y - aTrapeze->C->y, 2));//d

		AD = sqrt((double)pow(aTrapeze->D->x - aTrapeze->A->x, 2) + (double)pow(aTrapeze->D->y - aTrapeze->A->y, 2));//a

		BD = sqrt((double)pow(aTrapeze->D->x - aTrapeze->B->x, 2) + (double)pow(aTrapeze->D->y - aTrapeze->B->y, 2));//diagonal(1)

		AC = sqrt((double)pow(aTrapeze->C->x - aTrapeze->A->x, 2) + (double)pow(aTrapeze->C->y - aTrapeze->A->y, 2));//diagonal(2)
		//d1*d1 + d2*d2 = 2*a*b + c*c + d*d
		summ_diagonals = BD * BD + AC * AC;
		summ_diagonals =((int)(summ_diagonals * 100))/100;

		sum_sides = 2 * AD * BC + AB * AB + CD * CD;
		sum_sides = ((int)(sum_sides * 100)) / 100;
	}
	if (summ_diagonals != sum_sides)
	{
		printf("\nInvalid points for your trapeze.\n");

		return -1;
	}
	else 
	{
		double a;
		double semi_perimeter = (AB + BC + CD + AD)/2;
		a = ((AD + BC) / (abs(AD) - abs(BC))) * sqrt((semi_perimeter - AD) * (semi_perimeter - BC) * (semi_perimeter - AD - AB) * (semi_perimeter - AD - CD));
		square = abs(a);

		return square;
	}

}

void printTrapeze(Trapeze *aTrapeze)
{
	if (aTrapeze != NULL)
	{
		printf("[Trapeze]\nA([%d][%d])\nB([%d][%d])\nC([%d][%d])\nD([%d][%d])\n", aTrapeze->A->x,
			aTrapeze->A->y, aTrapeze->B->x, aTrapeze->B->y, aTrapeze->C->x, aTrapeze->C->y, aTrapeze->D->x, aTrapeze->D->y);
	}
}

void destroyTrapeze(Trapeze *aTrapeze)
{
	if (aTrapeze != NULL)
	{
		free(aTrapeze->A);
		free(aTrapeze->B);
		free(aTrapeze->C);
		free(aTrapeze->D);
		free(aTrapeze);
	}
}