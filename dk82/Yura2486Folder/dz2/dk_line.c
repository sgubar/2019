#include "square.h"
#include <stdlib.h>
#include <math.h>
Point *copyPointWithPoint(Point *aPoint);

Square *createSquare(Point *A, Point *B, Point *C, Point *D)
{
	Square *theResult = NULL;
	
	if (NULL != A && NULL != B && NULL != C && NULL != D)
	{
		theResult = (Square *)malloc(sizeof(Square));
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

void printSquare(Square *aSquare)
{
	if (NULL != aSquare)
	{
		printf ("[Square]. A(%d,%d) B(%d,%d) C(%d,%d) D(%d,%d)\n",
					aSquare->A->x, aSquare->A->y,
					aSquare->B->x, aSquare->B->y,
					aSquare->C->x, aSquare->C->y,
					aSquare->D->x, aSquare->D->y);
	}
}


