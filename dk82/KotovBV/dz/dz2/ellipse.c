#include <stdlib.h>
#include "ellipse.h"
#include <math.h>
Elips *createElips(Point *A, Point *B, Point *R)
{
	Elips *theresult = NULL;
	if (A != NULL && B != NULL & R != NULL)
	{
		theresult = (Elips*)malloc(sizeof(Elips));
		if (theresult != NULL)
		{
			theresult->A = copyPointWithPoint(A);
			theresult->B = copyPointWithPoint(B);
			theresult->R = copyPointWithPoint(R);
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

void printElips(Elips *aElips)
{
	if (aElips != NULL)
	{
		printf("A([%d][%d]),\nB([%d][%d]),\nR([%d][%d])\n", aElips->A->x,
			aElips->A->y, aElips->B->x, aElips->B->y, aElips->R->x, aElips->R->y);
	}
}
void destroyElips(Elips *aElips)
{
	if (aElips != NULL)
	{
		free(aElips->A);
		free(aElips->B);
		free(aElips->R);
		free(aElips);
	}
}

float areaElips(Elips *aElips)
{
	float theresult = 0.0;
	if (aElips != NULL)
	{
		float dx1 = abc(aElips->R->x - aElips->A->x);
		float dy1 = abc(aElips->R->y - aElips->A->y);
		float dx2 = abc(aElips->R->x - aElips->B->x);
		float dy2 = abc(aElips->R->y - aElips->B->y);
		float line1 = sqrt(dx1*dx1 + dy1 * dy1);
		float line2 = sqrt(dx2*dx2 + dy2 * dy2);
		theresult = 3.14*line1*line2;
	}
	return theresult;
}
float abc(int x)
{
	return (x < 0) ? (-x) : x;
}