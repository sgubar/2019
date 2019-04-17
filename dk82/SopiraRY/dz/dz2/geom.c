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
