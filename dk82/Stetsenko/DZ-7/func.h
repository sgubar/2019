#include <stdio.h>
#include <math.h>

struct node
{
  char data;
  struct node * left;
  struct node * right;
};
 
struct tree
{
  struct node * root;   
  int count;            
};


struct tree * tree_create(void);
char insert(struct tree * search_tree, char item);
int bin_search(const struct tree * search_tree, char item);
static void destroy(struct node * search_node);
void bin_destroy(struct tree * search_tree);
void traverse( struct tree * search_tree);
