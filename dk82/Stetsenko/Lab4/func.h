#ifndef dk_line_h
#define dk_line_h

#include <string.h>



typedef struct list
{
  int field; 
  struct list *ptr; 
}list;


struct list * init(int a);
void listprint(list *lst);
struct list * addelem(list *lst, int number);
struct list * swap(struct list *lst1, struct list *lst2, struct list *head);



#endif
