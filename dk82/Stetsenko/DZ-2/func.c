#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include <math.h>

Point *copyPointWithPoint(Point *aPoint);

Rectangle *createRectangle(Point *A, Point *B, Point *C, Point *D)
	{
		Rectangle *theResult = NULL;
		
			theResult = (Rectangle *)malloc(sizeof(Rectangle));
			if (NULL != theResult)
				{
					theResult->A = copyPointWithPoint(A);
					theResult->B = copyPointWithPoint(B);
					theResult->C = copyPointWithPoint(C);
					theResult->D = copyPointWithPoint(D);
				}
			return theResult;
	}


void destroyRectangle(Rectangle *aRectangle)
	{
		if (NULL != aRectangle)
		{
			free(aRectangle->A);
			free(aRectangle->B);
			free(aRectangle->C);
			
			free(aRectangle);
		}
	}
	
	
float squareRectangle(Rectangle *aRectangle)
	{
		float theResult = 0;
		if (NULL != aRectangle)
			{
				float a,b;
				float dX = (aRectangle->B->x - aRectangle->A->x);
				float dY = (aRectangle->B->y - aRectangle->A->y);
				a = sqrt(dX*dX + dY*dY);
				float dzX = (aRectangle->D->x - aRectangle->A->x);
				float dzY = (aRectangle->D->y - aRectangle->A->y);
				b = sqrt(dzX*dzX + dzY*dzY);
				theResult = a*b;
				
			}
		return theResult;
	}
	
	
void printRectangle(Rectangle *aRectangle)
	{
		if( NULL != aRectangle)
			{
				printf("[Rectangle]. A(%d,%d) - B(%d,%d) - C(%d,%d) - D(%d,%d) \n",
					aRectangle->A->x, aRectangle->A->y,
					aRectangle->B->x, aRectangle->B->y,
					aRectangle->C->x, aRectangle->C->y,
					aRectangle->D->x, aRectangle->D->y);
			}
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
	
