//
// Created by World_conspiracy on 20.03.2019.
//
#include <stdio.h>
#include <math.h>
#include "header.h"

float square_root(int b, int c){
    return sqrt(b + c);
  // return your_square;
   // printf("It's in function: %f\n",your_square);
}
float first_bracket(int a, int b, int c){
    return a*(sqrt(b + c) / b);
}
int factorial(int a){
    int output_factorial = 1;

    for (int i = 1; i <= a; i++) {

            output_factorial = i * output_factorial;

    }
    return  output_factorial;
}
