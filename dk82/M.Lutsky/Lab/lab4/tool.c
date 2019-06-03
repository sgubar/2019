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
		c = fgetc(file);
	}
	printf("\n");
	fseek(file, 0l, SEEK_SET);
	return list;
}


List *createList() {
	List *list = (List *)malloc(sizeof(List));
	list->size = 0;
	list->firstNode = NULL;
	list->lastNode = NULL;
	return list;
}


Node *createNode(char c) {
	Node *node = (Node *)malloc(sizeof(Node));

	node->next = NULL;
	node->c = c;
	return node;
}

void deleteNode(Node *node) {
	if (node != NULL) {
		free(node);
	}
}

void deleteList(List *list) {
	int deleteBackwards = 0;
	Node *node = NULL;
	Node *nextNode = NULL;
	if (list != NULL) {
		if (list->firstNode != NULL) {
			node = list->firstNode;
		}
		while (node != NULL) {
			nextNode = node->next;
			deleteNode(node);
			node = nextNode;
		}
	}
}

void addNode(List *list, Node *node) {
	if (list != NULL && node != NULL) {
		if (list->size == 0) {
			list->firstNode = node;
			list->lastNode = node;
		}
		else {
			list->lastNode->next = node;
			node->next = NULL;
			list->lastNode = node;
		}
		list->size++;
	}
}

List *doubleElement(List *list, char element) {
	if (list == NULL || list->firstNode == NULL) {
		return -1;
	}

	Node *node = list->firstNode;

	while (node != NULL) {
		if (node->c == element) {
			Node *tmp = createNode(node->c);
			tmp->next = node->next;
			node->next = tmp;
			list->size++;
			node = tmp;
		}

		node = node->next;
	}

	return list;
}


void printToFileList(FILE *fp, List *list) {
	if (fp == NULL || list == NULL || list->firstNode == NULL) {
		return -1;
	}

	Node *node = list->firstNode;

	while (node != NULL) {
		printf("%c", node->c);
		fprintf(fp, "%c", node->c);
		node = node->next;
	}
	printf("\n");

	fseek(fp, 0l, SEEK_SET);
}
