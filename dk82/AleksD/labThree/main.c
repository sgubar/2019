#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include "dk_tools.h"
#include <time.h> 
#define len 10000
int main(int argc, const char argv[]) { 
char file[]= "C:/Users/komp/Desktop/informatika/project/labThree/textLabThree.txt";
writeInFileRand(file);
  char mas[len];
  
  getMas(mas , file);
 clock_t inStart = clock();
 quickSort(mas,0,len-1);
 clock_t inEnd = clock();
 printf("Time of sorting: %f seconds\n",	(double) (inEnd-inStart)/CLOCKS_PER_SEC);

 
   int i;
 for (i = 0; i < len; i ++)
 {
 	printf("%c",mas[i]);
 }
 
 char value = 's';
  inStart = clock();
 int g = binarySearch(mas,value);
  inEnd = clock();
 printf("\nTime of searching: %f seconds\n",	(double) (inEnd-inStart)/CLOCKS_PER_SEC);
 printf("coordinate:%d",g+1);
  WriteEndInFile(mas,g,file); 
 fclose(fo);
return 0; 
} 
 
