#include <stdio.h>
#include "triangle.h"

int main(int argc, char *argv[])
{
	Dot *b = createDot(1, 2);
	Dot *a = createDot(5, 6);
	Dot *c = createDot(0, 2);

	Triangle *triugolnik =  createTriangle(a, b, c);
	Triangle *triugolnik1 = createTriangle(b, a, c);
	Triangle *triugolnik2 = createTriangle(c, b, a);

	TriangleArray *triangleArray = createArray(4);
	adding(triangleArray, triugolnik);
	adding(triangleArray, triugolnik1);
	adding(triangleArray, triugolnik2);

	printArray(triangleArray);
	saveToJSON(triangleArray);

	system("pause");
	return 0;
}