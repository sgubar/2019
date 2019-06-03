#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "tool.h"
#include "lists.h"
#pragma warning(disable:4996)


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	FILE* fo;
	fo = fopen("text.txt", "rt");
	
	getArr(fo);
	fflush(fo);
	fclose(fo);
	system("pause");
	return 0;
}