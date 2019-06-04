
//gcc -pthread -o run figures.c figures.h function.c header.h main.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

#include <pthread.h>

#include "figures.h"
#include "header.h"

pthread_mutex_t mutex;
pthread_mutex_t mutex2;

int getch(void);


void *threadFunc(void *resolution)
{

    long int clock_fun = 0;
    long int clock_out_sur = 0;
    clock_t clock_now;


    int time_stop = 500000;


    int numb_figure_now = 0;
    int numb_figure = 0;


    time_t times;
    int cadr_in_sec = 0;
    int FPS = 0;


    int point = 0;


    int next_figure;

    int *addr = (int *)resolution;;
    addr[1] = 0;



    //////////////////////////////////////////////настройка робочой области
     for(int line = 0; line < max_line; line++)
         for(int col = 0; col < max_col; col++)
         {
             Surface.surface[line][col] = 0;
             Surface.colic[line][col] = 0;
         }

     for(int col = 0; col < max_col; col++)
         Surface.surface[max_line - 1][col] = 1;
     for(int line = 0; line < max_line; line++)
     {
         Surface.surface[line][max_col-1] = 1;
         Surface.surface[line][0] = 1;
     }
     //out_surface();
     next_figure = add_figu(rand() % 7 + 1);
     //////////////////////////////////////////////////////////////////////




    while (1)
    {   
        clock_now = clock();
        //            out_surface();
        //            printf(" %i    ", point);
        //            printf("\t%i   ", numb_figure_now);
        //            printf("\tFPS: %i\n", FPS);
        //////////////////////////////////////////////// synchronization
        pthread_mutex_lock(&mutex);
        pthread_mutex_unlock(&mutex);
        ///////////////////////////////////////////////



        if( ( clock_now - clock_out_sur ) > 60000)
        {

            out_surface(next_figure);
            printf(" %i    ", point);
            printf("FPS: %i\n", FPS);

            if((time(NULL) - times) >= 1)
            {
                times = time(NULL);
                FPS = cadr_in_sec;
                cadr_in_sec = 0;
            }
            else
                cadr_in_sec++;

            //////////////////////////
            clock_out_sur = clock_now;
            //////////////////////////
        }



        if( ( clock_now - clock_fun ) > time_stop)
        {

            if(*addr == 66 || rules_game() == 1)
            {
                addr[1] = 66;
                printf("\n                ");
                printf("      GAME OVER\n");
                save_point(point);
                pthread_mutex_unlock(&mutex);
                pthread_exit(NULL);
            }

            if(fall_figu_surf() == 1)
            {
                save_changes();
                add_point(&point, job_with_line());
                next_figure = add_figu(next_figure);
                numb_figure_now++;
            }


            if( ( numb_figure_now - numb_figure ) == 5)
            {
                if(time_stop >= 70000)
                    time_stop = time_stop - 10000;

                numb_figure = numb_figure_now;
            }

            ///////////////////////
            clock_fun = clock_now;
            //////////////////////
        }

    }
    pthread_exit(NULL);
}





void *boot_command(void *resolution)
{
    clock_t clock_now;

    int *addr = (int *)resolution;


    while(1)
    {
        char input;

        clock_now = clock();

        pthread_mutex_unlock(&mutex);
        input = getch();
        //pthread_mutex_lock(&mutex2);
        pthread_mutex_lock(&mutex);


        if(addr[1] == 66)
        {
            pthread_mutex_unlock(&mutex);
            pthread_exit(NULL);
        }


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

            if ( clock() - clock_now > 20000 )
                fall_figu_surf();
            break;
        case 's':
            while(getch() != 's');
            break;
        case 'q':
            *addr = 66;
            pthread_mutex_unlock(&mutex);
            pthread_exit(NULL);
            break;
        }
    }

}





int main()
{
    srand(time(NULL));


    int resolution[2] = {0};

    pthread_t thread;
    pthread_t thread_boot;

    printf("h - help\n");
    printf("#");

    while(1)
    {
        char input;



        scanf("%c", &input);
        //input = getch();


        switch (input) {
        case 'g':
            resolution[0] = 0;
            resolution[1] = 0;

            pthread_create(&thread_boot, NULL, boot_command, (void *)&resolution[0]);
            pthread_create(&thread, NULL, threadFunc, (void *)&resolution);


            pthread_join(thread_boot, NULL);
            pthread_join(thread, NULL);

            break;
        case 'r':
            result_point();
            break;
        case 'h':
            help();
            break;
        case 'q':
            printf("\n");
            return 0;
            break;
        default:
            printf("#");
        }


    }






    printf("\n");
    //system("clear");
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

