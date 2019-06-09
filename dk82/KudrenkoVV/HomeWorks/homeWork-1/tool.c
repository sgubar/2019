#include "tool.h"

int counterWords(char array[]) {
	if (*array == NULL) {
		return -1;
	}

	int counter = 1;

	for (int i = 0; array[i] != '\0'; i++) {
		if (array[i] == ' ') {
			counter++;
		}
	}

	return counter;
}
