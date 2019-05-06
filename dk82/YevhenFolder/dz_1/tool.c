#include "tool.h"
#include <math.h>
#include <stdlib.h>

Point *CopyPointWithPoint(Point *aPoint);
Point *CreatPointByCoordinate(int x, int y);

Point* CopyPointWithPoint(Point* aPoint)
{
	Point* theResult = (Point*)malloc(sizeof(Point));
	if (NULL != theResult)
	{
		theResult->x = aPoint->x;
		theResult->y = aPoint->y;
	}
	return theResult;
}

Point* CreatPointByCoordinate(int x, int y)
{
	Point* theResult = (Point*)malloc(sizeof(Point));
	if (NULL != theResult)
	{
		theResult->x = x;
		theResult->y = y;
	}
	return theResult;
}
 
void printPrtr(Prtr* aPrtr)
{
	printf("Prtr through coordinato: \n");
	printf("\n A = (%d;%d) \n ", aPrtr->A->x, aPrtr->A->y);
	printf("B = (%d;%d) \n ", aPrtr->B->x, aPrtr->B->y);
	printf("C = (%d;%d) \n ", aPrtr->C->x, aPrtr->C->y);
}

float squarePrtr(Prtr* aPrtr)
{
	float AB = 0, BC = 0, AC = 0, Square;
	if (aPrtr != NULL)
	{
		AB = sqrt((float)pow(aPrtr->B->x - aPrtr->A->x, 2) + (float)pow(aPrtr->B->y - aPrtr->A->y, 2));

		BC = sqrt((float)pow(aPrtr->C->x - aPrtr->B->x, 2) + (float)pow(aPrtr->C->y - aPrtr->B->y, 2));

		AC = sqrt((float)pow(aPrtr->C->x - aPrtr->A->x, 2) + (float)pow(aPrtr->C->y - aPrtr->A->y, 2));

	}

	if (AB * AB + BC * BC != AC*AC)
	{
		printf("\nError\n");
		destroyPrtr(aPrtr);
		return 0;
	}
	else 
	{
		Square = (AB * BC) / 2;
		return Square;
	}
	
}

void destroyPrtr(Prtr* aPrtr)
{
	if (aPrtr != NULL )
	{
		free(aPrtr->A);
		free(aPrtr->B);
		free(aPrtr->C);

		free(aPrtr);
	}
}



Prtr* CreatePrtrByPoints(Point* A, Point* B, Point* C)
{

	Prtr* theResult = NULL;

	if (NULL != A && NULL != B && NULL != C )
	{
		theResult = (Prtr*)malloc(sizeof(Prtr));

		if (theResult != NULL)
		{
			theResult->A = CopyPointWithPoint(A);
			theResult->B = CopyPointWithPoint(B);
			theResult->C = CopyPointWithPoint(C);
		}
	}
	return theResult;
}

Prtr* CreatePrtrByCoordinates(int x1, int y1, int x2, int y2, int x3, int y3)
{
	Prtr* theResult = (Prtr*)malloc(sizeof(Prtr));

	if (theResult != 0)
	{
		theResult->A = CreatPointByCoordinate(x1, y1);
		theResult->B = CreatPointByCoordinate(x2, y2);
		theResult->C = CreatPointByCoordinate(x3, y3);
	}
	return theResult;
}
