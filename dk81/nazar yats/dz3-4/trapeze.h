#ifndef tool_h
#define tool_h

#include <stdio.h>

typedef struct tagPoint
{
	int x;
	int y;
}Point;

typedef struct tagTrapeze
{
	Point* A;
	Point* B;
	Point* C;
	Point* D;

}Trapeze;

Trapeze* CreateTrapezeByPoints(Point* A, Point* B, Point* C, Point* D);
Trapeze* CreateTrapezeByCoordinates(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
void printTrapeze(Trapeze* aTrapeze);
void destroyTrapeze(Trapeze* aTrapeze);
float TrapezeSquare(Trapeze* aTrapeze);
int checkTrapeze(Trapeze* aTrapeze);
void writeTrapToJSON(FILE* fo, Trapeze* aTrap);
void writePointToJSON(FILE* aFile, Point* aPoint);

#endif 
