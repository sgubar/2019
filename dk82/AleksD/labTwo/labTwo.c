#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include "dk_tools.h"
#include <time.h> 
int main(int argc, const char argv[]) { 

writeInFileRand();

 char masOne[10000];
 getMas(masOne);
 char masTwo[10000];
 getMas(masTwo);
 char masThree[10000];
 getMas(masThree);
 
  fo = fopen("textLab.txt", "rt"); 
  
 clock_t inStart = clock();
 bubbleSort(masOne); 
 clock_t inEnd = clock();
printf("Time of bubble sorting: %f seconds\n",	(double) (inEnd-inStart)/CLOCKS_PER_SEC);
 WriteEndInFile(masOne); 

 inStart = clock();
 selectionSort(masTwo); 
  inEnd = clock();
 printf("Time of selection sorting: %f seconds\n",	(double) (inEnd-inStart)/CLOCKS_PER_SEC);
 WriteEndInFile(masTwo); 
 
 inStart = clock();
 insertionSort(masThree); 
  inEnd = clock();
 printf("Time of insertion sorting: %f seconds\n",	(double) (inEnd-inStart)/CLOCKS_PER_SEC);
 WriteEndInFile(masThree);
  
 fclose(fo);
return 0; 
} 
 
