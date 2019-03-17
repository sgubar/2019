#include <stdio.h>
#include "square.h"

int main(int argc, const char * argv[])
{
	Point A = {0,0};
	Point B = {2,0};
	Point C = {0,2};
	Point D = {2,100};

	Square *ABCD = createSquare(&A, &B, &C, &D);
	printSquare(ABCD);

	return 0;
}
