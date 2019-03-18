#include "header.h"


int sum(int A)
{
    int answer = 0;


    for(int D = 0; D <= A; D++)
    {
        int step = 2;
        for(int num = 1; num < ( D + A ); num++)
            step = step * 2;
        answer = answer + step;
    }

    return answer;
}



int formula(int A, int B, int C, float *Q)
{
    if(A < 1)
        return -1;

    if(( A + B + C ) == 0)
        return -2;

    *Q = ( (float)A + (float)B + (float)C ) / ( 100 - (float)B - (float)C ) + (float)sum(A);

    return 0;
}




