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


float lineTriagle(Point *point1, Point *point2)
{
    float line = sqrt(( point1->x - point2->x )*( point1->x - point2->x ) +
                    ( point1->y - point2->y )*( point1->y - point2->y ));

    return line;
}



int CheckTriangle(Triangle* trian)
{

    float lines[3];
    float cell;
    int trueTrian;


    lines[0] = lineTriagle(trian->A, trian->B);
    lines[1] = lineTriagle(trian->B, trian->C);
    lines[2] = lineTriagle(trian->A, trian->C);


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





float square_triang(Triangle* trian)
{
    float lines[3];
    float cell;
    float square;


    lines[0] = lineTriagle(trian->A, trian->B);
    lines[1] = lineTriagle(trian->B, trian->C);
    lines[2] = lineTriagle(trian->A, trian->C);


    for(int number_cell = 0; number_cell < 3; number_cell++)
        for(int number = 0; number < 3; number++)
            if(lines[number_cell] > lines[number])
            {
                cell = lines[number_cell];
                lines[number_cell] = lines[number];
                lines[number] = cell;
            }


    square = ( lines[1] * lines[2] ) / 2;

    return square;
}




void writeJSON_Trian_Point(FILE *file, Point *poi)
{

    fprintf(file, "    \"x\" : %d,\n", poi->x);
    fprintf(file, "    \"y\" : %d\n", poi->y);

}



void writeJSON_Trian(FILE *file, Triangle *trian)
{
    fprintf(file, "{\n");

    fprintf(file, "{\n\"square\" : %.2f,\n", square_triang(trian));

    fprintf(file, "\"A\" : \n{\n");
    writeJSON_Trian_Point(file, trian->A);
    fprintf(file, "},\n");


    fprintf(file, "\"B\" : \n{\n");
    writeJSON_Trian_Point(file, trian->B);
    fprintf(file, "},\n");


    fprintf(file, "\"C\" : \n{\n");
    writeJSON_Trian_Point(file, trian->C);
    fprintf(file, "}\n");

    fprintf(file, "}");
}






int printTriangle(Triangle* trian)
{

    if(CheckTriangle(trian) != 0)
        return CheckTriangle(trian);

    float AB, BC, AC;

    AB = lineTriagle(trian->A, trian->B);
    BC = lineTriagle(trian->B, trian->C);
    AC = lineTriagle(trian->A, trian->C);




    printf("square = %.2f\n", square_triang(trian));


    printf("AB == %.2f >> ", AB);
    printf("A(%i, %i), B(%i, %i)\n", trian->A->x, trian->A->y, trian->B->x, trian->B->y);
    printf("BC == %.2f >> ", BC);
    printf("B(%i, %i), C(%i, %i)\n", trian->B->x, trian->B->y, trian->C->x, trian->C->y);
    printf("AC == %.2f >> ", AC);
    printf("A(%i, %i), C(%i, %i)\n", trian->A->x, trian->A->y, trian->C->x, trian->C->y);

    return 0;
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


