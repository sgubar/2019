#ifndef dk_tools_h 
 
#define dk_tools_h 
FILE* fo;
void quickSort(char* string , int left, int right);
int binarySearch(char* string , char value);
void getMas(char* string,char file[]); 
void writeInFileRand(char file[]); 
void WriteEndInFile(char* string ,int coordinate ,char file[]);
 
#endif
