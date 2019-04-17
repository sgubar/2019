#include <stdio.h>
#include "dk_tools.h"

int main(int argc, const char* argv[])
{
	Point A = { 1,1 };
	Point B = { 2,6 };
	Point C = { 7,6 };
	Point D = { 8,1 };
	Point arrayOfPoint[4] = {A , B , C , D};
	
	Trapeze* a = createTrapeze(&A, &B, &C, &D);
	printTrapeze(a);
	printf("The square of trapeze (point) = %f\n", squareTrapeze(a) );
	
	Trapeze* b = createTrapezeWithCoordinate(1, 1, 2, 6, 7, 6, 9, 1);
	printTrapeze(b);
	printf("The square of trapeze  (coordinate) = %f\n", squareTrapeze(b) );

	Trapeze* c = createTrapezeWithArrayOfPoint (arrayOfPoint);
	printTrapeze(c);
	printf("The square of trapeze (mas)  = %f\n", squareTrapeze(c) );


	destroyTrapeze(a);
	destroyTrapeze(b);
	destroyTrapeze(c);
	return 0;
}
