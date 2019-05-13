#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tool.h"

int main(int argc, char* argv[])
{
	
	
	char* arrayshell = getArray("D:\\tt.txt");
	int result = linSearch(arrayshell, '5');

	linSearch(arrayshell, '5');

	if (result != -1)
	{
		printf("Index : %d\n", result + 1);
	}
	else
	{
		printf("Element does not exist\n");
	}

	clock_t inStart = clock();
	ShellSort(arrayshell);
	clock_t inEnd = clock();
	printf("(Method Shella)\nTime of shell sorting: %f seconds\nTime of shell sorting: %d steps\n\n",
		(float)(inEnd - inStart) / CLOCKS_PER_SEC, inEnd - inStart);
	writeArray(arrayshell, "D:\\tt.txt");

	
}