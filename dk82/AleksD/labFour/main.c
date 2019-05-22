#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <math.h>  
#include "dk_tools.h"  
#define SIZE 8

int main(int argc, char *argv[]) { 
 srand(time(NULL));
 List* ListOne = createList();
 
 int i ;
 int random;
 for (i = 0 ; i < SIZE ; i ++ )
 {
   random = 1 + rand() % 100;
  addNodeToList(ListOne, random);
 }
 
  float Mid = 0.0;
  Mid = serArifmet(ListOne); 
  printList(ListOne);
  printf("%f\n\n", Mid);
  destroyNodeWhoFirstMin(ListOne, Mid);
  printList(ListOne);
  destroyList(ListOne);
  return 0; 
}

