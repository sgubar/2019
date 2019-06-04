#include "header.h"
#include "figures.h"


void figu_pri(int figure[8], int color)
{
    for(int line = 0, col_f = 0; line < 2; line++)
        for(int col = 0; col < 4; col++, col_f++)
        {
            Surface.surface[line][ col + max_col/3 ] = figure[col_f];
            Surface.colic[line][ col + max_col/3 ] = color;
        }
}

int add_figu(int random)
{


    int figure_1[9] = {2, 0, 0, 0, 2, 2, 2, 0, 1};
    int figure_2[9] = {0, 0, 2, 0, 2, 2, 2, 0, 2};
    int figure_3[9] = {2, 2, 0, 0, 0, 2, 2, 0, 3};
    int figure_4[9] = {0, 2, 2, 0, 2, 2, 0, 0, 4};
    int figure_5[9] = {0, 2, 0, 0, 2, 2, 2, 0, 5};
    int figure_6[9] = {0, 2, 2, 0, 0, 2, 2, 0, 6};
    int figure_7[9] = {0, 0, 0, 0, 2, 2, 2, 2, 7};



    //srand(time(NULL));
    //rand()/(RAND_MAX / 7)

    switch (random) {
    case 1:

        figu_pri(figure_1, figure_1[8]);
        break;
    case 2:

        figu_pri(figure_2, figure_2[8]);
        break;
    case 3:

        figu_pri(figure_3, figure_3[8]);
        break;
    case 4:

        figu_pri(figure_4, figure_4[8]);
        break;
    case 5:

        figu_pri(figure_5, figure_5[8]);
        break;
    case 6:

        figu_pri(figure_6, figure_6[8]);
        break;
    case 7:

        figu_pri(figure_7, figure_7[8]);
        break;
    }
    return ( rand() % 7 + 1 );
}


int audit_figu_rite()
{
    for(int line = max_line - 1; line >= 0; line--)
        for(int col = max_col - 1; col >= 0; col--)
        {
            if(Surface.surface[line][col] == 2
                    && Surface.surface[line][col + 1] == 1)
                return 1;
        }
    return 0;
}




int figure_line()
{
    for(int line = (max_line - 1); line >= 0; line--)
        for(int col = 0; col < max_col; col++)
            if(Surface.surface[line][col] == 2)
            {
                if(Surface.surface[line][col + 1] == 1)
                    return -3;
                else if(Surface.surface[line][col + 2] == 1)
                    return -2;

                if(Surface.surface[line][col - 1] == 1)
                    return 0;
            }
    return -1;
}



void search_left_ground()
{
    Figu_coord.point_col_e = 0;


    for(int line = max_line - 1; line >= 0; line--)
        for(int col = max_col - 1; col >= 0; col--)
        {
            if(Surface.surface[line][col] == 2)
                Figu_coord.point_line = line;
        }

    for(int col = max_col - 1; col >= 0; col--)
        for(int line = max_line - 1; line >= 0; line--)
        {
            if(Surface.surface[line][col] == 2)
                Figu_coord.point_col = col;
        }

    for(int line = 0; line < max_line; line++)
        for(int col = 0; col < max_col; col++)
        {
            if(Surface.surface[line][col] == 2)
                Figu_coord.point_line_e = line;
        }

    for(int line = 0; line < max_line; line++)
        for(int col = 0; col < max_col; col++)
        {
            if(Surface.surface[line][col] == 2 && Figu_coord.point_col_e < col)
                Figu_coord.point_col_e = col;

        }
}


int wheeling_figu()
{

    search_left_ground();

    int max_col_m = Figu_coord.point_col_e - Figu_coord.point_col + 1;
    int max_line_m = Figu_coord.point_line_e - Figu_coord.point_line + 1;

    int massif[max_line_m][max_col_m];
    int colic_m[max_line_m][max_col_m];

    int left_shift = 0;
    int top_shift = 0;


    if(audit_figu_rite() == 1 && (max_line_m - max_col_m) == 1)
        left_shift = -1;
    else if((max_line_m - max_col_m) == -3)
        left_shift = 1;
    else if((max_line_m - max_col_m) == 3)
        left_shift = figure_line();




///////////////////////////////////////////////////////massif[][] = {0}
    for(int line = 0; line < max_line_m; line++)
        for(int col = 0; col < max_col_m; col++)
            massif[max_line_m][max_col_m] = 0;

    for(int line = 0; line < max_line_m; line++)
        for(int col = 0; col < max_col_m; col++)
            if(Surface.surface[line + Figu_coord.point_line][col + Figu_coord.point_col] == 2)
            {
                massif[line][col] = Surface.surface[line + Figu_coord.point_line][col + Figu_coord.point_col];
                colic_m[line][col] = Surface.colic[line + Figu_coord.point_line][col + Figu_coord.point_col];
            }




    ///////////////////////////////////////////////////////////////////////check
    for(int line = 0, col_m  = 0; line < max_col_m; line++, col_m++)
        for(int col = 0, line_m = max_line_m - 1; col < max_line_m; col++, line_m--)
        {
            if(massif[line_m][col_m] == 2 &&
                    Surface.surface[line + Figu_coord.point_line + top_shift][col + Figu_coord.point_col + left_shift] == 1)
                return 1;
        }



    /////////////////////////////////////////////////delete figure
    for(int line = 0; line < max_line_m; line++)
        for(int col = 0; col < max_col_m; col++)
            if(Surface.surface[line + Figu_coord.point_line][col + Figu_coord.point_col] == 2)
            {
                Surface.surface[line + Figu_coord.point_line][col + Figu_coord.point_col] = 0;
                Surface.colic[line + Figu_coord.point_line][col + Figu_coord.point_col] = 0;
            }

    /////////////////////////////////////////////////////////////////////add turn figure
    for(int line = 0, col_m  = 0; line < max_col_m; line++, col_m++)
        for(int col = 0, line_m = max_line_m - 1; col < max_line_m; col++, line_m--)
        {
            if(massif[line_m][col_m] == 2)
            {
                Surface.surface[line + Figu_coord.point_line + top_shift]
                        [col + Figu_coord.point_col + left_shift] = massif[line_m][col_m];

                Surface.colic[line + Figu_coord.point_line + top_shift]
                        [col + Figu_coord.point_col + left_shift] = colic_m[line_m][col_m];
            }
        }
    return 0;
}



//////////////////////// движение в сторону/////////////////

int bias_figu_rite()
{
    if(audit_figu_rite() == 1)
        return 1;

        for(int line = max_line - 1; line >= 0; line--)
            for(int col = max_col - 1; col >= 0; col--)
            {
                if(Surface.surface[line][col] == 2)
                {
                    Surface.surface[line][col + 1] = 2;
                    Surface.surface[line][col] = 0;


                    Surface.colic[line][col + 1] = Surface.colic[line][col];
                    Surface.colic[line][col] = 0;
                }
            }
    return 0;
}


int bias_figu_left()
{
    for(int line = max_line - 1; line >= 0; line--)
        for(int col = 0; col < max_col; col++)
        {
            if(Surface.surface[line][col] == 2
                    && Surface.surface[line][col - 1] == 1)
                return 1;
        }

        for(int line = max_line - 1; line >= 0; line--)
            for(int col = 0; col < max_col; col++)
            {
                if(Surface.surface[line][col] == 2)
                {
                    Surface.surface[line][col - 1] = 2;
                    Surface.surface[line][col] = 0;


                    Surface.colic[line][col - 1] = Surface.colic[line][col];
                    Surface.colic[line][col] = 0;
                }
            }
    return 0;
}



//////////////////////////////////////////////////////////

int fall_figu_surf()
{
    for(int line = max_line - 1; line >= 0; line--)
        for(int col = max_col - 1; col >= 0; col--)
        {

            if(Surface.surface[line][col] == 2
                    && Surface.surface[line + 1][col] == 1)
                return 1;
        }

        for(int line = max_line - 1; line >= 0; line--)
            for(int col = max_col - 1; col >= 0; col--)
        {
            if(Surface.surface[line][col] == 2
                    && Surface.surface[line + 1][col] == 0)
            {
                Surface.surface[line + 1][col] = 2;
                Surface.surface[line][col] = 0;

                ///colic
                Surface.colic[line + 1][col] = Surface.colic[line][col];
                Surface.colic[line][col] = 0;
                ////
            }
        }
    return 0;
}


void save_changes()
{
    for(int line = 0; line < max_line; line++)
        for(int col = 0; col < max_col; col++)
        {
            if(Surface.surface[line][col] == 2)
                Surface.surface[line][col] = 1;
        }
}
