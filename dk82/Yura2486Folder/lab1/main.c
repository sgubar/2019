#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "tool.h"


int main(int argc, char *argv[]){
	float a;
	float b;
	float c;
	float q;
	printf("WARNING!\nB+C>=0\nB!=0\nC>0; C is integer\nA>=0; A is integer\n\n");
	
	
	a = getA();
	//printf("%f", a);
	b = getB();
	c = getC();
	
	while (b+c<0)
		{
			printf("B is invalid\n");
			b = getB();
		}
		
	q = (a*sqrt(b+c))/b+sumOfFactorials((int) a, (int) c);
	printf("Q = %f\n", q);

	
//system("PAUSE");

return 0;

}

