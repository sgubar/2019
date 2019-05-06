#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tool.h"

int main(int argc, char* argv[])
{

	char* bubble = readFile("C:\\InText.txt");
	char* vibir = readFile("C:\\InText.txt");
	char* vstavka = readFile("C:\\InText.txt");

	clock_t inStart = clock();
	bubbleSort(bubble);
	clock_t inEnd = clock();
	printf("Metod bulbashki\nTime sorting: %f seconds\n",
		(float)(inEnd - inStart) / CLOCKS_PER_SEC, inEnd - inStart);
	writeFile(bubble, "C:\\OutText.txt");


	inStart = clock();
	vibirSort(vibir);
	inEnd = clock();
	printf("Metod viboru\nTime sorting: %f seconds\n",
		(float)(inEnd - inStart) / CLOCKS_PER_SEC, inEnd - inStart);
	writeFile(vibir, "C:\\OutText1.txt");


	inStart = clock();
	vstavkaSort(vstavka);
	inEnd = clock();
	printf("Metod vstavki\nTime sorting : %f seconds\n",
		(float)(inEnd - inStart) / CLOCKS_PER_SEC, inEnd - inStart);
	writeFile(vstavka, "C:\\OutText2.txt");

	system ("pause");
}
