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


char *readFile(FILE *fp) {
	if (NULL == fp) {
		return -1;
	}

	fseek(fp, 0l, SEEK_END);
	int fileSize = ftell(fp);
	fseek(fp, 0l, SEEK_SET);

	char *mass = (char*)malloc(sizeof(char) * fileSize);
	fgets(mass, fileSize, fp);
	fseek(fp, 0l, SEEK_SET);

	printf("Input: %s\n", mass);
	return mass;
}

int linearSearch(char *mass, char c, int size)
{
	if (NULL == mass || size <= 0) {
		return -1;
	}

	int result = -1;

	for (int i = 0; i < size; i++)
	{
		if (mass[i] == c) {
			return i;
		}
	}

	return result;
}
