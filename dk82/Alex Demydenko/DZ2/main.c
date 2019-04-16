#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "circle.h"

int main(int argc, char **argv)
{
	Point A = {2,4};
	double radius = 7;
	Circle *sample = createCircleWithCenter(&A, radius);
	printCircle(sample);
	destroyCircle(sample);
	
	return 0;
}

