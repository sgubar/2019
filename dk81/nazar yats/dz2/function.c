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




Rectangle *createRectangle(Point *A, Point *B, Point *C, Point *D)
{
    Rectangle *rec = NULL;

    if (A != NULL && B != NULL && C != NULL && D != NULL)
    {
        rec = (Rectangle *)malloc(sizeof(Rectangle));

        rec->A = CPWP(A);
        rec->B = CPWP(B);
        rec->C = CPWP(C);
        rec->D = CPWP(D);
    }

    return rec;
}


float lineRectangle(Rectangle* rec, int number)
{
    float lines[5];


    lines[0] = sqrt(( rec->A->x - rec->B->x )*( rec->A->x - rec->B->x ) +
                    ( rec->A->y - rec->B->y )*( rec->A->y - rec->B->y ));
    lines[1] = sqrt(( rec->B->x - rec->C->x )*( rec->B->x - rec->C->x ) +
                    ( rec->B->y - rec->C->y )*( rec->B->y - rec->C->y ));
    lines[2] = sqrt(( rec->C->x - rec->D->x )*( rec->C->x - rec->D->x ) +
                    ( rec->C->y - rec->D->y )*( rec->C->y - rec->D->y ));
    lines[3] = sqrt(( rec->A->x - rec->D->x )*( rec->A->x - rec->D->x ) +
                    ( rec->A->y - rec->D->y )*( rec->A->y - rec->D->y ));
    lines[4] = sqrt(( rec->A->x - rec->C->x )*( rec->A->x - rec->C->x ) +
                    ( rec->A->y - rec->C->y )*( rec->A->y - rec->C->y ));

    return lines[number];
}



int CheckRectangle(Rectangle* rec)
{
	int number_cell;
	int number;
	
    float lines[5];
    float cell;
    int trueRec;


    lines[0] = lineRectangle(rec, 0);
    lines[1] = lineRectangle(rec, 1);
    lines[2] = lineRectangle(rec, 2);
    lines[3] = lineRectangle(rec, 3);
    lines[4] = lineRectangle(rec, 4);


    for( number_cell = 0; number_cell < 5; number_cell++)
        for( number = 0; number < 5; number++)
            if(lines[number_cell] > lines[number])
            {
                cell = lines[number_cell];
                lines[number_cell] = lines[number];
                lines[number] = cell;
            }

	if(lines[1] != lines[2] || lines[3] != lines[4]){
		trueRec = 99;
	}
    trueRec = lines[0]*lines[0] - lines[1]*lines[1] - lines[3]*lines[3];

    return trueRec;
}

void printRectangle(Rectangle* rec)
{
    float AB, BC, CD, AD;

    AB = lineRectangle(rec, 0);
    BC = lineRectangle(rec, 1);
    CD = lineRectangle(rec, 2);
    AD = lineRectangle(rec, 3);


    printf("AB == %.2f >> ", AB);
    printf("A(%i, %i), B(%i, %i)\n", rec->A->x, rec->A->y, rec->B->x, rec->B->y);
    printf("BC == %.2f >> ", BC);
    printf("B(%i, %i), C(%i, %i)\n", rec->B->x, rec->B->y, rec->C->x, rec->C->y);
    printf("CD == %.2f >> ", CD);
    printf("C(%i, %i), D(%i, %i)\n", rec->C->x, rec->C->y, rec->D->x, rec->D->y);
    printf("AD == %.2f >> ", AD);
    printf("A(%i, %i), D(%i, %i)\n", rec->A->x, rec->A->y, rec->D->x, rec->D->y);

}



void destroyRectangle(Rectangle* rec)
{
    if (rec != NULL)
    {
        free(rec->A);
        free(rec->B);
        free(rec->C);
        free(rec->D);

        free(rec);
    }
}

