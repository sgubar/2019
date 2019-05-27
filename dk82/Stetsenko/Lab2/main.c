#include "lib.h"

void main(void)
{
	FILE *afile;
	fopen_s(&afile, "InText.txt", "r");
	char* arr = readFile(afile);
	printf("%s\n", arr);
	fclose(afile);

	fopen_s(&afile, "OutText.txt", "w+");
	bubbleSort(arr, strlen(arr));
	printf("%s\n", arr);
	readFile(afile, arr);
	fclose(afile);




	system("pause");
}
