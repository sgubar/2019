#include "dz4.h"

int getSize()
{
	int size;
	do
	{
		printf("Enter size:\n");
		scanf("%d", &size);
		printf("\n");
	}
	while (size <= 0);
	return size;
}

double circleRadius(Circle *aCircle)
{
	aCircle->radius = sqrt( pow((double)aCircle->A->x, 2) + pow((double)aCircle->A->y, 2) );
	
	return aCircle->radius;
}

double circleArea(Circle *aCircle)
{
	return ( 3.14*pow((double)aCircle->radius, 2) );
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
			//theResult->area = circleArea(theResult);
		}
	}
	
	return theResult;
}

Array *createCircleArray(int size)
{
	Array *theResult = NULL;
	
	if (size >= 0)
	{
		theResult = (Array *)malloc(sizeof(Array));
		
		if (NULL != theResult)
		{
			theResult->array = (Circle **)malloc(size*sizeof(Circle *));
			
			if (NULL != theResult->array)
			{
				theResult->size = size;
				theResult->count = 0;
			}
			else
			{
				free(theResult);
				theResult = NULL;
			}
		}
	}
	
	return theResult;
}

Circle *copyCircle(Circle *aCircle)
{
	Circle *newCircle = (Circle *)malloc(sizeof(Circle));
	if (NULL != newCircle && NULL != aCircle)
	{
		newCircle = createCircleWithPoint(aCircle->A);
	}
	
	return newCircle;
}

int addElement(Array *aCircleArray, Circle *aCircle)
{	
	int theResult = 0;
	if ((NULL != aCircleArray && NULL != aCircle) && aCircleArray->count < aCircleArray->size)
	{		
		aCircleArray->array[aCircleArray->count] = copyCircle(aCircle);
		theResult = aCircleArray->count;
		aCircleArray->count++;
	}
	
	return theResult;
}

int addElementAtIndex(Array *aCircleArray, Circle *aCircle, int index)
{	
	int theResult = -1;
	if (NULL != aCircleArray && NULL != aCircle && index >= 0 && index < aCircleArray->count)
	{		
		if (NULL == aCircleArray->array[index])
		{
			aCircleArray->array[index] = copyCircle(aCircle);
		}
		else
		{
			destroyCircle(aCircleArray->array[index]);
			aCircleArray->array[index] = copyCircle(aCircle);
			theResult = index;
		}
	}
	
	return theResult;
}

void destroyCircleArray(Array *aCircleArray)
{
	if (NULL != aCircleArray)
	{
		for (int i = 0; i < aCircleArray->count; i++)
		{
			destroyCircle(aCircleArray->array[i]);
		}
			
		free(aCircleArray);
	}
}

void printCircle(Circle *aCircle)
{
	if (NULL != aCircle)
	{
		printf ("[Circle]\n Center (%d, %d),\n Radius = %.2f\n Area = %.2f\n", 
				aCircle->A->x, aCircle->A->y,
				aCircle->radius, circleArea(aCircle));
	}
}

void printCircleArray(Array *aCircleArray)
{
	if (NULL != aCircleArray)
	{
		printf("[Circles]\n");
		for (int i = 0; i < aCircleArray->count; i++)
		{
			printCircle(aCircleArray->array[i]);
		}
		printf("\n");
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

 /*
 void writeArrayToJSON(FILE *file, Array *aCircleArray)
{
	if (NULL != aCircleArray)
	{
		fprintf(file, "{\n");
		fprintf(file, "\t\"count\": %d\n", aCircleArray->count);
		fprintf(file, "\t\"size\": %d,\n", aCircleArray->size);
		fprintf(file, "\t\"array\": [\n");
		
		for(int i = 0; i < aCircleArray->count; i++)
		{
			writeCircleToJSON(file, aCircleArray->array[i]);
						
			if (i != aCircleArray->count - 1)
				fprintf(file, "\t\t},\n");
			else
				fprintf(file, "\t\t}\n");
			
		}
		fprintf(file, "\t]\n");
		fprintf(file, "}");
	}
}

void writeCircleToJSON(FILE *file, Circle *aCircle)
{		
	fprintf(file, "\t\t{\n");
	fprintf(file, "\t\t\"Radius\": %f,\n", aCircle->radius);
	fprintf(file, "\t\t\"Area\": %f,\n", aCircle->area);
	
	fprintf(file, "\t\t\"A\": {\n");
	//fprintf(file, "\t\t\t\"x\": %d,\n", aCircle->A->x);
	fprintf(file, "\t\t\t\"y\": %d\n\t\t\t},\n", aCircle->A->y);

}
*/

