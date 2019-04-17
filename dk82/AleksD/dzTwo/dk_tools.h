#ifndef dk_tools_h 
 
#define dk_tools_h 


#include <stdio.h>

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


Trapeze* createTrapeze(Point* A, Point* B, Point* C, Point* D);
Trapeze* createTrapezeWithCoordinate(int xA, int yA, int xB, int yB, int xC, int yC, int xD, int yD);
Trapeze* createTrapezeWithArrayOfPoint (Point* arrayOfPoint);
void destroyTrapeze(Trapeze* aTrapeze);
float squareTrapeze(Trapeze* aTrapeze);
void printTrapeze(Trapeze* aTrapeze);



#endif
