//
// Created by Владислав on 19.03.2019.
//
#include "Square.h"
#include <stdlib.h>

Point *copyPointWithPoint(Point *aPoint);
Point *createPointWithCoordinate(int x, int y);

//Zero point, Side

Square *createSquareSide(Point *A, int side)
{
    Square *result = NULL;
    Point *B = NULL;
    Point *C = NULL;
    Point *D = NULL;

    if (NULL != A && 0 != side)
    {
        B = (Point *)malloc(sizeof(Point));
        C = (Point *)malloc(sizeof(Point));
        D = (Point *)malloc(sizeof(Point));

        result = (Square *)malloc(sizeof(Square));


        if (NULL != result)
        {

            result->A = copyPointWithPoint(A);
            result->B = copyPointWithPoint(A);
            result->C = copyPointWithPoint(A);
            result->D = copyPointWithPoint(A);

            result->B->y+=side;
            result->C->x+=side;
            result->C->y+=side;
            result->D->x+=side;

        }
    }
    return result;
}

// 4 points

Square *createSquarePoints(Point *A, Point *B, Point *C, Point *D)
{
    Square *result = NULL;

    if (NULL != A && NULL != B && NULL != C && NULL != D)
    {
        result = (Square *)malloc(sizeof(Square));

        if (NULL != result)
        {

            result->A = copyPointWithPoint(A);
            result->B = copyPointWithPoint(B);
            result->C = copyPointWithPoint(C);
            result->D = copyPointWithPoint(D);

        }
    }
    return result;
}

// Coordinates
Square *createSquareWithCoordinates(int xA, int yA, int xB, int yB, int xC, int yC, int xD, int yD)
{
    Square *Result = (Square *)malloc(sizeof(Square));

    if (NULL != Result)
    {
        Result->A = createPointWithCoordinate(xA, yA);
        Result->B = createPointWithCoordinate(xB, yB);
        Result->C = createPointWithCoordinate(xC, yC);
        Result->D = createPointWithCoordinate(xD, yD);
    }

    return Result;
}

void destroySquare(Square *aSquare)
{
    if (NULL != aSquare)
    {
        free(aSquare->A);
        free(aSquare->B);
        free(aSquare->C);
        free(aSquare->D);

        free(aSquare);
    }
}

void printSquare(Square *aSquare)
{
    if (NULL != aSquare)
    {
        printf ("[Square]. B(%d,%d) - C(%d,%d)\n"
                "             |        |\n"
                "          A(%d,%d) - D(%d,%d)\n",
                aSquare->B->x, aSquare->B->y,
                aSquare->C->x, aSquare->C->y,
                aSquare->A->x, aSquare->A->y,
                aSquare->D->x, aSquare->D->y);
    }
}

int area(Square *aSquare)
{
    int area = 0;
    if(NULL != aSquare)
    {
        area = aSquare->D->x - aSquare->A->x;
        area  = area*area;
    }
    return area;
}

// Service
Point *copyPointWithPoint(Point *aPoint)
{
    Point *Result = (Point *)malloc(sizeof(Point));
    if (NULL != Result)
    {
        Result->x = aPoint->x;
        Result->y = aPoint->y;
    }

    return Result;
}

Point *createPointWithCoordinate(int x, int y)
{
    Point *theResult = (Point *)malloc(sizeof(Point));
    if (NULL != theResult)
    {
        theResult->x = x;
        theResult->y = y;
    }

    return theResult;
}