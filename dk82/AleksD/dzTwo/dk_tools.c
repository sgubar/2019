#include "dk_tools.h"
#include <stdlib.h>
#include <math.h>

Point* copyPointWithPoint(Point* aPoint);
Point* creatPointWithCoordinate(int x, int y);

Trapeze* createTrapeze(Point* A, Point* B , Point* C , Point* D)
{
	Trapeze* theResult = NULL;

	if (NULL != A && NULL != B && NULL != C && NULL != D)
	{
		theResult = (Trapeze*)malloc(sizeof(Trapeze));
		if (NULL != theResult)
		{
			theResult->A = copyPointWithPoint(A);
			theResult->B = copyPointWithPoint(B);
			theResult->C = copyPointWithPoint(C);
			theResult->D = copyPointWithPoint(D);
		}
	}

	return theResult;
}

Trapeze* createTrapezeWithCoordinate(int xA, int yA, int xB, int yB, int xC, int yC, int xD, int yD)
{
	Trapeze* theResult = (Trapeze*)malloc(sizeof(Trapeze));

	if (NULL != theResult)
	{
		theResult->A = creatPointWithCoordinate(xA, yA);
		theResult->B = creatPointWithCoordinate(xB, yB);
		theResult->C = creatPointWithCoordinate(xC, yC);
		theResult->D = creatPointWithCoordinate(xD, yD);
	}

	return theResult;
}
Trapeze* createTrapezeWithArrayOfPoint (Point* arrayOfPoint)
{
	Trapeze* theResult = (Trapeze*)malloc(sizeof(Trapeze));
	if (theResult != NULL)
	{
		theResult -> A = copyPointWithPoint(&arrayOfPoint[0]);
		theResult -> B = copyPointWithPoint(&arrayOfPoint[1]);
 		theResult -> C = copyPointWithPoint(&arrayOfPoint[2]);
		theResult -> D = copyPointWithPoint(&arrayOfPoint[3]);
	}
	return theResult;
}



void destroyTrapeze(Trapeze* aTrapeze)
{
	if (NULL != aTrapeze)
	{
		free(aTrapeze->A);
		free(aTrapeze->B);
		free(aTrapeze->C);
		free(aTrapeze->D);
		free(aTrapeze);
	}
}

float squareTrapeze(Trapeze* aTrapeze)
{
	double theLengthUp = 0.0;
	double theLengthDown = 0.0;
	double theResult = 0.0;
	double Down_minus_Up = 0.0;
	double theLengthLeft = 0;
	double h = 0.0;	
	double flag = 0;
	if (NULL != aTrapeze)
	{
		double dUpX = (double)(aTrapeze->C->x - aTrapeze->B->x);
		double dUpY = (double)(aTrapeze->C->y - aTrapeze->B->y);
		double dDownX = (double)(aTrapeze->D->x - aTrapeze->A->x);
		double dDownY = (double)(aTrapeze->D->y - aTrapeze->A->y);
		double dLeftX = (double)(aTrapeze->B->x - aTrapeze->A->x);
		double dLeftY = (double)(aTrapeze->B->y - aTrapeze->A->y);
		theLengthLeft = sqrt(dLeftX * dLeftX + dLeftY * dLeftY);
		theLengthUp = sqrt(dUpX * dUpX + dUpY * dUpY);
		theLengthDown = sqrt(dDownX * dDownX + dDownY * dDownY);
		Down_minus_Up = (theLengthDown - theLengthUp) / 2;
		h = sqrt(theLengthLeft * theLengthLeft - Down_minus_Up * Down_minus_Up);
		theResult = ((theLengthUp + theLengthDown) / 2) * h;
	}

	return theResult;
}

void printTrapeze(Trapeze * aTrapeze)
{
	if (NULL != aTrapeze)
	{
		printf("[Trapeze]. A(%d,%d) - B(%d,%d) - C(%d,%d) - D(%d,%d)\n",
			aTrapeze->A->x, aTrapeze->A->y,
			aTrapeze->B->x, aTrapeze->B->y,
			aTrapeze->C->x, aTrapeze->C->y,
			aTrapeze->D->x, aTrapeze->D->y);
	}
}

Point* copyPointWithPoint(Point * aPoint)
{
	Point* theResult = (Point*)malloc(sizeof(Point));
	if (NULL != theResult)
	{
		theResult->x = aPoint->x;
		theResult->y = aPoint->y;
	}

	return theResult;
}

Point* creatPointWithCoordinate(int x, int y)
{
	Point* theResult = (Point*)malloc(sizeof(Point));
	if (NULL != theResult)
	{
		theResult->x = x;
		theResult->y = y;
	}

	return theResult;
}
