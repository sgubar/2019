#include "Header.h"
#include "quickSort.h"

void main(void) {

	int size;
	char find;

	printf("rand value : ");
	scanf_s("%i", &size);

	char* buffer = randArray(size);
	printf("%s\n", buffer);

	quickSort(buffer, 0, size-1);
	//selectSort(char*, int);
	printf("%s\n", buffer);
	printf("binary search letter : ");
	scanf_s(" %c", &find);
	
	int id = binSearch(buffer, size, find);
	printf("Founded value id: %i\n", id);
	fileWrite(buffer, id);
	system("pause");
}