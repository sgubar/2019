#include <stdio.h>
#include "tool.h"

int q( int a, int b)
{	
	
	int result = fuc(a) / mod((2 * a) + b);
	return result;
}

int main(void)
{ 	int a,b;
    printf("Enter number1:  ");
 	scanf("%i",&a);
 	printf("Enter number2:  ");
 	scanf("%i",&b);
	printf("Result is: %i\n", q(a, b));

	return 0;
}
