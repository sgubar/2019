#ifndef square_h
#define square_h
#include <stdio.h>

typedef struct tagPoint
	{
	int x;
	int y;
	}Point;

typedef struct tagSquare
	{
	Point *A;
	Point *B;
	Point *C;
	Point *D;
	}Square;

Square *createSquare(Point *A, Point *B, Point *C, Point *D);
//Square *createSquareWithCoordinate(int xA, int yA, int xB, int yB, int xC, int yC, int xD, int yD);
//Square *createSquareWithMassOfPoint
//void destroySquare(Line *aLine);

void printSquare(Square *aSquare);

#endif
