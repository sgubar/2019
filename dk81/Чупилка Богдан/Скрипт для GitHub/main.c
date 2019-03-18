 #include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "function.h"

int main() {
	setlocale(LC_ALL, "Rus");
	float a, b, c;
	
	printf("Введите значения a, b, c\na=");
	scanf("%f", &a);
	printf("b=");
	scanf("%f", &b);
	printf("c=");
	scanf("%f", &c);
	
	float umnozResult, moduleResult, kubResult, divisionResult, eksResult, mnoz1Result;
	
	umnozResult=(umnoz(a,b,c));
	moduleResult = (module(umnozResult));
	kubResult=(kub(c));
	divisionResult = (division(moduleResult,kubResult));
	eksResult=(eks(a));
	mnoz1Result=umnoz1(divisionResult,eksResult);
	
	printf("result=%f\n", mnoz1Result);
	system ( "Pause" );
	return 0;
}
	
