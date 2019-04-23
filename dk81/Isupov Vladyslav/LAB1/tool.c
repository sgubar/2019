//
// Created by Владислав on 01.04.2019.
//

#include "tool.h"
#include <stdio.h>
#include <stdlib.h>

double calculate(double A, double B, double C)
{
    int D = 0;
    return (A*(Q_rsqrt((float)B+(float)C)/B)+sum(D,(int)C, factorial((int)A)));
}

void inputValues(int *A, int *B, int *C)
{
    do
    {
        printf("Enter variable A :");
        *A = scanWithChecking();
    }
    while (*A == ERROR);
    do
    {
        printf("Enter variable C :");
        *C = scanWithChecking();
        if (*C == 0)
            printf("Variable C mast be != 0 !\n");
    }
    while (*C == ERROR || *C == 0);

    do
    {
        printf("Enter variable B != 0 :");
        *B = scanWithChecking();
        if (*B == 0)
            printf("Variable B mast be != 0 !\n");
        if ((*B+*C)<0)
            printf("Sum C and B can`t be negative! \n");

    }
    while (*B == ERROR || *B == 0 || (*B+*C)<0) ;

}

float Q_rsqrt( float number )
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y;
    i  = 0x5f3759df - ( i >> 1 );
    y  = * ( float * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) );
    y  = y * ( threehalfs - ( x2 * y * y ) );
    return 1/y;
}

int sum(int D, int C, int val)
{

    for (D; D<C; D++)
    {
        val++;
    }
    return val;
}

int factorial(int val)
{
    if (val == 0 || val == 1) return 1;
    return val * factorial(val - 1);

}

int scanWithChecking()
{
    char buf[32];
    int val = 0;
    fgets(buf, 31, stdin);
    if(sscanf(buf, "%d", &val) != 1)
    {
        printf("Error! Invalid value!\n");
        return ERROR;
    }

    else
        return val;
}
