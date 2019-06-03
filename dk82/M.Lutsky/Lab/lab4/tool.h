#include <stdio.h>

typedef struct tagNode Node;
typedef struct tagList List;

struct tagNode {
	char c;
	Node *next;
};

struct tagList {
	int size;
	Node *firstNode;
	Node *lastNode;
};


List *createList();
List *readFile(FILE *file);

List *doubleElement(List *list, char element);
Node *createNode(char c);
void deleteNode(Node *node);
void deleteList(List *list);
void printToFileList(FILE *fp, List *list);

void addNode(List *list, Node *node);
