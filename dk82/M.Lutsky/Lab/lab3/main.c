#include "tool.h"

void main() {


	FILE *fp;
	fopen_s(&fp, "text.txt", "a+");

	char *mass = readFile(fp);
	fseek(fp, 0l, SEEK_END);
	int fileSize = ftell(fp);
	fclose(fp);

	shellSort(mass, fileSize);
	printf("Result: %s\n", mass);

	char c = '1';
	int index = linearSearch(mass, c, fileSize);
	printf("Index for %c = %i\n", c, index);

	system("pause");
	return 0;
}
