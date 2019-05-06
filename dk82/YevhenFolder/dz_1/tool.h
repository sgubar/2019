#ifndef tool_h
#define tool_h

#include <stdio.h>

typedef struct tagPoint
{
	int x;
	int y;
}Point;

typedef struct tagPrtr {
	Point *A;
	Point *B;
	Point *C;
}Prtr;

void  printPrtr(Prtr* aPrtr);
void  destroyPrtr(Prtr* aPrtr);
float squarePrtr(Prtr* aPrtr);


Prtr *CreatePrtrByPoints(Point* A, Point* B, Point* C);
Prtr *CreatePrtrByCoordinates(int x1, int y1, int x2, int y2, int x3, int y3);


#endif 
