#ifndef tool_h
#define tool_h
#include <stdio.h>

FILE* fo;


int linSearch(char* array, char key);
void ShellSort(char* array);
char* getArray(char* path_to_file);
void writeArray(char* array, char* path_to_file);

#endif