#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include "dk_tools.h"
#include <time.h> 
int main(int argc, const char argv[]) { 

char file[]= "C:/Users/komp/Desktop/informatika/project/labTwo/textLab.txt";
writeInFileRand(file);
 char* masOne[10000];
 getMas(masOne,file);
 char masTwo[10000];
 getMas(masTwo,file);
 char masThree[10000];
 getMas(masThree,file);
 
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
  
 
return 0; 
} 
