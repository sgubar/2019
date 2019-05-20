#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tool.h"
#include <time.h>

int main(int argc, const char * argv[])
{
	int lengthOfString= lengthOfFile("dataR.txt");

	char *String_one = readStrFromFile();
	if (NULL != String_one)
	{
		bubbleSort(lengthOfString, String_one);
	}
	writeStrToFile(String_one);

	char *String_two = readStrFromFile();
	if (NULL != String_two)
	{
		selectionSort(lengthOfString, String_two);
	}

	char *String_three = readStrFromFile();
	if (NULL != String_three)
	{
		insertionSort(lengthOfString, String_three);
	}
	
	free(String_one);
	free(String_two);
	free(String_three);

	system("pause");
	return 0;
}