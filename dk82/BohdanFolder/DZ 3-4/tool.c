#include "tool.h"
#include <math.h>
#include <stdlib.h>

Point* CopyPointWithPoint(Point* aPoint);
Point* CreatPointByCoordinate(int x, int y);

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

void printTrapeze(Trapeze* aTrapeze)
{
	printf("Trapeze through coordinató: \n");
	printf("\n A - (%d;%d) \n ", aTrapeze->A->x, aTrapeze->A->y);
	printf("B - (%d;%d) \n ", aTrapeze->B->x, aTrapeze->B->y);
	printf("C - (%d;%d) \n ", aTrapeze->C->x, aTrapeze->C->y);
	printf("D - (%d;%d) \n ", aTrapeze->D->x, aTrapeze->D->y);
}

float TrapezeSquare(Trapeze* aTrapeze)
{
	float Square;
	float AB = 0, BC = 0, CD = 0, DA = 0;
	if (aTrapeze != NULL)
	{
		AB = sqrt((double)pow(aTrapeze->B->x - aTrapeze->A->x, 2) + (double)pow(aTrapeze->B->y - aTrapeze->A->y, 2));
		BC = sqrt((double)pow(aTrapeze->C->x - aTrapeze->B->x, 2) + (double)pow(aTrapeze->C->y - aTrapeze->B->y, 2));
		CD = sqrt((double)pow(aTrapeze->D->x - aTrapeze->C->x, 2) + (double)pow(aTrapeze->D->y - aTrapeze->C->y, 2));
		DA = sqrt((double)pow(aTrapeze->A->x - aTrapeze->D->x, 2) + (double)pow(aTrapeze->A->y - aTrapeze->D->y, 2));

	}
	
	Square = ((BC + DA)/2) * (sqrt(pow(AB, 2) - (pow((pow(DA - BC, 2) + pow(AB, 2) - pow(CD, 2))/(2 * (DA - BC)), 2))));
	return Square;

}

int checkTrapeze(Trapeze* aTrapeze)
{

	float BC = 0, DA = 0;
	if (aTrapeze != NULL)
	{
		BC = sqrt((double)pow(aTrapeze->C->x - aTrapeze->B->x, 2) + (double)pow(aTrapeze->C->y - aTrapeze->B->y, 2));
		DA = sqrt((double)pow(aTrapeze->A->x - aTrapeze->D->x, 2) + (double)pow(aTrapeze->A->y - aTrapeze->D->y, 2));

	}
	if (BC > DA || BC == DA)
	{
		printf("Error");
		destroyTrapeze(aTrapeze);
		return 0;
	}
	else
	{
		return 1;
	}


}


void destroyTrapeze(Trapeze* aTrapeze)
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

Trapeze* CreateTrapezeByPoints(Point* A, Point* B, Point* C, Point* D)
{

	Trapeze* theResult = NULL;

	if (NULL != A && NULL != B && NULL != C && NULL != D)
	{
		theResult = (Trapeze*)malloc(sizeof(Trapeze));

		if (theResult != NULL)
		{
			theResult->A = CopyPointWithPoint(A);
			theResult->B = CopyPointWithPoint(B);
			theResult->C = CopyPointWithPoint(C);
			theResult->D = CopyPointWithPoint(D);
		}
	}
	return theResult;
}


Trapeze* CreateTrapezeByCoordinates(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	Trapeze* theResult = (Trapeze*)malloc(sizeof(Trapeze));

	if (theResult != 0)
	{
		theResult->A = CreatPointByCoordinate(x1, y1);
		theResult->B = CreatPointByCoordinate(x2, y2);
		theResult->C = CreatPointByCoordinate(x3, y3);
		theResult->D = CreatPointByCoordinate(x4, y4);
	}

	return theResult;
}

void writePointToJSON(FILE* aFile, Point* aPoint)
{
	if (NULL == aPoint || NULL == aFile)
	{
		return;
	}

	fprintf(aFile, "{\"x\" : %d, \"y\" : %d}", aPoint->x, aPoint->y);
}

void writeTrapToJSON(FILE* fo, Trapeze* aTrap)
{
	if (NULL == aTrap || NULL == fo)
	{
		return;
	}

	fprintf(fo, "{\n\"A\" : ");
	writePointToJSON(fo, aTrap->A);
	fprintf(fo, ", \n\"B\" : ");
	writePointToJSON(fo, aTrap->B);
	fprintf(fo, ", \n\"C\" : ");
	writePointToJSON(fo, aTrap->C);
	fprintf(fo, ", \n\"D\" : ");
	writePointToJSON(fo, aTrap->D);
	fprintf(fo, "\n}");
}