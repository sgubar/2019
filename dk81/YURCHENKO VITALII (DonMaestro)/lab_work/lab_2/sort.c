#include <header.h>


void bubble(int max_char, char masiv[max_char])
{
    for(int bulb = 0; bulb < max_char; bulb++)
        for(int i = 1; i < max_char - 1; i++)
        {
            char cell;

            if(masiv[i] < masiv[i-1])
            {
                cell = masiv[i-1];
                masiv[i-1] = masiv[i];
                masiv[i] = cell;
            }
        }
}


void insert(int max_char, char masiv[max_char])
{
    char cell;
    int locat;

    for(int i = 1; i < max_char - 1; i++)
    {
        cell = masiv[i];
        locat = i - 1;
        while(locat >= 0 && masiv[locat] > cell)
        {
            masiv[locat+1] = masiv[locat];
            locat = locat - 1;
        }
        masiv[locat+1] = cell;
    }
}


void selection(int max_char, char masiv[max_char])
{
    int min;

    for(int sorted = 0; sorted < max_char - 1; sorted++)
    {
        min = sorted;
        for(int now = sorted + 1; now < max_char - 1; now++)
            if(masiv[min] > masiv[now])
                min = now;
        char cell = masiv[sorted];
        masiv[sorted] = masiv[min];
        masiv[min] = cell;
    }

}

