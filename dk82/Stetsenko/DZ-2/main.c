#include <stdio.h>
#include <stdlib.h>
#include "func.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Point A = {0,0};
	Point B = {10,0};
	Point C = {10,5};
	Point D = {0,5};
	
	Rectangle *ABCD = createRectangle(&A ,&B , &C ,&D);
	
	printRectangle(ABCD);
	
	printf("Square of Rectangle ABCD = %.2f\n", squareRectangle(ABCD));
	
	
	destroyRectangle(ABCD);
	
	
	return 0;
}
