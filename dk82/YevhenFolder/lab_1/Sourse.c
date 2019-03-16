#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include "tools.h"

int main(int argc, char *argv[])
{
	float a;
	float b;
	float c;
	float x;
	
	a = variableA();
	b = variableB();
	c = variableC();
		
    x = division((int) a, (int) b, (int) c) + suma((int) a);

    printf_s("Q =  %f\n", x);

	system("PAUSE");

	return 0;
}
