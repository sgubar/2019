//
// Created by Владислав on 19.03.2019.
//
#include <stdio.h>

#ifndef DZ2_SQUARE_H
#define DZ2_SQUARE_H

typedef struct tagPoint
{
    int y;
    int x;
}Point;

typedef struct tagSquare
{
    Point *A;
    Point *B;
    Point *C;
    Point *D;
}Square;


Square *createSquareSide(Point *A, int side);
Square *createSquarePoints(Point *A, Point *B, Point *C, Point *D);
Square *createSquareWithCoordinates(int xA, int yA, int xB, int yB, int xC, int yC, int xD, int yD);
void destroySquare(Square *aSquare);
void printSquare(Square *aSquare);

int area(Square *aSquare);


#endif //DZ2_SQUARE_H
