#include <stdio.h>
#include <string.h>
#include "dk_tool.h"
int main(int argc, char *argv[]) {
	char myString[100];
    printf("Vvedyte stroku: ");
    gets(myString);
    printf("chislo slov ravno %d\n", words(myString));
	return 0;
}
