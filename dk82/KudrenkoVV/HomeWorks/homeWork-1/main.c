#include <stdio.h>
#include "tool.h"

void main() {
	char array[] = "Hello, world";
	int counter = counterWords(array);

	printf("Words in <%s>: %i  ", array, counter);

	system("pause");
}