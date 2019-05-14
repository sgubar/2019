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
		summ_diagonals = ((int)(summ_diagonals * 100)) / 100;

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
		double semi_perimeter = (AB + BC + CD + AD) / 2;
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

TrapezeArray* createArray(int number)
{
	TrapezeArray* theResult = NULL;

	if (number > 0)
	{
		theResult = (TrapezeArray*)malloc(sizeof(TrapezeArray));

		if (theResult != NULL)
		{
			theResult->trapezes = (Trapeze **)malloc(sizeof(Trapeze*) * number);

			if (theResult->trapezes != NULL)
			{
				theResult->number = number;
				theResult->count = 0;
			}
		}
		else
		{
			free(theResult);
			theResult = NULL;
		}
	}

	return theResult;
}


int AddElement(TrapezeArray* anArray, Trapeze* aTrapeze)
{
	int theResult = -1;

	if (anArray != NULL && aTrapeze != NULL && anArray->count < anArray->number)
	{
		anArray->trapezes[anArray->count] = createTrapeze(aTrapeze->A, aTrapeze->B, aTrapeze->C, aTrapeze->D);
		theResult = anArray->count;
		anArray->count++;
	}

	return theResult;
}


int AddTrapezeByIndex(TrapezeArray* anArray, Trapeze* aTrapeze, int num)
{
	int theResult = -1;

	if (anArray != NULL && aTrapeze != NULL && anArray->count < anArray->number && num >= 0 && num <= anArray->count)
	{

		if (anArray->trapezes[anArray->count] == NULL)
		{
			anArray->trapezes[anArray->count] = createTrapeze(aTrapeze->A, aTrapeze->B, aTrapeze->C, aTrapeze->D);
			theResult = anArray->count;
			anArray->count++;
		}
		else
		{

			for (int i = 0; i < (anArray->count - num); i++)
			{
				anArray->trapezes[anArray->count - i] = anArray->trapezes[anArray->count - i - 1];
			}
			anArray->trapezes[num] = createTrapeze(aTrapeze->A, aTrapeze->B, aTrapeze->C, aTrapeze->D);
			anArray->count++;
		}
	}

	return theResult;
}


void writeArrayToJSON(FILE *aFile, TrapezeArray *anArray)
{
	if (aFile == NULL || anArray == NULL)
		return;

	fprintf(aFile, "{\n\"number\" : %d,\n\"count\" : %d,\n",
		anArray->number, anArray->count);

	fprintf(aFile, "\"trapezes\" : \n[\n");

	for (int i = 0; i < anArray->count; i++)
	{
		writeTrapezeToJSON(aFile, anArray->trapezes[i]);

		if (i < anArray->count - 1)
		{
			fprintf(aFile, ",");
		}
		fprintf(aFile, "\n");
	}

	fprintf(aFile, "]\n}");
}


void printArray(TrapezeArray *anArray)
{
	if (anArray == NULL)
	{
		return;
	}

	printf("[TR]: number(%d), count(%d)", anArray->number, anArray->count);
	printf(", trapezes: \n");

	for (int i = 0; i < anArray->count; i++)
	{
		printTrapeze(anArray->trapezes[i]);
	}
}

void freeArray(TrapezeArray *anArray)
{
	if (NULL != anArray)
	{
		for (int i = 0; i < anArray->count; i++)
		{
			destroyTrapeze(anArray->trapezes[i]);
		}
		free(anArray->trapezes);
		free(anArray);
	}
}

void writePointToJSON(FILE* aFile, Point* aPoint)
{
	if (NULL == aPoint || NULL == aFile)
	{
		return;
	}
	fprintf(aFile, "{\"x\" : %d, \"y\" : %d}", aPoint->x, aPoint->y);
}

void writeTrapezeToJSON(FILE* aFile, Trapeze* aTrapeze)
{
	if (NULL == aTrapeze || NULL == aFile)
	{
		return;
	}

	fprintf(aFile, "{\n\"A\" : ");
	writePointToJSON(aFile, aTrapeze->A);
	fprintf(aFile, ", \n\"B\" : ");
	writePointToJSON(aFile, aTrapeze->B);
	fprintf(aFile, ", \n\"C\" : ");
	writePointToJSON(aFile, aTrapeze->C);
	fprintf(aFile, ", \n\"D\" : ");
	writePointToJSON(aFile, aTrapeze->D);
	fprintf(aFile, "\n}");
}