#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main() {

	Node *head = NULL;
	Vvod(&head);
	bubbleSort(head);
	vivod(head);
	destroylist(head);


	system("PAUSE");
}