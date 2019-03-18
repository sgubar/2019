#include <stdio.h>
#include "triangle.h"

int main(int argc, char *argv[]) 
{
	Triangle *triugolnik = createTriangle(createDot(3,2),createDot(1,3),createDot(0,5));
	outputData(triugolnik);
	deleteTriangle(triugolnik);
	system("pause");
	return 0;
}