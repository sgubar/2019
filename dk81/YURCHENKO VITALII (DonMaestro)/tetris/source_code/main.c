
//gcc -pthread -o run figures.c figures.h function.c header.h main.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

#include <pthread.h>

//#include <conio.h>

#include "figures.h"
#include "header.h"

char input;



int getch(void);


void *threadFunc(void *arg)
{
    int go = 0;
    while (!go)
    {
        for(int number = 0; number < 2; number++)
        {
            out_surface();

            usleep(300000);


            if(input == 'q' || rules_game() == 1)
            {
                //clrscr();
                printf("     GAME OVER\n");
                printf("to exit click on 'q'\n");
                pthread_exit(NULL);
            }
        }


        if(input == 'v')
        {
            while (fall_figu_surf() != 1) {}
            input = '0';
        }
        if(fall_figu_surf() == 1)
        {
            save_changes();
            add_figu();
        }
    }
    pthread_exit(NULL);
}



int main()
{
    int go = 0;
    pthread_t thread;

    for(int line = 0; line < max_line; line++)
        for(int col = 0; col < max_col; col++)
            Surface.surface[line][col] = 0;

    for(int col = 0; col < max_col; col++)
        Surface.surface[max_line - 1][col] = 1;
    for(int line = 0; line < max_line; line++)
    {
        Surface.surface[line][max_col-1] = 1;
        Surface.surface[line][0] = 1;
    }




    out_surface();
    add_figu();


    pthread_create(&thread, NULL, threadFunc, NULL);


    while(!go)
    {
        input = getch();

        if(input == 'x')
        {
            bias_figu_rite();
            input = '0';
        }

        if(input == 'z')
        {
            bias_figu_left();
            input = '0';
        }

        if(input == 'c')
        {
            wheeling_figu();
            input = '0';
        }

        if(input == 'q')
        {
            if(pthread_join(thread, NULL) != 0)
                printf("ERROR: \n");
            break;
        }

    }


    printf("\n");
    system("clear");
    return 0;
}




int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}













/*
 *


int getche(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}*/
