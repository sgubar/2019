#ifndef dk_tools_h 
 
#define dk_tools_h 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct tagPoint
{
	int x;
	int y;

} Point;


typedef struct tagTrapeze
{
	Point* A;
	Point* B;
	Point* C;
	Point* D;
}Trapeze;

typedef struct tagArray
{

	int number;
	int counter;
		
	Trapeze** trapezes;
	
}Array;


Trapeze* createTrapeze(Point* A, Point* B, Point* C, Point* D);
Trapeze* createTrapezeWithCoordinate(int xA, int yA, int xB, int yB, int xC, int yC, int xD, int yD);
Trapeze* createTrapezeWithArrayOfPoint (Point* arrayOfPoint);
void destroyTrapeze(Trapeze* aTrapeze);
float squareTrapeze(Trapeze* aTrapeze);
void printTrapeze(Trapeze* aTrapeze, int i);
Array *createArray(int aNumber);
int addElement(Array *anArray, Trapeze *aTrapeze);
void printArray(Array *anArray);
int addElementByIndex(Array *anArray, Trapeze *aTrapeze, int index);
void destroyAndAddTrapezeByIndex(Array *anArray, Point *A, Point *B, Point *C, Point *D, int index);
void freeArray(Array *anArray);
void writeArrayToJSON(FILE *fo, Array *anArray);
void writeTrapezeToJSON(FILE *fo, Trapeze *aTrapeze);
void writePointToJSON(FILE *fo, Point *aPoint);
#endif
