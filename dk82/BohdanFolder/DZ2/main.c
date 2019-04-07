#include <stdio.h>
#include <stdlib.h>
#include "tool.h"


int main()
{

	Point A = { 3,0 };
	Point B = { 4,0 };
	Point C = { 14,3 };
	Point D = { 10,0 };

	Trapeze* ABCD = CreateTrapezeByPoints(&A, &B, &C, &D);
	checkTrapeze(ABCD);
	if (checkTrapeze(ABCD) == 0)
	{
		printTrapeze(ABCD);
		float square = TrapezeSquare(ABCD);
		printf("\nSquare of trapeze :%f \n", square);
		destroyTrapeze(ABCD);
		return 0;
	}
}