#ifndef __GEOM_H
#define __GEOM_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

//geometric
//point
typedef struct tagPoint
{
	float x;
	float y;
}Point;

//vector
typedef struct tagVector
{
	float vx;
	float vy;
}Vector;

//triangle
typedef struct tagTriangle
{
	Vector *AB;
	Vector *AC;
	Vector *BC;
	float area;
}Triangle;

typedef struct tagArray
{
	int count;
	int size;
	
	Triangle **array;
}Array;

//functions
	//4 creating points
Point *createPoint(int x, int y);

	//4 creating vectors
		//through coordinates
Vector *createVector(Point *A, Point *B);

//4 creating triangles
	//through points
Triangle *createTriangleThroughPoints(Point *A, Point *B, Point *C);
	//through vectors
Triangle *createTriangleThroughVectors(Vector *AB, Vector *AC, Vector *BC);
	//making a copy
Triangle *copyTriangle(Triangle *aTriangle);

//4 creating arrays
Array *createRandomTriangleArray(int size);
Array *createTriangleArray(int size);
	//array actions
int addElement(Array *aTriangleArray, Triangle *aTriangle);
int addElementAtIndex(Array *aTriangleArray, Triangle *aTriangle, int index);

//freeing the memory
	//destroying vector
void destroyVector(Vector *aVector);
	//destroying triangles
void destroyTriangle(Triangle *aTriangle);
void destroyTriangleArray(Array *aTriangleArray);

//area
	//through vectors only
float triangleVectorArea(Vector *aVector, Vector *bVector);
	//through triangle
float triangleArea(Triangle *aTriangle);

//misc operations
void printPoint(Point *aPoint);
void printVector(Vector *aVector);
void printTriangle(Triangle *aTriangle);
void printTriangleArray(Array *aTriangleArray);

int checkArray(Array *aTriangleArray);

//JSON
void writeArrayToJSON(FILE *file, Array *aTriangleArray);
void writeTriangleToJSON(FILE *file, Triangle *aTriangle);

#endif
