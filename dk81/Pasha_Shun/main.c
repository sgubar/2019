// 21.03.19
// Lab_Work1
//Created by Pasha Shun (World_conspiracy)
//Good luck :)

#include <stdio.h>
#include <math.h>
#include "header.h"
int main() {
    int a, b, c;
    int factor;
    float square;
    float first_Bracket;
    int sum_of_factorials;

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
    square = square_root(b, c);
    first_Bracket = first_bracket(a, b, square);
    factor = factorial(a);
    sum_of_factorials = sum (c, factor);


    printf("Your output is: %f + %d = %f", first_Bracket, sum_of_factorials, first_Bracket + sum_of_factorials);
    return 0;
}
