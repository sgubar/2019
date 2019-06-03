#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include "func.h"

int main(void)
{
	struct tree * my_tree = tree_create();
	insert(my_tree, 12.25);
	insert(my_tree, 5.25);
	insert(my_tree, 24.25);
	insert(my_tree, 32.25);
	insert(my_tree, 14.25);
	insert(my_tree, 6.25);
	insert(my_tree, 9.25);
	insert(my_tree, 16.25);	
	traverse(my_tree);
	printf("%f \n ", bin_search(my_tree, 32.25));
	bin_destroy(my_tree);
    return 0;
}
