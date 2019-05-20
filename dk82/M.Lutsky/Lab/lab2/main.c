#include "tool.h"

void main() {
	FILE *fp;
	fopen_s(&fp, "text.txt", "a+");

	char *mass = readFile(fp);
	fseek(fp, 0l, SEEK_END);
	int fileSize = ftell(fp);
	fclose(fp);

	insertionSort(mass, fileSize);
	printf("Result: %s\n", mass);
	fclose(fp);

	system("pause");
	return 0;
}
