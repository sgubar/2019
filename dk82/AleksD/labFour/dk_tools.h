#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <math.h> 
#include <time.h>  
typedef struct tagNode Node; 
 
struct tagNode 
{ 
  int value; 
  Node* nextNode; 
}; 
 
typedef struct List 
{ 
  int count; 
  Node *head; 
  Node *end; 
   
}List; 
 
List *createList(); 
void destroyList(List* aList); 
Node* createNode(int aValue); 
Node* getParentNode(List* aList, Node* aNode);

void destroyNode(Node* aNode); 
void addNodeToList(List *aList, int aValue);
float serArifmet(List* aList);
void printList(List* aList);
void destroyNodeWhoFirstMin(List* aList , float mid);

