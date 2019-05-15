#include <stdio.h>
#include "dk_tools.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(int argc, const char* argv[])
{ 
FILE *fo=fopen("C:/Users/komp/Desktop/informatika/project/dzFive/testForDzFive.json", "w+");
Array* theArrayOne = createArray(4);

Array* theArrayThree = createArray(4);

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
	
	Point M = {0,0};
	Point N = {0,5};
	Point O = {14,5};
	Point P = {5,0};
	
	Trapeze *a = createTrapeze(&A, &B, &C, &D);
	Trapeze *b = createTrapeze(&E, &F, &G, &H);
	Trapeze *c = createTrapeze(&I, &J, &K, &L);
	Trapeze *d = createTrapeze(&M, &N, &O, &P);
	
	addElement(theArrayOne, a);
	addElement(theArrayOne, b);
	addElement(theArrayOne, c);
	addElement(theArrayOne, d);
	
	printArray(theArrayOne);
	


	addElement(theArrayThree, a);
	addElement(theArrayThree, b);
	addElement(theArrayThree, c);
	addElement(theArrayThree, d);
	
    printf("\nSquare of first trapeze :%f \n", squareTrapeze(a));
	printf("\nSquare of second trapeze :%f \n", squareTrapeze(b));	
	printf("\nSquare of third trapeze :%f \n", squareTrapeze(c));
	printf("\nSquare of four trapeze :%f \n", squareTrapeze(d));
	
	insertionSort(theArrayOne);
	shellSort(theArrayThree);
	
	printf("\n\n\t\tSorted trapezes:\n\n\n");
	printArray(theArrayOne);
	
	printArray(theArrayThree);
	
	printf("\nthe number of trapeze, who you searching is [%d]\n",binarySearch(theArrayThree,20));
	
	writeArrayToJSON(fo, theArrayOne);

	writeArrayToJSON(fo, theArrayThree);
	
	freeArray(theArrayOne);
	
	freeArray(theArrayThree);
	
	fflush(fo);
	fclose(fo);
	return 0;
}
