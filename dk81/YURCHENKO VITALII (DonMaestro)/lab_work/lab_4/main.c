#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main()
{
    List *list = createList();


    add_cell(list, 'f');
    add_cell(list, 'r');
    add_cell(list, 'e');
    add_cell(list, 'e');
    add_cell(list, 'd');
    add_cell(list, 'o');
    add_cell(list, 'm');


    printl(list);

    if ( add_cell_in(list, 355, 'i') == NULL )
        printf("ERROR:\n");


    printl(list);


    destroyList(list);

    return 0;
}
