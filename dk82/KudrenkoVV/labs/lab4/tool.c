#include "tool.h"

List *readFile(FILE *file) {
	char c = fgetc(file);

	List *list = createList();
	Node *node;

	int start = 1;

	while (c != EOF) {
		printf("%c", c);
		node = createNode(c, NULL, NULL);
		addNode(list, node);
	}
	printf("\n");
	return list;
}


List *createList() {
	List *list = (List *)malloc(sizeof(List));
	list->size = 0;
	list->headNode = NULL;
	list->tailNode = NULL;
	return list;
}

void outputElements(Node *node, int size, FILE *fp) {
	List *list = readFile(fp);

	printElementsNormal(list->headNode, list->size, fp);
	printElementsNormal(list->headNode, list->size, fp);

	printElementsReverse(list->headNode, list->size, fp);
	printElementsReverse(list->headNode, list->size, fp);

}

void printElementsNormal(Node *node,int size, FILE *fp) {
	Node *head = node;
	Node *tail;

	int i, j;
	for (j = 0; j < 1; j++) {
		for (i = 0; i < size; i++) {
			printf("%c", node->c);
			fprintf(fp, "%c", node->c);
			if (i != size - 1) node = node->next;
		}
		printf("\n");
		fprintf(fp, "\n");
		tail = node;
		node = head;
	}

}

void printElementsReverse(Node *node, int size, FILE *fp) {
	Node *head = node;
	Node *tail;
	int i, j;

	node = tail;
	for (j = 0; j < 1; j++) {
		for (i = 0; i < size; i++) {
			printf("%c", node->c);
			fprintf(fp, "%c", node->c);
			node = node->prev;
		}
		printf("\n");
		fprintf(fp, "\n");
		node = tail;
	}
}


Node *createNode(char c) {
	Node *node = (Node *)malloc(sizeof(Node));

	node->next = NULL;
	node->prev = NULL;
	node->c = c;
	return node;
}

void addNode(List *list, Node *node) {
	if (list != NULL && node != NULL) {
		if (list->size == 0) {
			list->headNode = node;
			list->tailNode = node;
		}
		else {
			list->tailNode->next = node;
			node->next = NULL;
			node->prev = list->tailNode;
			list->tailNode = node;
		}
		list->size++;
	}
}

