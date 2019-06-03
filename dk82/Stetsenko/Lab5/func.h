#include <stdio.h>
#include <math.h>

struct node
{
  float data;
  struct node * left;
  struct node * right;
};
 
struct tree
{
  struct node * root;   
  int count;            
};


struct tree * tree_create(void);
float insert(struct tree * search_tree, float item);
float bin_search(const struct tree * search_tree, float item);
static void destroy(struct node * search_node);
void bin_destroy(struct tree * search_tree);
void traverse( struct tree * search_tree);
