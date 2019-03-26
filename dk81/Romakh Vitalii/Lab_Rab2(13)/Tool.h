#include <stdio.h>
#define ERROR -451

char* sortArray(char* charArr, int length);
int   getFileLength(FILE *fp);
void  writeArrayToFile(FILE *fp, char* charArr);
char *readArrayFromFile(FILE *fp);
