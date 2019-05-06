#ifndef Tool_h
#define Tool_h
#include <stdio.h>
FILE* fo;

void bubbleSort(char* anArray);
void vibirSort(char* anArray);
void vstavkaSort(char* anArray);
char* getFile(char* path_to_file);
void writeFile(char* anArray, char* file);

#endif
