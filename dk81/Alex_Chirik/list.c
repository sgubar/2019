#include "list.h"
#include <stdio.h>


Node *CreateNode(int value){
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;
	return node;
}

void Vvod(Node ** head) {
	int k, l;
	Node* prednoda = NULL;
	printf("Enter the number of items :");
	scanf_s("%d", &k);
	for (int i = 0; i < k; i++) {
		printf("Enter item #%d value :",i+1);
		scanf_s("%d", &l);
		Node* node = CreateNode(l);
		if (prednoda == NULL) {
			*head = node;
		} 
		else {
			prednoda->next = node;
		}
		prednoda = node;
	}
}

void vivod(Node * node) {
	while (node != NULL) {
		printf("%d ", node->value);
		node = node->next;
	}
	printf("\n");
}

void destroylist(Node * node) {
	while (node != NULL) {
		Node * next = node->next;
		free(node);
		node = next;
	}
}

void bubbleSort(struct Node *start) {
	int swapped, i;
	struct Node *ptr1;
	struct Node *lptr = NULL;

	if (start == NULL)
		return;

	do
	{
		swapped = 0;
		ptr1 = start;

		while (ptr1->next != lptr)
		{
			if (ptr1->value > ptr1->next->value)
			{
				int temp = ptr1->value;
				ptr1->value = ptr1->next->value;
				ptr1->next->value = temp;

				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	} while (swapped);
}