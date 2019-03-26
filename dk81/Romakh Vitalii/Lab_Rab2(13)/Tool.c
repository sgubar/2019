#include "Tool.h"

char* sortArray(char* anArray, int length) {

	for (int i = 0; i < length - 1; i++)
	{
		int minIndex = i;

		for (int j = i + 1; j < length; j++)
		{
			if (anArray[j] > anArray[minIndex])
			{
				minIndex = j;
			}
		}

		int tmp = anArray[i];
		anArray[i] = anArray[minIndex];
		anArray[minIndex] = tmp;
	}


	return anArray;
}

int  getFileLength(FILE *fp) {
	
	if (fp == NULL) {
		return ERROR;
	}


	FILE *initPos = fp;
	int length = 0;
	char c;
	while ((c = fgetc(fp)) != EOF)
	{
		length++;
	}
	length -= 4;
	fseek(fp, 0l, SEEK_SET);

	return length;
}


char *readArrayFromFile(FILE *fp) {
	if (fp == NULL) {
		return ERROR;
	}

	int length = getFileLength(fp);
	char* arr = (char*)malloc(sizeof(char) * length);
	
	fgets(arr,length,fp);
	fseek(fp, 0l, SEEK_SET);
	return arr;
}

void  writeArrayToFile(FILE *fp, char* charArr) {
	if (fp != NULL) {
		fprintf(fp, "%s", charArr);
	}
	else {
		return ERROR;
	}
}
