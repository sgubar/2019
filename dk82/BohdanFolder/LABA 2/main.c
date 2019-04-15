#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tool.h"

int main(int argc, char* argv[])
{

	char* arraybulb = getArray("D:\\tt1.txt");
	char* arrayvib = getArray("D:\\tt2.txt");
	char* arrayvstav = getArray("D:\\tt3.txt");

	clock_t inStart = clock();
	bubbleSort(arraybulb);
	clock_t inEnd = clock();
	printf("(Metod bulbashki)\nTime of bubble sorting: %f seconds\nTime of bubble sorting: %d steps\n\n",
		(float)(inEnd - inStart) / CLOCKS_PER_SEC, inEnd - inStart);
	writeArray(arraybulb, "D:\\tt1.txt");

	
	inStart = clock();
	selectionSort(arrayvib);
	inEnd = clock();
	printf("(Metod viboru)\nTime of selection sorting: %f seconds\nTime of selection sorting: %d steps\n\n",
		(float)(inEnd - inStart) / CLOCKS_PER_SEC, inEnd - inStart);
	writeArray(arrayvib, "D:\\tt2.txt");


	inStart = clock();
	insertionSort(arrayvstav);
	inEnd = clock();
	printf("(Metod vstavki)\nTime of selection sorting: %f seconds\nTime of selection sorting: %d steps\n\n",
		(float)(inEnd - inStart) / CLOCKS_PER_SEC, inEnd - inStart);
	writeArray(arrayvstav, "D:\\tt3.txt");


}



