#include "tool.h"

int fillArray(char *cArray, int size) {
 int i, counter = 0;
 
 FILE *fstream;
 fopen_s(&fstream, "read.txt", "r");
 
 fscanf_s(fstream, "%s", cArray, size);

 for (i = 0; cArray[i] != '\0'; i++) {
  counter++;
 }
 
 fclose(fstream);
 return counter;
}

void shellSort(char *cArray, int counter) {
	int j, i, step;
	char tmp;

	for (step = counter / 2; step > 0; step /= 2)
		for (i = step; i < counter; i++) {
			tmp = cArray[i];
			for (j = i; j >= step; j -= step) {
				if (tmp > cArray[j - step])
					cArray[j] = cArray[j - step];
				else
					break;
			}
			cArray[j] = tmp;
		}
}

int search(char *cArray, char requiredKey, int counter) {
  	int i;
  	
  	if(NULL == cArray || counter <= 0)
  		return -1;
	
	for (i = 0; i <= counter; i++) {
		if (cArray[i] == requiredKey) {  
		return i;
		}
	}
	return -1;
}

