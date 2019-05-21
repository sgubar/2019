#include <stdio.h>
#include <stdlib.h>
#include "theNode.h"
#include "theList.h"
#define NODE_NUMBER 5

    int main()
{
	IntList *thelist = CreateList();
	int value;
	int i;
	printf("\n\nAdd elements :\n\n");
			for(i = 0; i < NODE_NUMBER; i++)
		 	{
               printf("Node [ %d ] - ", i);
			   scanf("%d", &value);
               IntNode *theNode = CreateNode(value);
               AddNode(thelist, theNode);
			}
		doPrintList(thelist);
		printf("\n\n");
		while(FindtheSameNodeIndex(thelist)!= -1)
        {
		    FreeNode(RemovedNodeAtIndex(thelist, FindtheSameNodeIndex(thelist)));
        }
		doPrintList(thelist);

		return 0;
}
