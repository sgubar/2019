#include <stdio.h>
#include "tool.h"


int main(int argc, char* argv[])
{
	Point A = { 1,2 };
	Point B = { 1,55 };
	Point C = { 3,5 };
	Point D = { 5,2 };
	Point mass[4] = { {1,2}, {2, 3}, {4, 3}, {5, 2} };
	
	Trapeze* array = createTrapezewithArray(mass);// create trapeze with array
	Trapeze* points = createTrapeze(&A, &B, &C, &D);// create trapeze with points
	Trapeze* coordinates = createTrapezeWithCoordinate(2, 12, 4, 6, 2, 4, 4, 2);// create trapeze with coordinate

	
	if (array != NULL)
	{
		printTrapeze(array);// squeare trapeze with array
		double square_arr = Trapeze_square(array);
		printf("square: %.2f\n\n", square_arr);// output of the result
	}
	
	if (points != NULL)
	{
		printTrapeze(points);// squeare trapeze with points
		double square_points = Trapeze_square(points);
		printf("square: %.2f\n\n", square_points);// output of the result
	}

	if (coordinates != NULL)
	{
		printTrapeze(coordinates);// squeare trapeze with coordinate
		double square_coordinates = Trapeze_square(coordinates);
		printf("square: %.2f\n\n", square_coordinates);// output of the result
	}

	destroyTrapeze(array);
	destroyTrapeze(points);
	destroyTrapeze(coordinates);

	system("PAUSE");
	return 0;
}