#include "tool.h"

int fillArray(char *cArray, int size) {
	int i, counter = 0;
	
	FILE *fstream;
	fopen_s(&fstream, "read.txt", "r");
	
	fscanf_s(fstream, "%s", cArray,size);

	for (i = 0; cArray[i] != '\0'; i++) {
		counter++;
	}
	fclose(fstream);
	return counter;

}

void bubbleSort(char cArray[], int counter) {
	int j, i;
	char tmp;
	
	for (j = 0; j < counter - 1; j++) {
		for (i = 0; i < counter - 1; i++) {
			if (cArray[i] < cArray[i + 1]) {  
				tmp = cArray[i];    
				cArray[i] = cArray[i + 1]; 
				cArray[i + 1] = tmp;     					
			}
		}
	}
}

void shellSort(char cArray[], int counter) {
	int j, i, step;
	char tmp;
	

	for (step = counter / 2; step > 0; step /= 2)
		for (i = step; i < counter; i++) {
			tmp = cArray[i];
			for (j = i; j >= step; j -= step) {
				if (tmp < cArray[j - step])
					cArray[j] = cArray[j - step];
				else
					break;
			}
			cArray[j] = tmp;
		}
}

void insertionSort(char cArray[], int counter) {
    char newElement, location;
    int i;

    for (i = 1; i < counter; i++) {
        newElement = cArray[i];
        location = i - 1;
        while(location >= 0 && cArray[location] < newElement) {
            cArray[location+1] = cArray[location];
            location = location - 1;
        }
        cArray[location+1] = newElement;
    }
}
