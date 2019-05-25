#include "Header.h"

void main(void) 
{
	int length = structSize();

	Node* list_begin = (Node*)malloc(sizeof(Node));
	Node* list_end = list_begin;

	scanf("%i", &list_begin->Value);
	
	for (int i = 1; i < length; i++)
	{
		Node* list_add = (Node*)malloc(sizeof(Node));
		scanf("%i", &list_add->Value);

		list_add->prev = (void*)list_end;
		list_end->next = (void*)list_add;
		list_end = list_add;
	}
	
	for (Node* list_seek = list_end->prev; list_seek != list_begin; list_seek = list_seek->prev)
	{
		printf("%i\n", list_seek->Value);
	}
	
}
