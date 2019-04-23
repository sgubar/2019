//
// Created by Владислав on 01.04.2019.
//

#ifndef LAB1_TOOL_H
#define LAB1_TOOL_H
#define ERROR -858

#include <stdio.h>


//interface
void inputValues(int *A, int *B, int *C);
double calculate(double A, double B, double C);

//math
//https://ru.wikipedia.org/wiki/Быстрый_обратный_квадратный_корень

float Q_rsqrt( float number );
int sum(int D, int C, int val);
int factorial(int val);

//service

int scanWithChecking();

#endif //LAB1_TOOL_H
