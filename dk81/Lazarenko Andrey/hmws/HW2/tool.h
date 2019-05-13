#include <stdio.h>

typedef struct point
{
	int x;
	int y;
}Point;

typedef struct Trapeze
{
	Point *A;
	Point *B;
	Point *C;
	Point *D;
}Trapeze;
 
Trapeze *createTrapeze(Point *A, Point *B, Point *C, Point *D);
Point *copyPointWithPoint(Point *aPoint);
Trapeze *createTrapezeWithCoordinate(int xA, int xB, int xC,int xD, int yA, int yB, int yC, int yD);
Point *creatPointWithCoordinate(int x, int y);
Trapeze *createTrapezewithArray(Point *array);

double Trapeze_square(Trapeze *aTrapeze);
void printTrapeze(Trapeze *aTrapeze);
void destroyTrapeze(Trapeze *aTrapeze);
