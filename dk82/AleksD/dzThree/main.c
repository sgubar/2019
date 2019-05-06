#include <stdio.h>
#include "dk_tools.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(int argc, const char* argv[])
{ 
FILE *fo=fopen("C:/Users/komp/Desktop/informatika/project/dzThree/test.json", "w+");
Array* theArray = createArray(3);
	
	Point A = {0,0};
	Point B = {0,1};
	Point C = {0,0};
	Point D = {0,2};
	
	Point E = {0,0};
	Point F = {0,3};
	Point G = {0,0};
	Point H = {0,4};
	
	Point I = {0,0};
	Point J = {0,5};
	Point K = {0,0};
	Point L = {0,6};
	
	Trapeze ABCD = {&A, &B, &C, &D};
	Trapeze EFGH = {&E, &F, &G, &H};
	Trapeze IJKL = {&I, &J, &K, &L};
	
	addElement(theArray, &ABCD);
	addElement(theArray, &EFGH);
	addElement(theArray, &IJKL);
	printArray(theArray);
	
	addElementByIndex(theArray, &ABCD, 0);
	addElementByIndex(theArray, &IJKL, 1);
	addElementByIndex(theArray, &EFGH, 2);
	
	printArray(theArray);
	writeArrayToJSON(fo, theArray);
	
	freeArray(theArray);
	fflush(fo);
	fclose(fo);
	return 0;
}
