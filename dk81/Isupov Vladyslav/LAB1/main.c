#include <stdio.h>
#include <stdlib.h>
#include "tool.h"



int main()
{
    int  A = 0, B = 0, C = 0;

    inputValues(&A, &B, &C);
    printf("%.2f", calculate(A, B, C));
    return 0;
}