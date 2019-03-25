#include "circle.h"
//#include <stdio.h>
#define PI 3.14

Circle *createCircle (Dot *O, int radius) 
{
	Circle *result = NULL;

	if (NULL != O && NULL != radius)
	{
		result = (Circle *)malloc(sizeof(Circle));

		if (NULL != result)
		{
			result->O = O;
			result->radius = radius;
		}
	}

	return result;
}

void destroyCircle (Circle *circle) 
{
	if (NULL != circle)
	{	
		//free(circle->O->x);
		//free(circle->O->y);
		//free(circle->O);
		//free(circle->radius);
		free(circle);
	}
}


void printCircle (Circle *circle)
{
	if (NULL != circle)
	{	
		printf("Circle O(%i, %i)\nRadius = %i\n", circle->O->x, circle->O->y, circle->radius);
		printf("Square = %.2f\n", PI * circle->radius * circle->radius);
	}
}