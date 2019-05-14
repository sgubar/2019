#include <stdio.h>
#include <stdlib.h>
#include "luna_lab3.h"

void ShellSort(char *mass, int Count)
{
  int theInner = 0;
  int theOuter = 0;
  int kek = 1;
  while (kek <= Count/3)
  {
    kek = kek*3 + 1;
  }
     while (kek > 0)
  {
    for (theOuter = kek; theOuter < Count; theOuter ++)
    {
      int temp = mass[theOuter];
      theInner = theOuter;
      while (theInner > kek-1 && mass[theInner - kek] >= temp)
      {
        mass[theInner] = mass[theInner - kek];
        theInner -= kek;
      }
      mass[theInner] = temp;
    }
    kek = (kek - 1) / 3;
  }
}

void WritetoFile(char *mass, int asize, char *fname)
{
  FILE *file;
  file= fopen(fname, "w");

  int i;
  for(i = 0; i < asize; i++)
  {
      fprintf(file, "%c", mass[i]);
  }
  fclose(file);
}

int lineSearch(char Value, char *mass, int asize)
{
    int i;
    int counter = 0;
    for(i = 0; i < asize; i ++)
    {
        counter++;
        if(mass[i] == Value)
        {
            return counter;
        }
    }
    return counter;
}

void randomizer(char *mass, int size)
{
    int i;
    for( i = 0; i < size; i++)
    {
        switch(rand() % 2)
        {
        case 0: mass[i] = rand() % 26 + 97; break;
        case 1: mass[i] = rand() % 10 + 48; break;
        }
    }
}
