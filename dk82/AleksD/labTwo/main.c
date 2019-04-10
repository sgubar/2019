#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dk_tools.h"
int main(int argc, const char argv[]) {
	char mas[100];
	writeInFileRand();
	getMas(mas);
	bubbleSort(mas);
	WriteEndInFile(mas);
	return 0;
}
	/*
	
	
	for (int i = 0; i < 100 ; i ++)
	{
		fprintf(fo, "%c", rand() % 26 + 97);
	}
	for (int i = 0; i < 100; i++)
	{
		fscanf(fo, "%c", &mas[i]);
	}
	bubbleSort(mas);
	for (int i = 0; i < 100; i++)
	{
		printf("%c", mas[i]);
	}

	
	gets(mass);
	int k;
	k= strlen(mass);
	selectionSort(mass);
	for (int i = 0; i < k; i++)
	{
		fprintf(fo,"%c", mass[i]);
	}


	gets(masss);
	int g = strlen(masss);
	insertionSort(masss);
	for (int i = 0; i < g; i++)
	{
		fprintf(fo,"%c", masss[i]);
	}
	*/
	
	
