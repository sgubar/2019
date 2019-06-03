#include <stdio.h>
#include <math.h>
#include "func.h"


struct tree * tree_create(void)
{
	struct tree * new_tree = malloc(sizeof * new_tree);
	if (new_tree == NULL) return NULL;
	new_tree->root = NULL;
	new_tree->count = 0;
	return new_tree;
}

/* ôóíêöèÿ äëÿ ïîèñêà â äåðåâå óçëà ñ óêàçàííûì çíà÷åíèåì */
float bin_search(const struct tree * search_tree, float item)
{
	const struct node * search_node;
	search_node = search_tree->root;
	for(;;)
	{
		if (search_node == NULL) return 0;
		else if (item == search_node->data) return 1;
		else if (item > search_node->data) search_node = search_node->right;  
		else search_node = search_node->left;  
	
	}
}

/* ôóíêöèÿ äëÿ äîáàâëåíèÿ óçëà â äåðåâî */
float insert(struct tree * search_tree, float item)
{
	struct node * search_node, **new;

	new = &search_tree->root;
	search_node = search_tree->root;

	for(;;)
	{
		if(search_node == NULL)
		{
			search_node = *new = malloc(sizeof * search_node);
			if(search_node != NULL)
			{
				search_node->data = item;
				search_node->left = search_node->right=NULL;
				search_tree->count++;
				return 1;
			}
			else return 0;
		}
		else if(item == search_node->data) return 2;
		else if(item > search_node->data)
		{
			new = &search_node->right;
			search_node = search_node->right;
		}
		else
		{
			new = &search_node->left;
			search_node = search_node->left;
		}
	}
}

/* ôóíêöèÿ äëÿ óäàëåíèÿ óçëà ñ îïðåäåëåííûì çíà÷åíèåì èç äåðåâà */

/* ôóíêöèÿ äëÿ îáõîäà äåðåâà áåç èñïîëüçîâàíèÿ ðåêóðñèè */
void traverse(struct tree * search_tree)
{
	struct node * stack[search_tree->count];
	int count;
	struct node * search_node;
	count = 0;
	search_node = search_tree->root;

	for(;;)
	{
		while(search_node != NULL)
		{
			stack[count++] = search_node;
			search_node = search_node->left;
		}
		if(count == 0) return ;
		search_node = stack[--count];
		printf("%f \n",search_node->data);
		search_node = search_node->right;
	}
}

/* ôóíêöèÿ äëÿ óäàëåíèÿ óçëà ñ îïðåäåëåííûì çíà÷åíèåì èç äåðåâà */
static void destroy(struct node * search_node)
{
	if(search_node == NULL) return;
	destroy(search_node->left);
	destroy(search_node->right);
	free(search_node);
} 

/* ôóíêöèÿ äëÿ ïîëíîãî óäàëåíèÿ äåðåâà */
void bin_destroy(struct tree * search_tree)
{
	destroy(search_tree->root);
	free(search_tree);
}
