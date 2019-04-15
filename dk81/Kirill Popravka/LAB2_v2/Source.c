#include "Func.h"

void main(void)
{	
	int random;

	FILE *file;
	
	srand(time(0));

	printf("Write lenght value for random create array with a-z, A-Z\n");

	scanf_s("%i", &random);

	char* arr = randomArray(random);
	
	printf("Unsorted array: %s\n", arr);
	selectionSort(arr);
	
	fopen_s(&file, "array.txt", "w");

	printf("Sorted array: %s\n", arr);
	fileWrite(file, arr);

	fclose(file);

	system("pause");

}