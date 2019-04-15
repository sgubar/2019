#include "header.h"




void clrscr()
{
    system("clear");
    //system("@cls||clear");
    //printf("\e[1;1H\e[2J");
}

void out_surface()
{
    clrscr();


    printf("\n               ");

    for(int line = 3; line < max_line; line++)
    {
        printf("\n                ");

        for(int col = 0; col < max_col; col++)
        {
            //printf("%i ", Surface.surface[line][col]);
            if(Surface.surface[line][col] != 0)
                printf("* ");
            else
                printf("  ");
        }
    }
    printf("\n               ");
}






///


void fall_singles(int line_start)
{
    for(int line = line_start; line > 0; line--)
        for(int col = 1; col < ( max_col - 1 ); col++)
        {
            Surface.surface[line][col] = Surface.surface[line - 1][col];
            Surface.surface[line - 1][col] = 0;
        }
}


void delete_line(int line)
{
    for(int col = 1; col < max_col - 1; col++)
        Surface.surface[line][col] = 0;
}


int job_with_line()
{
    int number = 0;
    for(int line = max_line - 2; line >= 0; line--)
        for(int col = 1; col < ( max_col - 1 ) && Surface.surface[line][col] == 1; col++)
        {
            if(col == max_col - 2)
            {
                delete_line(line);
                fall_singles(line);
                number++;
                line = max_line - 1;
            }
        }
    return number;
}



void add_point(int *point, int delet_line)
{
    switch (delet_line) {
    case 1:
        *point = *point + 100;
        break;
    case 2:
        *point = *point + 300;
        break;
    case 3:
        *point = *point + 700;
        break;
    case 4:
        *point = *point + 1500;
        break;
    }
}

/////



int rules_game()
{
    for(int col = 1; col < max_col - 2; col++)
    {
        if(Surface.surface[2][col] == 1)
            return 1;
    }

    return 0;
}
