#include <stdio.h>
#include "dk_tools.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(int argc, const char* argv[])
{ 
FILE *fo=fopen("C:/Users/komp/Desktop/informatika/project/dzFour/testForDzFour.json", "w+");
Array* theArrayOne = createArray(3);
Array* theArrayTwo = createArray(3);
Array* theArrayThree = createArray(3);

	Point A = {0,0};
	Point B = {1,4};
	Point C = {4,4};
	Point D = {5,0};
	
	Point E = {0,0};
	Point F = {2,3};
	Point G = {3,3};
	Point H = {4,0};
	
	Point I = {0,0};
	Point J = {0,5};
	Point K = {9,5};
	Point L = {6,0};
	
	Trapeze *a = createTrapeze(&A, &B, &C, &D);
	Trapeze *b = createTrapeze(&E, &F, &G, &H);
	Trapeze *c = createTrapeze(&I, &J, &K, &L);
	
	addElement(theArrayOne, a);
	addElement(theArrayOne, b);
	addElement(theArrayOne, c);
	printArray(theArrayOne);
	
	addElement(theArrayTwo, a);
	addElement(theArrayTwo, b);
	addElement(theArrayTwo, c);

	addElement(theArrayThree, a);
	addElement(theArrayThree, b);
	addElement(theArrayThree, c);
	
    printf("\nSquare of first trapeze :%f \n", squareTrapeze(a));
	printf("\nSquare of second trapeze :%f \n", squareTrapeze(b));	
	printf("\nSquare of third trapeze :%f \n", squareTrapeze(c));
	bubbleSort(theArrayOne);
	selectionSort(theArrayTwo);
	insertionSort(theArrayThree);
	
	printf("\n\n\t\tSorted trapezes:\n\n\n");
	printArray(theArrayOne);
	printArray(theArrayTwo);
	printArray(theArrayThree);
		
	writeArrayToJSON(fo, theArrayOne);
	writeArrayToJSON(fo, theArrayTwo);
	writeArrayToJSON(fo, theArrayThree);
	
	freeArray(theArrayOne);
	freeArray(theArrayTwo);
	freeArray(theArrayThree);
	
	fflush(fo);
	fclose(fo);
	return 0;
}
