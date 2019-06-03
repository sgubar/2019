#include <stdio.h>
#include <stdlib.h>
#include "tool.h"

int main(int argc, char *argv[]) {

	int i, counter = 0;
	
	char *cArray = (char *) malloc(sizeof(char) * 100);
	
	FILE *fstream;
	fopen_s(&fstream, "read.txt", "r");

	counter = fillArray(cArray, 100);

	FILE *stream;
	fopen_s(&stream, "write.txt", "w");
	
	printf("Array: %s\n", cArray);
	printf("Counter: %i\n", counter);
	printf("Element in unsort massive: %i\n", search(cArray, 'o', counter));
	fprintf(stream, "Element in unsort massive: %i\n", search(cArray, 'o', counter));
	
		
	shellSort(cArray, counter);
	printf("Sort array: %s\n", cArray);

	printf("Element in sort massive: %i", search(cArray, '3', counter));
	fprintf(stream, "Element in sort massive: %i", search(cArray, '3', counter));
	
	fclose(fstream);
	fclose(stream);	

	return 0;
}
