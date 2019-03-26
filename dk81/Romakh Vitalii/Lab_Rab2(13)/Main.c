#include <stdio.h>
#include "Tool.h"
int main(int argc, char *argv[]) {
	
	FILE *fp;
	fopen_s(&fp,"InText.txt","r");
	char* arr = readArrayFromFile(fp);
	printf("%s\n", arr);
	fclose(fp);

	fopen_s(&fp, "OutText.txt", "w+");
	sortArray(arr,strlen(arr));
	printf("%s\n", arr);
	writeArrayToFile(fp,arr);
	fclose(fp);


	system("pause");
}