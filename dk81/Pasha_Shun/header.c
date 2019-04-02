//
// Created by World_conspiracy on 20.03.2019.
//
#include <stdio.h>
#include <math.h>
#include "header.h"

float square_root(int b, int c){
    float i = 0.00;
    while (i*i < (b + c))
        i++;
    while (i*i > (b + c))
        i -= 0.001;
    return i;
}
float first_bracket(int a, int b, float square){
    float F_bracket;
    F_bracket = a * square / b;
    return F_bracket;
}
int factorial(int a){
    int output_factorial = 1;

    for (int i = 1; i <= a; i++) {

            output_factorial = i * output_factorial;

    }
    return  output_factorial;
}

int sum (int c, int factor){
    int a;
    int sum_of_factorials;
    for (int i = 0; i < c; i++) {
        a += i;
        sum_of_factorials += factorial(a);
    }
    return  sum_of_factorials;
}
