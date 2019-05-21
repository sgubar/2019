#include "geom.h"

//functions
//4 creating points
/*Point *createPoint(int x, int y)
{
	Point *newPoint = (Point *)malloc(sizeof(Point));
	if (newPoint != NULL)
	{
		newPoint->x = x;
		newPoint->y = y;
	}
	
	return newPoint;
}*/

//4 creating vectors
//coordinates
Vector *createVector(Point *A, Point *B)
{
	Vector *newVector = (Vector *)malloc(sizeof(Vector));
	
	if (NULL != newVector)
	{
		newVector->vx = B->x - A->x;
		newVector->vy = B->y - A->y;
	}
	
	return newVector;
}

//4 creating triangles
//points
Triangle *createTriangleThroughPoints(Point *A, Point *B, Point *C)
{
	Triangle *newTriangle = (Triangle *)malloc(sizeof(Triangle));
	if (NULL != newTriangle)
	{
		newTriangle->AB = createVector(A, B);
		newTriangle->AC = createVector(A, C);
		newTriangle->BC = createVector(B, C);
		newTriangle->area = triangleArea(newTriangle);
	}
	
	return newTriangle;
}

//vectors
Triangle *createTriangleThroughVectors(Vector *AB, Vector *AC, Vector *BC)
{
	Triangle *newTriangle = (Triangle *)malloc(sizeof(Triangle));
	if (NULL != newTriangle)
	{
		newTriangle->AB = AB;
		newTriangle->AC = AC;
		newTriangle->BC = BC;
		newTriangle->area = triangleArea(newTriangle);
	}
	
	return newTriangle;
}

//making a copy
Triangle *copyTriangle(Triangle *aTriangle)
{
	Triangle *newTriangle = (Triangle *)malloc(sizeof(Triangle));
	if (NULL != newTriangle && NULL != aTriangle)
	{
		newTriangle = createTriangleThroughVectors(aTriangle->AB, aTriangle->AC, aTriangle->BC);
	}
	
	return newTriangle;
}

//array
	//creating random triangle array
Array *createRandomTriangleArray(int size)
{
	Array *theResult = NULL;
	
	if (size > 0)
	{
		theResult = (Array *)malloc(sizeof(Array));
		
		if (NULL != theResult)
		{
			theResult->array = (Triangle **)malloc(size*sizeof(Triangle *));
			
			if (NULL != theResult->array)
			{
				theResult->size = size;
				theResult->count = 0;
				
				for (int i = 0; i < size; i++)
				{
					Point O = {0, 0};
					Point A = {0, 0 + rand() % 10};
					Point B = {0 + rand() % 10, 0 + rand() % 10};
					
					theResult->array[i] = createTriangleThroughPoints(&O, &A, &B);
					theResult->count ++;
				}
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
	//creating empty triangle array
Array *createTriangleArray(int size)
{
	Array *theResult = NULL;
	
	if (size >= 0)
	{
		theResult = (Array *)malloc(sizeof(Array));
		
		if (NULL != theResult)
		{
			theResult->array = (Triangle **)malloc(size*sizeof(Triangle *));
			
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
		//array actions
int addElement(Array *aTriangleArray, Triangle *aTriangle)
{	
	int theResult = -1;
	if ((NULL != aTriangleArray && NULL != aTriangle) && aTriangleArray->count < aTriangleArray->size)
	{		
		aTriangleArray->array[aTriangleArray->count] = copyTriangle(aTriangle);
		theResult = aTriangleArray->count;
		aTriangleArray->count++;
	}
	
	return theResult;
}

int addElementAtIndex(Array *aTriangleArray, Triangle *aTriangle, int index)
{	
	int theResult = -1;
	if (NULL != aTriangleArray && NULL != aTriangle && index >= 0 && index < aTriangleArray->count)
	{		
		if (NULL == aTriangleArray->array[index])
		{
			aTriangleArray->array[index] = copyTriangle(aTriangle);
		}
		else
		{
			destroyTriangle(aTriangleArray->array[index]);
			aTriangleArray->array[index] = copyTriangle(aTriangle);
			theResult = index;
		}
	}
	
	return theResult;
}

//freeing the memory
	//destroying vector
void destroyVector(Vector *aVector)
{
	//free(aVector->vx);
	//free(aVector->vy);
	free(aVector);
}

	//destroying triangle
void destroyTriangle(Triangle *aTriangle)
{
	destroyVector(aTriangle->AB);
	destroyVector(aTriangle->AC);
	destroyVector(aTriangle->BC);
	free(aTriangle);
}

	//destroying array
void destroyTriangleArray(Array *aTriangleArray)
{
	if (NULL != aTriangleArray)
	{
		for (int i = 0; i < aTriangleArray->count; i++)
		{
			destroyTriangle(aTriangleArray->array[i]);
		}
			
		free(aTriangleArray);
	}
}

//area
	//through vectors only
float triangleVectorArea(Vector *aVector, Vector *bVector)
{
	float area = -1;
	if (NULL != aVector && NULL != bVector)
	{
		float AxBy = (aVector->vx * bVector->vy);
		float BxAy = (bVector->vx * aVector->vy);
		area = (AxBy - BxAy) / 2;
		
		return (area < 0) ? (area * (-1)) : area;
	}
	return area;
}

	//through triangle
float triangleArea(Triangle *aTriangle)
{
	float area = -1;
	if (NULL != aTriangle)
	{
		float AxBy = (aTriangle->AC->vx * aTriangle->AB->vy);
		float BxAy = (aTriangle->AB->vx * aTriangle->AC->vy);
		area = (AxBy - BxAy) / 2;
		
		return (area < 0) ? (area * (-1)) : area;
	}
	return area;
}

//misc operations
	//printing
void printPoint(Point *aPoint)
{
	if (NULL != aPoint)
	{
		printf("Point [%f, %f]\n", aPoint->x, aPoint->y);
	}
}

void printVector(Vector *aVector)
{
	if (NULL != aVector)
	{
		printf("\tVector [%f, %f]\n", aVector->vx, aVector->vy);
	}
}

void printTriangle(Triangle *aTriangle)
{
	if (NULL != aTriangle)
	{
		printVector(aTriangle->AB);
		printVector(aTriangle->AC);
		printVector(aTriangle->BC);
		printf("\t\tArea [%f]\n", aTriangle->area);
	}
}

void printTriangleArray(Array *aTriangleArray)
{
	if (checkArray(aTriangleArray) == 0)
	{
		printf("\nTriangles [%d/%d]\n", aTriangleArray->count, aTriangleArray->size);
		for (int i = 0; i < aTriangleArray->count; i++)
		{
			printf("#[%d]\n", i);
			printTriangle(aTriangleArray->array[i]);
		}
		printf("\n");
	}
}

	//other
int checkArray(Array *aTriangleArray)
{	
	if (NULL != aTriangleArray)
	{
		if (aTriangleArray->array != NULL)
		{
			if (aTriangleArray->size >= 0  && aTriangleArray->count >= 0)
			{
				return 0;
			}
		}
	}
	
	return -1;
}

	//JSON
void writeArrayToJSON(FILE *file, Array *aTriangleArray)
{
	if (checkArray(aTriangleArray) == 0)
	{
		fprintf(file, "{\n");
		fprintf(file, "\t\"count\": %d\n", aTriangleArray->count);
		fprintf(file, "\t\"size\": %d,\n", aTriangleArray->size);
		fprintf(file, "\t\"array\": [\n");
		
		for(int i = 0; i < aTriangleArray->count; i++)
		{
			//fprintf(file, "\t\t{\n\t\t\"index\": %d,\n", i);
			writeTriangleToJSON(file, aTriangleArray->array[i]);
						
			if (i != aTriangleArray->count - 1)
				fprintf(file, "\t\t},\n");
			else
				fprintf(file, "\t\t}\n");
			
		}
		fprintf(file, "\t]\n");
		fprintf(file, "}");
	}
}

void writeTriangleToJSON(FILE *file, Triangle *aTriangle)
{		
	fprintf(file, "\t\t{\n");
	fprintf(file, "\t\t\"area\": %.1f,\n", aTriangle->area);
	fprintf(file, "\t\t\"AB\": {\n");
	fprintf(file, "\t\t\t\"x\": %f,\n", aTriangle->AB->vx);
	fprintf(file, "\t\t\t\"y\": %f\n\t\t\t},\n", aTriangle->AB->vy);
			
	fprintf(file, "\t\t\"AC\": {\n");
	fprintf(file, "\t\t\t\"x\": %f,\n", aTriangle->AC->vx);
	fprintf(file, "\t\t\t\"y\": %f\n\t\t\t},\n", aTriangle->AC->vy);
		
	fprintf(file, "\t\t\"BC\": {\n");
	fprintf(file, "\t\t\t\"x\": %f,\n", aTriangle->BC->vx);
	fprintf(file, "\t\t\t\"y\": %f\n\t\t\t}\n", aTriangle->BC->vy);
}
