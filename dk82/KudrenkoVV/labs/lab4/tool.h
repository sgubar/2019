#include <stdio.h>


typedef struct tagNode {
	char c;
	Node *next;
	Node *prev;
}Node;

typedef struct tagList {
	int size;
	Node *headNode;
	Node *tailNode;
}List;


List *createList();
List *readFile(FILE *file);

void printElements(Node *node, int size, FILE *fp);
void printElementsNormal(Node *node,int size, FILE *fp);
void printElementsReverse(Node *node, int size, FILE *fp);

void outputElements(Node *node, int size, FILE *fp);
Node *createNode(char c);


void addNode(List *list, Node *node);