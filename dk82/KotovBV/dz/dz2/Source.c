#include <stdlib.h>
#include "ellipse.h"
#include <Windows.h>
int main(int argc, char const *argv[])
{
	float area = 0.0;
	Point A = { 6,3 };
	Point B = { 2,10 };
	Point R = { 8,6 };

	if (perp(&R, &A, &B) != 0)
	{
		MessageBox(NULL, "ERROR404", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return 0;
	}
	Elips *a = createElips(&A, &B, &R);
	Elips *b = createElipsWithCoordinate(2, 1, 2, 4, 6, 4);
	printElips(a);
	areaElips(a);
	area = areaElips(a);
	printElips(b);
	destroyElips(a);
	printf("area=%f\n", area);
	system("pause");
	return 0;
}