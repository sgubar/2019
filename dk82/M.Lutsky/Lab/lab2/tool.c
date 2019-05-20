#include "tool.h"

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

char *insertionSort(char *mass, int size) {
	for (int i = 1; i < size - 1; i++)
	{
		int tmp = mass[i];
		int j = i;
		while (j > 0 && mass[j - 1] >= tmp)
		{
			mass[j] = mass[j - 1];
			--j;
		}
		mass[j] = tmp;
	}
	return mass;
}
