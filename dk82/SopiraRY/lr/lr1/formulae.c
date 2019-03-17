#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void help()
{
	printf("###SYNTAX###\n\n\t./formulae [A] [B] [C]\n\nEither B or C must not be 0.\nB must be an integer.\nB must be in [1; 100].\n\n");
}

int main(int argc, char **argv)
{
	if (argc != 4){
		help();
		return 1;
	}
	
	double a = atof(argv[1]);
	int b = atoi(argv[2]);
	double c = atof(argv[3]);
	int d = 0;
	
	if (b < 0 || c == 0){
		help();
		return 1;
	}
	
	printf("Q = %f\n", ( (a * b) / (b + square(c)) ) + sum_of(d, b, factorial(d)));

	return 0;
}

