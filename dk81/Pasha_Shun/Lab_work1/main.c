// 21.03.19
// Lab_Work1
//Created by Pasha Shun (World_conspiracy)
//Good luck :)

#include <stdio.h>
#include <math.h>
#include "header.h"
int main() {
    int a, b, c;
    int sum_of_factorials = 0;

    printf("Input A (warning , this variable must be >= 0) :\n");
    scanf("%d", &a);
    printf("Input B (warning , this variable must be > 0 and bigger than C) :\n");
    scanf("%d", &b);
    printf("Input C (warning , this variable must be >= 0) :\n");
    scanf("%d", &c);

    if (b <= 0 || c < 0 || b < c || a < 0){
        printf("Sorry, wrong variables\n");
        return 0;
    }

    for (int i = 0; i < c; i++) {

        a += i;
        sum_of_factorials += factorial(a);
    }
    /*
    printf("%d\n", sum_of_factorials);

    square_root(b, c);
    printf("LoL \n");
    printf("%f\n", square_root(b, c));

    printf("**********\n");
    printf("%f\n", first_bracket(a, b, square_root(b, c)) );
    //factorial(sum);
    printf("**********\n");
    printf("%d", factorial(a));
    */


    printf("Your output is: %f + %d = %f", first_bracket(a, b, square_root(b, c)), sum_of_factorials, first_bracket(a, b, square_root(b, c) + sum_of_factorials));
    return 0;
}
