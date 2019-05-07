#include <stdlib.h>
#include "luna_tool.h"


void Type_chooser(int *mass, int quantity, int choice)
{
    clock_t time;
  scanf("%d", &choice);
 while(choice != 1 && choice != 2 && choice != 3)
    {
        printf("Specify the sort type: ");
        scanf("%d", &choice);
    }
      switch(choice)
    {
        case 1:
            time = Bubble(mass, quantity);
            printf("Time of sorting by Bubble = %f", (double)time/CLOCKS_PER_SEC);
            Filewriter(mass, quantity, "Bubble.txt");
            break;
        case 2:
            time = Select(mass, quantity);
            printf("Time of sorting by Select = %f", (double)time/CLOCKS_PER_SEC);
            Filewriter(mass, quantity, "Select.txt");
            break;
        case 3:
            time = Insert(mass, quantity);
            printf("Time of sorting by Insert = %f", (double)time/CLOCKS_PER_SEC);
            Filewriter(mass, quantity, "Insert.txt");
            break;
    }
}
clock_t Bubble(int *mass, int quantity)
{
    clock_t bub_time;
    bub_time = clock();
    int i, j;
    for (i = 1; i <= quantity - 1; i++)
    {
        for (j = 0; j <= quantity - 2; j++) {
            if (mass[j] > mass[j + 1])
            {
                swap(&mass[j], &mass[j + 1]);
            }
        }
    }
    bub_time = clock() - bub_time;
    return bub_time;
}

clock_t Select(int *mass, int quantity)
{
    clock_t sel_time;
    sel_time = clock();
    int i;
    for ( i = 0; i < quantity; i++)
    {
        int d = i;
        int j;
        for ( j = i+1; j < quantity; j++)
        {
            if (mass[j] < mass[d])
            {
                d = j;
            }
        }
        swap(&mass[d], &mass[i]);
    }
    sel_time = clock() - sel_time;
    return sel_time;
}
clock_t Insert(int *mass, int quantity)
{
    clock_t in_time;
    in_time = clock();
    int i;
    for ( i = 1; i <= quantity - 1; i++)
    {
        int x = mass[i];

        int j = i;
        while (j > 0 && mass[j - 1] < x)
        {
            mass[j] = mass[j - 1];
            j--;
        }
        mass[j] = x;
    }
    in_time = clock() - in_time;
    return in_time;
}
void swap (int *x, int *y)
{
    int position = *x;
    *x = *y;
    *y = position;
}

void random(int *mass, int quantity)
{
    int i;
    for( i = 0; i < quantity; i++)
    {
        switch(rand() % 2)
        {
        case 0: mass[i] = rand() % 26 + 97; break;
        case 1: mass[i] = rand() % 10 + 48; break;
        }
    }
}

void Filewriter(int *mass, int quantity, char* name)
{
    int i;
    FILE *file = fopen(name, "w");
    for ( i = 0; i < quantity; i++)
    {
        fprintf(file, "%c ", mass[i]);
    }
    fclose(file);
}
