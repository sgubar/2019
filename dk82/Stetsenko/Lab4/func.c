#include "func.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list * init(int a) // à- çíà÷åíèå ïåðâîãî óçëà
{
  struct list *lst;
  lst = (struct list*)malloc(sizeof(struct list)+1);
  lst->field = a;
  lst->ptr = NULL;   // ýòî ïîñëåäíèé óçåë ñïèñêà
  return(lst);
}

void listprint(list *lst)
{
  struct list *p;
  p = lst;
  do {
    printf("%d - \n", p->field);    // âûâîä çíà÷åíèÿ ýëåìåíòà p  
    p = p->ptr;        // ïåðåõîä ê ñëåäóþùåìó óçëó
  } while (p != NULL);
}

struct list * addelem(list *lst, int number)
{
  struct list *temp, *p;
  temp = (struct list*)malloc(sizeof(list)+1);
  p = lst->ptr; 
  lst->ptr = temp; 
  temp->field = number; 
  temp->ptr = p; 
  
  return(temp);
}


struct list * sort(list *lst)
{
	int temp;
	struct list *lst1 = lst, *lst2 = 0;
	for(lst2 = lst; lst2; lst2 = lst2->ptr)
	{
		for(lst1 = lst; lst1->ptr; lst1 = lst1->ptr)
		{
			if(lst1->field < lst1->ptr->field)
			{
				temp = lst1->field ;
				lst1->field = lst1->ptr->field ;
				lst1->ptr->field = temp;
			}
		}
	}		
}
