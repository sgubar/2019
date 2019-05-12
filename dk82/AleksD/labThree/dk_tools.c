#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include "dk_tools.h" 
#define len 10000
void quickSort(char* string , int left , int right)
{
	int i;
	int j;
	i = left;
	j = right;
	char x;
	char y;
	x = string[(left + right) / 2];
	do{
		while ((string[i] < x) && (i < right)) i++;
		while ((x < string[j]) && (j > left)) j--;
		if(i<=j)
		{
			y = string[i];
			string[i] = string[j];
			string[j] = y;
			i++;
			j--;
		}
	} while (i <= j);
	
	if (left < j) quickSort (string , left , j);
	if (i < right) quickSort (string , i , right);
}

int binarySearch(char* string , char value)
{
	int max = len;
	int min = 0;
	while(min <= max)
	{
		int mid = (min + max) / 2;
		
		if (value == string[mid])
		{
		return mid;

		}
		else if(value > string[mid])
		{
			min = mid+1;
		}
		else
		{
			max = mid-1;
		}
	}
}

void getMas(char* string , char file[])
{
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
 
void WriteEndInFile(char* string ,int coordinate ,char file[]) 
{ 
 fo = fopen(file, "a+"); 
 fprintf(fo,"\n"); 
 int i;
 for (i=0; i < len; i++) 
 { 
  fprintf(fo, "%c", string[i]); 
 } 
 fprintf(fo,"\nthe element is located at coordinate %d", coordinate+1);
 fclose(fo); 
}
