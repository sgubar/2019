#include <stdlib.h>
#include <stdio.h>
#include "tool.h"
#pragma warning(disable:4996)
int main(int argc, char const* argv[])
{
	double area[] = { 0.0, 0.0,0.0 };
	Point A = { 6,3 };
	Point B = { 2,10 };
	Point C = { 8,6 };
	Point mass[3] = { {5,4 }, {1, 3}, {9, 1} };

	triangle* arr = createTriangwithArray(mass);//создаем треугольники
	triangle* a = createTriang(&A, &B, &C);//
	triangle* b = createTriangWithCoordinate(6, 3, 8, 1, 8, 6);

	area[0] = areaTriangle(a);//считаем площади треугольников
	area[1] = areaTriangle(b);
	area[2] = areaTriangle(arr);


	printTriangle(a);//выводим треугольники и их площадь
	printf("area[a]=%f\n\n", area[0]);
	printTriangle(arr);
	printf("area[arr]=%f\n\n", area[2]);
	printTriangle(b);
	printf("area[b]=%f\n\n", area[1]);

	destroyTriangle(a);
	destroyTriangle(b);
	destroyTriangle(arr);

	system("pause");
	return 0;
}
