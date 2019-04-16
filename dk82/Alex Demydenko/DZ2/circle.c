#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "circle.h"



float circleArea(Circle *aCircle)
{
//	float area =  3.14*pow((float)aCircle->radius, 2);
//	aCircle->area = 3.14*pow((float)aCircle->radius, 2);
	
	return  3.14*pow((float)aCircle->radius, 2);
}

Point *copyPointWithPoint(Point *aPoint)
{
	Point *theResult = (Point *)malloc(sizeof(Point));
	if (NULL != theResult)
	{
		theResult->x = aPoint->x;
		theResult->y = aPoint->y;
	}
	
	return theResult;
}
/*
Circle *createCircleWithPoint(Point *aPoint)
{
	Circle *theResult = NULL;
	
	if (NULL != aPoint)
	{
		theResult = (Circle*)malloc(sizeof(Circle));
		if (NULL != theResult)
		{
			theResult->A = copyPointWithPoint(aPoint);
			theResult->radius = circleRadius(theResult);
			theResult->area = circleArea(theResult);
		}
	}
	
	return theResult;
}*/

Circle *createCircleWithCenter(Point *aCenter, double radius)
{
	Circle *theResult = NULL;
	if (NULL != aCenter)
	{
		theResult = (Circle*)malloc(sizeof(Circle));
		if (NULL != theResult)
		{
			theResult->A = copyPointWithPoint(aCenter);
			theResult->radius = radius;
			theResult->area = circleArea(theResult);
		}
	}
	
	return theResult;
}

void printCircle(Circle *aCircle)
{
	if (NULL != aCircle)
	{
		printf ("*_*Circle*_*\n Center (%d, %d)\n Radius = %.2f\n Area = %.2f", 
				aCircle->A->x, aCircle->A->y,
				aCircle->radius, aCircle->area);
	}
}
	
void destroyCircle(Circle *aCircle)
{
	if (NULL != aCircle)
	{
		free(aCircle->A);
		free(aCircle);
	}
}
