#include<stdio.h>
#include "tool.h"

void res(int * arr[], int dlina) {

	int a;
	int perestanovka = dlina - 1;

	for (int i = 0; i < dlina / 2; i++)
	{
		a = arr[i];
		arr[i] = arr[perestanovka];
		arr[perestanovka] = a;
		perestanovka--;
	}
}

void printArr(int * arr[], int dlina) {
	printf("[");
	for (int i = 0; i < dlina; i++)
	{
		printf("%i;", arr[i]);
	}
	printf("]\n");
}
