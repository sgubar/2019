#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include "dk_tools.h" 
#define len 10000
void bubbleSort(char* string1) { 
 char flag; 
 int i; 
 int j; 
 for (i = 0; i < len; i++)  
 { 
  for (j=0; j < len-1; j++) 
  { 
   if (string1[j] > string1[j + 1]) 
   { 
    flag = string1[j]; 
    string1[j] = string1[j + 1]; 
    string1[j + 1] = flag; 
   } 
  } 
 } 
} 
 
void selectionSort(char* string2) { 
 int i; 
 int j; 
 int flags; 
 for (i=0; i < len; i++) 
 { 
  int min = i; 
 
  for (j = i + 1; j < len; j++) 
  { 
   if (string2[min] > string2[j]) 
   { 
    min = j; 
   } 
  } 
  flags = string2[i]; 
  string2[i] = string2[min]; 
  string2[min] = flags; 
 } 
} 
 
void insertionSort(char* string3) { 
 char temp; 
 int item; 
 int i = 0; 
 for (i; i < len; i++) 
 { 
  temp = string3[i]; 
  item = i - 1; 
  while (item >= 0 && string3[item] < temp) 
  { 
   string3[item+1] = string3[item];  
   item--; 
   string3[item+1] = temp;
  } 
 } 
} 
 
void getMas(char* string, char file[]) { 
 int i;
 fo = fopen(file, "r"); 
 for (i=0; i < len; i++) 
 { 
  fscanf(fo, "%c", &string[i]); 
 } 
 fclose(fo); 
} 
 
void writeInFileRand(char file[]) { 
 int i; 
 int flag;
 fo = fopen(file,"w+"); 
 for (i=0; i < len/2; i++) 
 { 
  fprintf(fo,"%c", rand() % 26 + 97);
  fprintf(fo,"%c", rand() % 26 + 65);
 } 
 fclose(fo); 
} 
 
void WriteEndInFile(char* string) 
{ 
 fo = fopen("textLab.txt", "a+"); 
 fprintf(fo,"\n"); 
 int i;
 for (i=0; i < len; i++) 
 { 
  fprintf(fo, "%c", string[i]); 
 } 
 fclose(fo); 
}

