#include "Header.h"

void main(void) {

	int size;
	char find;

	printf("rand value : ");
	scanf_s("%i", &size);

	char* buffer = randArray(size);
	printf("%s\n", buffer);
	
	selectSort(buffer);
	printf("%s\n", buffer);
	printf("binary search letter : ");
	scanf_s( " %c", &find);

	binSearch(buffer, size, find);
	fileWrite(buffer);
	freeArray(buffer);
	system("pause");
}