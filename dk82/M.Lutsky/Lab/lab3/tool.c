#include "tool.h"


char *shellSort(char *mass, int size)
{
	int i = 0;
	int j = 0;
	int h = 1;
	while (h <= size / 3)
	{
		h = h * 3 + 1;
	}
	while (h > 0)
	{
		for (j = h; j < size - 1; j++)
		{
			int temp = mass[j];
			i = j;
			while (i > h - 1 && mass[i - h] >= temp)
			{
				mass[i] = mass[i - h];
				i -= h;
			}
			mass[i] = temp;
		}
		h = (h - 1) / 3;
	}
	return mass;
}


int fileSize(FILE *fp) {
	fseek(fp, 0l, SEEK_END);
	int fileSize = ftell(fp);
	fseek(fp, 0l, SEEK_SET);
	return fileSize;
}

char *readFile(FILE *fp) {
	if (NULL == fp) {
		return -1;
	}

	int size = fileSize(fp);

	char *mass = (char*)malloc(sizeof(char) * size);
	fgets(mass, size, fp);

	printf("Input: %s\n", mass);
	return mass;
}

int linearSearch(char *mass, char c, int size)
{
	int result = -1;
	if (NULL == mass || size <= 0) {
		return result;
	}
	for (int i = 0; i < size; i++)
	{
		if (mass[i] == c) {
			return i;
		}
	}
	return result;
}

