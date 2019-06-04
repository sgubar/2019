#ifndef LIST_H
#define LIST_H

//typedef struct {}None;


typedef struct Cell
{
    char A;
    struct Cell *next;
}Cell;

typedef struct List
{
    struct Cell *next;
}List;


List *createList();
void destroyList(List *list);


Cell *add_cell(List *list, char symbol);
Cell *add_cell_in(List *list, int number, char symbol);


void printl(List *list);


#endif // LIST_H
