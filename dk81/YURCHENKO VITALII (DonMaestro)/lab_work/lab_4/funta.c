#include <stdio.h>
#include <stdlib.h>

#include "list.h"


Cell *add_cell(List *list, char symbol)
{

    Cell *cell = (Cell *)malloc(sizeof(Cell));

    if (NULL != cell)
    {
        cell->A = symbol;
        cell->next = NULL;
    }




    if (list->next == NULL)
    {
        list->next = cell;
        return cell;
    }




    Cell *end_cell;
    end_cell = list->next;


    while (end_cell->next != NULL)
        end_cell = end_cell->next;


    end_cell->next = cell;

    return cell;
}




void printl(List *list)
{
    Cell *cell = list->next;

    do
    {
        printf("%c", cell->A);
        cell = cell->next;
    }while (cell->next != NULL);

    printf("%c\n", cell->A);

}

Cell *add_cell_in(List *list, int number, char symbol)
{
    if (number < 0)
        return NULL;


    Cell *cell = (Cell *)malloc(sizeof(Cell));
    if (cell != NULL)
    {
        cell->A = symbol;
        cell->next = NULL;
    }


    if (number == 0)
    {
        cell->next = list->next;
        list->next = cell;
        return cell;
    }


    Cell *cell_in = list->next;
    int in = 0;

    do
    {

         if (in == ( number - 1 ))
         {

             cell->next = cell_in->next;
             cell_in->next = cell;

             return cell;
         }

         cell_in = cell_in->next;
         in++;

    }while(cell_in->next != NULL);

    add_cell(list, symbol);

    return cell;
}





////////////////////////////////////////////////

List *createList()
{
    List *list = (List *)malloc(sizeof(List));

    if (list != NULL)
    {
        list->next = NULL;
    }

    return list;
}




void destroyList(List *list)
{
    Cell * cell = list->next;
    do
    {
        cell = cell->next;
        free(cell);
    }while (cell->next != NULL);

    free(list->next);
    free(list);
}
