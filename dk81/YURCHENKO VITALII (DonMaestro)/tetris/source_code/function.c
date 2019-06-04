#include "header.h"
#include "figures.h"


#define RESET    "\033[0m"
#define BLACK    "\033[1;30m"    //чёрный цвет знаков
#define RED      "\033[1;31m"    //красный цвет знаков
#define GREEN    "\033[1;32m"    //зелёный цвет знаков
#define YELLOW   "\033[1;33m"    //желтый цвет знаков
#define BLUE     "\033[1;34m"    //синий цвет знаков
#define VIOLET   "\033[1;35m"    //фиолетовый цвет знаков
#define SEA_WAVE "\033[1;36m"    //цвет морской волны знаков
#define GRAY     "\033[1;37m"    //серый цвет знаков

void clrscr()
{
    system("clear");
    //system("@cls||clear");
    //printf("\e[1;1H\e[2J");
}


void colic_fun(int colic)
{
    switch (colic) {
    case 0:
        printf("%s[]%s", GRAY, RESET);
        break;
    case 1:
        printf("%s[]%s", RED, RESET);
        break;
    case 2:
        printf("%s[]%s", GREEN, RESET);
        break;
    case 3:
        printf("%s[]%s", YELLOW, RESET);
        break;
    case 4:
        printf("%s[]%s", BLUE, RESET);
        break;
    case 5:
        printf("%s[]%s", VIOLET, RESET);
        break;
    case 6:
        printf("%s[]%s", SEA_WAVE, RESET);
        break;
    case 7:
        printf("%s[]%s", BLACK, RESET);
        break;
    }
}


int numline(int line)
{
    if ( line == 4)
        return 0;
    if ( line == 5)
        return 4;
}

void out_surface(int figure)
{
    int mfigure[7][9] = {{2, 0, 0, 0, 2, 2, 2, 0, 1},
                         {0, 0, 2, 0, 2, 2, 2, 0, 2},
                         {2, 2, 0, 0, 0, 2, 2, 0, 3},
                         {0, 2, 2, 0, 2, 2, 0, 0, 4},
                         {0, 2, 0, 0, 2, 2, 2, 0, 5},
                         {0, 2, 2, 0, 0, 2, 2, 0, 6},
                         {0, 0, 0, 0, 2, 2, 2, 2, 7}};


    ////////////////



    clrscr();


    printf("\n               ");

    for(int line = 3; line < max_line; line++)
    {
        printf("\n                ");

        for(int col = 0; col < max_col; col++)
        {
            //printf("%i ", Surface.surface[line][col]);

            if(Surface.surface[line][col] != 0)
                colic_fun(Surface.colic[line][col]);
            else
                printf("  ");
        }


        for (int col = numline(line); col < ( numline(line) + 4 ) && line < 7; col++)
        {
            if (line == 3 || line == 6)
                colic_fun(0);
            else if(mfigure[figure - 1][col] != 0)
                colic_fun(mfigure[figure - 1][8]);
            else
                printf("  ");

            if ( col == 3 || col == 7 )
                colic_fun(0);
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








void result_point()
{
    FILE *fres;

    char fname[25];
    int fpoint;


    if((fres = fopen("results.txt", "rt")) == NULL)
    {

        if((fres = fopen("results.txt", "w+t")) == NULL)
        {
            printf("ERROR:\n");
            return;
        }

        for (int number = 0; number < 5; number++)
            fprintf(fres, "username 0\n");
        fclose(fres);

        if((fres = fopen("results.txt", "r+t")) == NULL)
        {
            printf("ERROR:\n");
            return;
        }

    }



    printf("GAME RECORD\n");

    for(int now = 0; now < 5; now++)
    {
        fscanf(fres, "%s%i", fname, &fpoint);
        printf("%i: %s == %i\n", (now + 1), fname, fpoint);
    }

    fclose(fres);

}



void ch_ch(char ch1[25], char ch2[25])
{
    for(int now = 0; now < 25; now++)
        ch1[now] = ch2[now];
}




void bubble(char name[6][25], int point[6])
{
    for(int bulb = 0; bulb < 6; bulb++)
        for(int i = 1; i < 6; i++)
        {
            int cell_point;
            char cell_name[25];

            if(point[i] > point[i-1])
            {
                cell_point = point[i-1];
                point[i-1] = point[i];
                point[i] = cell_point;

                ch_ch(cell_name, name[i-1]);
                ch_ch(name[i-1], name[i]);
                ch_ch(name[i], cell_name);
            }
        }
}





void save_point(int point)
{
    FILE *fres;

    char name[25];
    char fname[6][25];

    int fpoint[6] = { 0 };

    int s = 0;


    if((fres = fopen("results.txt", "r+t")) == NULL)
    {

        if((fres = fopen("results.txt", "w+t")) == NULL)
        {
            printf("ERROR:\n");
            return;
        }

        for (int number = 0; number < 5; number++)
            fprintf(fres, "username 0\n");
        fclose(fres);

        if((fres = fopen("results.txt", "r+t")) == NULL)
        {
            printf("ERROR:\n");
            return;
        }

    }


    for(int now = 0; now < 5; now++)
        fscanf(fres, "%s %i\t\n", fname[now], &fpoint[now]);

    fclose(fres);



    if(point < fpoint[4])
        return;
    else if(point > fpoint[4])
    {
        printf("enter the name: ");
        scanf("%s", name);
    }



    for(int now = 0; now < 5; now++)
    {
        if(strcmp(name, fname[now]) == 0 && point > fpoint[now])
        {
            fpoint[now] = point;
            now = 6;
            s = 1;
        }
        else if(strcmp(name, fname[now]) == 0 && point < fpoint[now])
            return;
    }




    if(point > fpoint[4] && s == 0)
    {
        ch_ch(fname[5], name);
        fpoint[5] = point;
    }



    bubble(fname, fpoint);



    if((fres = fopen("results.txt", "w+t")) == NULL)
    {
        printf("ERROR:\n");
        return;
    }


    for(int now = 0; now < 5; now++)
        fprintf(fres, "%s %i\n", fname[now], fpoint[now]);


    fclose(fres);

}







void help()
{
    printf("q - output\n");
    printf("g - start new game\n");
    printf("r - results of players\n");

}


