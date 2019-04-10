#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dk_tools.h"
#define _CRT_SECURE_NO_WARNINGS
void bubbleSort(char* string1) {
	int flag;
	int n = strlen(string1);
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++)
		{
			if (string1[i] > string1[i + 1])
			{
				flag = string1[i];
				string1[i] = string1[i + 1];
				string1[i + 1] = flag;
			}
		}
	}

}

void selectionSort(char* string2) {
	int k = strlen(string2);
	int flags;
	for (int i = 0; i < k; i++)
	{
		int min = i;

		for (int j = i + 1; j < k; j++)
		{
			if (string2[min] > string2[j])
			{
				min = j;
			}
		}
		flags = string2[i];
		string2[i] = string2[min];
		string2[min] = flags;
	}
}

void insertionSort(char* string3) {
	char temp;
	int item;
	int l = strlen(string3);
	for (int i = 1; i < l; i++)
	{
		temp = string3[i];
		item = i - 1;
		while (item >= 0 && string3[item] > temp)
		{
			string3[item + 1] = string3[item];
			string3[item] = temp;
			item--;
		}
	}
}

void getMas(char* string) {
	fo = fopen("textLab.txt", "rt");
	for (int i = 0; i < 100; i++)
	{
		fscanf(fo, "%c", &string[i]);
	}
	fclose(fo);
}

void writeInFileRand() {
	fo = fopen("textLab.txt","a+");
	for (int i = 0; i < 100; i++)
	{
		fprintf(fo,"%c", rand() % 26 + 97);
	}
	fclose(fo);
}

void WriteEndInFile(char* string)
{
	fo = fopen("textLab.txt", "a+");
	fprintf(fo,"\n");
	for (int i = 0; i < 100; i++)
	{
		fprintf(fo, "%c", string[i]);
	}
	fclose(fo);
}
