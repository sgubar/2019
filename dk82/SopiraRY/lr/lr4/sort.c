#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

	//help function
int partition(List *aList, int start, int end)
{
    int pivot = nodeAtIndex(aList, end)->value; 
    
    //int temp_i; 
    int i = (start - 1);

    for (int j = start; j <= (end - 1); j++)
    {
        if ( (nodeAtIndex(aList, j)->value) <= pivot)	//<= up, >= down
        {
            i++;
            
            swapNodes(aList, i, j);
            /*
            temp_i = nodeAtIndex(aList, i)->value;
			nodeAtIndex(aList, i)->value = nodeAtIndex(aList, j)->value;
			nodeAtIndex(aList, j)->value = temp_i;*/
        }
    }
    
    swapNodes(aList, i + 1, end);
    /*
    temp_i = nodeAtIndex(aList, i + 1)->value;
	nodeAtIndex(aList, i + 1)->value = nodeAtIndex(aList, end)->value;
	nodeAtIndex(aList, end)->value = temp_i;*/
	
    return (i + 1);
}

//quick sort
	//sort
void quickSort(List *aList, int start, int end)
{
	if (start < end)
	{
		int pivot = partition(aList, start, end);
		
		quickSort(aList, start, pivot - 1);
		quickSort(aList, pivot + 1, end);
	}
}
