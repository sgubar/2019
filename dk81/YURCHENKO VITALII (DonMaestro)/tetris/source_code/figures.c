#include "header.h"
#include "figures.h"


void figu_pri(int figure[8])
{
    for(int line = 0, col_f = 0; line < 2; line++)
        for(int col = 0; col < 4; col++, col_f++)
            Surface.surface[line][ col + max_col/3 ] = figure[col_f];
}

void add_figu()
{
    int figure_0[8] = {2, 0, 0, 0, 2, 2, 2, 0};
    int figure_1[8] = {0, 0, 2, 0, 2, 2, 2, 0};
    int figure_2[8] = {2, 2, 0, 0, 0, 2, 2, 0};
    int figure_3[8] = {0, 2, 2, 0, 2, 2, 0, 0};
    int figure_4[8] = {0, 2, 0, 0, 2, 2, 2, 0};
    int figure_5[8] = {0, 2, 2, 0, 0, 2, 2, 0};
    int figure_6[8] = {0, 0, 0, 0, 2, 2, 2, 2};

    srand(time(NULL));
    switch (rand()/(RAND_MAX / 7)) {
    case 0:
        figu_pri(figure_0);
        break;
    case 1:
        figu_pri(figure_1);
        break;
    case 2:
        figu_pri(figure_2);
        break;
    case 3:
        figu_pri(figure_3);
        break;
    case 4:
        figu_pri(figure_4);
        break;
    case 5:
        figu_pri(figure_5);
        break;
    case 6:
        figu_pri(figure_6);
        break;
    }
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


void wheeling_figu()
{

    search_left_ground();

    int max_col_m = Figu_coord.point_col_e - Figu_coord.point_col + 1;
    int max_line_m = Figu_coord.point_line_e - Figu_coord.point_line + 1;

    int massif[max_line_m][max_col_m];

    int left_shift = 0;


    if(audit_figu_rite() == 1 && max_col_m < max_line_m)
        left_shift = -1;

    //printf("\n%i   %i\n", max_line_m, max_col_m);
    //printf("\n%i   %i\n", Figu_coord.point_line, Figu_coord.point_col);
    //printf("\n%i   %i\n", Figu_coord.point_line_e, Figu_coord.point_col_e);
    for(int line = 0; line < max_line_m; line++)
        for(int col = 0; col < max_col_m; col++)
        {
            massif[line][col] = Surface.surface[line + Figu_coord.point_line][col + Figu_coord.point_col];
            Surface.surface[line + Figu_coord.point_line][col + Figu_coord.point_col] = 0;
            //printf("%i", massif[line][col]);
        }

    for(int line = 0, col_m  = 0; line < max_col_m; line++, col_m++)
        for(int col = 0, line_m = max_line_m - 1; col < max_line_m; col++, line_m--)
        {
            Surface.surface[line + Figu_coord.point_line]
                    [col + Figu_coord.point_col + left_shift] = massif[line_m][col_m];
        }

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
