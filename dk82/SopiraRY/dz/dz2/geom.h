#ifndef __GEOM_H
#define __GEOM_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

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

//freeing the memory
	//destroying vector
void destroyVector(Vector *aVector);
	//destroying triangle
void destroyTriangle(Triangle *aTriangle);

//area
	//through vectors only
float triangleVectorArea(Vector *aVector, Vector *bVector);
	//through triangle
float triangleArea(Triangle *aTriangle);

//misc operations
void printPoint(Point *aPoint);
void printVector(Vector *aVector);
void printTriangle(Triangle *aTriangle);

#endif
