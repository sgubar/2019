#include <stdlib.h>
#include "ellipse.h"

int main(int argc, char const *argv[])
{
	float area = 0.0;
	Point A = { 2,1 };
	Point B = { 2,4 };
	Point R = { 6,4 };
	Elips *a = createElips(&A, &B, &R);
	printElips(a);
	areaElips(a);
	area = areaElips(a);
	destroyElips(a);
	printf("area=%f\n", area);
	system("pause");
	return 0;
}