#include "header.h"



Point *CPWP(Point *aPoint)
{
    Point *Result = (Point *)malloc(sizeof(Point));
    if (Result != NULL)
    {
        Result->x = aPoint->x;
        Result->y = aPoint->y;
    }
    return Result;
}




Triangle *createTriangle(Point *A, Point *B, Point *C)
{
    Triangle *trian = NULL;

    if (A != NULL && B != NULL && C != NULL)
    {
        trian = (Triangle *)malloc(sizeof(Triangle));

        trian->A = CPWP(A);
        trian->B = CPWP(B);
        trian->C = CPWP(C);
    }

    return trian;
}


float lineTriagle(Triangle* trian, int number)
{
    float lines[3];


    lines[0] = sqrt(( trian->A->x - trian->B->x )*( trian->A->x - trian->B->x ) +
                    ( trian->A->y - trian->B->y )*( trian->A->y - trian->B->y ));
    lines[1] = sqrt(( trian->B->x - trian->C->x )*( trian->B->x - trian->C->x ) +
                    ( trian->B->y - trian->C->y )*( trian->B->y - trian->C->y ));
    lines[2] = sqrt(( trian->A->x - trian->C->x )*( trian->A->x - trian->C->x ) +
                    ( trian->A->y - trian->C->y )*( trian->A->y - trian->C->y ));

    return lines[number];
}



int CheckTriangle(Triangle* trian)
{

    float lines[3];
    float cell;
    int trueTrian;


    lines[0] = lineTriagle(trian, 0);
    lines[1] = lineTriagle(trian, 1);
    lines[2] = lineTriagle(trian, 2);


    for(int number_cell = 0; number_cell < 3; number_cell++)
        for(int number = 0; number < 3; number++)
            if(lines[number_cell] > lines[number])
            {
                cell = lines[number_cell];
                lines[number_cell] = lines[number];
                lines[number] = cell;
            }


    trueTrian = lines[0]*lines[0] - lines[1]*lines[1] - lines[2]*lines[2];

    return trueTrian;
}

void printTriangle(Triangle* trian)
{
    float AB, BC, AC;

    AB = lineTriagle(trian, 0);
    BC = lineTriagle(trian, 1);
    AC = lineTriagle(trian, 2);


    printf("AB == %.2f >> ", AB);
    printf("A(%i, %i), B(%i, %i)\n", trian->A->x, trian->A->y, trian->B->x, trian->B->y);
    printf("BC == %.2f >> ", BC);
    printf("B(%i, %i), C(%i, %i)\n", trian->B->x, trian->B->y, trian->C->x, trian->C->y);
    printf("AC == %.2f >> ", AC);
    printf("A(%i, %i), C(%i, %i)\n", trian->A->x, trian->A->y, trian->C->x, trian->C->y);

}



void destroyTriangle(Triangle* trian)
{
    if (trian != NULL)
    {
        free(trian->A);
        free(trian->B);
        free(trian->C);

        free(trian);
    }
}



