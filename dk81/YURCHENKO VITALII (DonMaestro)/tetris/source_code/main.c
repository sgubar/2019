
//gcc -pthread -o run figures.c figures.h function.c header.h main.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

#include <pthread.h>

//#include <conio.h>

#include "figures.h"
#include "header.h"

//char input;



int getch(void);




void *threadFunc(void *resolution)
{

    long int ttime;
    int numb = 0;
    int numb_out;

    int time_stop = 60000;


    int *addr = (int *)resolution;;
    int go = 0;

    *(addr + 1) = 1;

    while (!go)
    {

        for(int number = 0; number < 8; number++)
        {


            out_surface();
            printf("\n%i\n", numb_out);

            if(ttime == time(NULL))
            {
                numb++;
            }
            else
            {
                numb_out = numb;
                numb = 0;
                ttime = time(NULL);
            }




            if(numb_out > 13)
                time_stop = time_stop + 1000;
            if(numb_out < 11)
                time_stop = time_stop - 1000;



            usleep(time_stop);



//////////////////////////////////////////////// synchronization
            while(*addr == 1)
            {
                *(addr + 1) = 1;
                usleep(10000);
            }
            *(addr + 1) = 0;
///////////////////////////////////////////////



            if(*addr == 66 || rules_game() == 1)
            {
                //clrscr();
                *(addr + 1) = 66;
                printf("     GAME OVER\n");
                printf("to exit click on 'q'\n");
                pthread_exit(NULL);
            }
        }



        if(fall_figu_surf() == 1)
        {
            save_changes();
            add_figu();
        }

    }
    pthread_exit(NULL);
}





void *boot_command(void *resolution)
{
    int *addr = (int *)resolution;

    char input;
    int go = 0;
    while(!go)
    {
        *addr = 0;
        input = getch();
        *addr = 1;


        if(*(addr + 1) == 66)
            pthread_exit(NULL);


/////////////////////////////////  synchronization
        do
        {usleep(10000);}
        while(*(addr + 1) != 1);
////////////////////////////////////


        switch (input) {
        case 'x':
            bias_figu_rite();
            break;
        case 'z':
            bias_figu_left();
            break;
        case 'c':
            wheeling_figu();
            break;
        case 'v':
            while (fall_figu_surf() != 1) {}
            break;
        case 'q':
            *addr = 66;
            pthread_exit(NULL);
            break;
        }
    }

}





int main()
{
    int resolution[2] = {0};

    pthread_t thread;
    pthread_t thread_boot;

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




    //out_surface();
    add_figu();

    pthread_create(&thread_boot, NULL, boot_command, (void *)&resolution[0]);
    pthread_create(&thread, NULL, threadFunc, (void *)&resolution);


    pthread_join(thread_boot, NULL);
    pthread_join(thread, NULL);



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
            //if(pthread_join(thread, NULL) != 0)
                printf("ERROR: \n");
            break;
        }







        if(input == 'v')
        {
            while (fall_figu_surf() != 1) {}
            input = '0';
        }


*/









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
