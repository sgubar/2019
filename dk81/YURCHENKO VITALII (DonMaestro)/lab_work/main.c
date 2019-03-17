#include <stdio.h>
#include "header.h"

int main()
{

    int A, B, C;
    float Q = 0;
    int error;


    printf("𝑄 ← (A + B + C)/(100 − B − C) + ∑ 2^(D + A) (A, D = 0)\n");

    printf("Введіть натуральне число A = ");
    scanf("%i", &A);

    printf("Введіть ціле число B = ");
    scanf("%i", &B);

    printf("Введіть ціле число C = ");
    scanf("%i", &C);



    error = formula(A, B, C, &Q);

    if(error == -1)
    {
        printf("error: 'A' не натуральне число\n");
        return -1;
    }
    else if(error == -2)
    {
        printf("error: 'A + B + C' не повинно дорівнювати 0\n");
        return -1;
    }

    printf("%.2f\n", Q);

    return 0;
}
