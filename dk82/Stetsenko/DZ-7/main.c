#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include "func.h"

int main(void)
{
	struct tree * my_tree = tree_create();
	insert(my_tree, 'a');
	insert(my_tree, 'c');
	insert(my_tree, 'm');
	insert(my_tree, 'w');
	insert(my_tree, 'v');
	insert(my_tree, 'P');
	insert(my_tree, 'F');
	insert(my_tree, 'b');	
	traverse(my_tree);
	printf("%i\n ", bin_search(my_tree, 'm'));
	bin_destroy(my_tree);
    return 0;
}
