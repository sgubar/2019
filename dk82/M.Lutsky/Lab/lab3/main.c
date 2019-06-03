#include "tool.h"

void main() {

	FILE *fp;
	fopen_s(&fp, "text.txt", "a+");

	char *mass = readFile(fp);
	int size = fileSize(fp);
	fclose(fp);

	fopen_s(&fp, "text1.txt", "w+");
	fprintf(fp, "Input: %s\n", mass);
	clock_t inStart = clock();
	shellSort(mass, size);
	clock_t inEnd = clock();
	printf("Time of Shell sorting: %f seconds, %d steps\n", (double)(inEnd - inStart) / CLOCKS_PER_SEC, inEnd - inStart);
	printf("Result: %s\n", mass);
	fprintf(fp, "Result: %s\n", mass);

	char c = 'b';
	int index = linearSearch(mass, c, size);
	printf("Index for %c = %i\n", c, index);
	fprintf(fp, "Index for %c = %i\n", c, index);
	fclose(fp);
	system("pause");
	return 0;
}
