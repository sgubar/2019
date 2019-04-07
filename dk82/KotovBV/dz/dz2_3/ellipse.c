#include <stdlib.h>
#include "ellipse.h"
#include <math.h>
#include <Windows.h>
Elips* createElips(Point* A, Point* B, Point* R)
{
	if (perp(R, A, B) == 0.0) {
		Elips* theresult = NULL;
		if (A != NULL && B != NULL && R != NULL)
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
	else
	{
		MessageBox(NULL, "ERROR404, ellipse Isn't created", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return NULL;
	}
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

Elips* createElipsWithCoordinate(int xA, int xB, int xR, int yA, int yB, int yR)
{
	if (perp(creatPointWithCoordinate(xR, yR),creatPointWithCoordinate(xA, yA), creatPointWithCoordinate(xB, yB)) == 0.0)
	{
		Elips* theresult = (Elips*)malloc(sizeof(Elips));
		if (theresult != NULL)
		{
			theresult->A = creatPointWithCoordinate(xA, yA);
			theresult->B = creatPointWithCoordinate(xB, yB);
			theresult->R = creatPointWithCoordinate(xR, yR);
		}
		return theresult;
	}
	else
	{
		MessageBox(NULL, "ERROR404, ellipse Isn't created", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return NULL;
	}
}


Point *creatPointWithCoordinate(int x, int y)
{
	Point *theresult = (Point*)malloc(sizeof(Point));
	if (theresult != NULL)
	{
		theresult->x = x;
		theresult->y = y;
	}
	return theresult;
}


Elips* createElipswithArray(Point* arr)
{
	if (perp(&arr[0], &arr[1], &arr[2]) == 0) {
		Elips* theResult = NULL;
		if (arr != NULL)
		{
			theResult = (Elips*)malloc(sizeof(Elips));
			if (theResult != NULL)
			{
				printf("%d,%d,%d,%d,%d,%d", arr[0].x, arr[0].y, arr[1].x, arr[1].y, arr[2].x, arr[2].y);
				theResult->A = copyPointWithPoint(&arr[0]);
				theResult->B = copyPointWithPoint(&arr[1]);
				theResult->R = copyPointWithPoint(&arr[2]);
			}
		}
		return theResult;
	}
	else
	{
		MessageBox(NULL, "ERROR404, ellipse Isn't created", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return NULL;
	}
}

void printElips(Elips *aElips)
{
	if (aElips != NULL)
	{
		printf("[Elips].\nA([%d][%d]),\nB([%d][%d]),\nR([%d][%d])\n", aElips->A->x,
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


float perp(Point *R, Point *A, Point *B)
{
	float theresult = 0.0;
	if (((R->x - B->x) != 0.0 && (R->y - B->y) != 0.0) || ((R->x - A->x) != 0.0 && (R->y - A->y) != 0.0))
	{
		float dx1 = (R->x - B->x);
		float dy1 = (R->y - B->y);
		float dx2 = (R->x - A->x);
		float dy2 = (R->y - A->y);
		theresult = dx1 * dx2 + dy1 * dy2;
		return theresult;
	}
	else return 1;
}



void writePointToJSON(FILE* aFile, Point* aPoint)
{
	if (NULL == aPoint || NULL == aFile)
	{
		return;
	}
	fprintf(aFile, "{\"x\" : %d, \"y\" : %d}", aPoint->x, aPoint->y);
}

void writeElipsToJSON(FILE* aFile, Elips* aElips)
{
	if (NULL == aElips || NULL == aFile)
	{
		return;
	}

	fprintf(aFile, "{\n\"A\" : ");
	writePointToJSON(aFile, aElips->A);
	fprintf(aFile, ", \n\"B\" : ");
	writePointToJSON(aFile, aElips->B);
	fprintf(aFile, ", \n\"R\" : ");
	writePointToJSON(aFile, aElips->R);
	fprintf(aFile, "\n}");
}