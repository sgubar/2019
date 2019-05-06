#include <stdio.h>
#include <stdlib.h>
#include "array.h"


int main(int argc, const char* argv[])
{
	TrapArray* theArray = createArray(8);

	Point A = { 0,0 };
	Point B = { 4,4 };
	Point C = { 10,4 };
	Point D = { 14,0 };
	
	Trapeze ABCD = { &A, &B, &C, &D };

	addElement(theArray, &ABCD);
	printArray(theArray);

	A.x = 2;
	D.x = 11;

	addElement(theArray, &ABCD);
	printArray(theArray);

	B.y = 3;

	addElement(theArray, &ABCD);
	printArray(theArray);

	bubblesort(theArray);

	fopen_s(&fo, "D:/test.json", "a+");

	writeArrayToJSON(fo, theArray);

	fflush(fo);
	fclose(fo);

	freeArray(theArray);

}

