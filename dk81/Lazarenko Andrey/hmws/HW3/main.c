#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "tool.h"


int main(int argc, char* argv[])
{
	Point A = { 1,8 };
	Point B = { 4,16 };
	Point C = { 6,16 };
	Point D = { 9,8 };
	Point mass[4] = { {2,6}, {4, 8}, {6, 8}, {8, 6} };

	Trapeze* array = createTrapezewithArray(mass);// create trapeze with array
	Trapeze* points = createTrapeze(&A, &B, &C, &D);// create trapeze with points
	Trapeze* coordinates = createTrapezeWithCoordinate(2, 6, 6, 16, 6, 8, 10, 6);// create trapeze with coordinate

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

	TrapezeArray* theArray = createArray(5);

	AddElement(theArray, points);
	printArray(theArray);

	AddElement(theArray, coordinates);
	printArray(theArray);

	AddElement(theArray, array);
	printArray(theArray);

	AddTrapezeByIndex(theArray, coordinates, 1);
	printArray(theArray);

	FILE* thefile = fopen("test.json", "a+");
	if (thefile != NULL)
	{
		printf("File created successful\n\n");
	}
	else
	{
		return 0;
	}

	writeArrayToJSON(thefile, theArray);
	fflush(thefile);
	fclose(thefile);

	freeArray(theArray);
	destroyTrapeze(points);
	destroyTrapeze(coordinates);
	destroyTrapeze(array);

	system("PAUSE");
	return 0;
}