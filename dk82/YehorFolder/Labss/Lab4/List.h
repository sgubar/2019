#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct __tagDoubleNode DoubleNode;

struct __tagDoubleNode
{
	double value;
	DoubleNode *prev;
	DoubleNode *next;
};

typedef struct __tagDoubleList
{
	DoubleNode *head;
	DoubleNode *tail;
	int counter;
}DoubleList;


DoubleList *CreateDoubleList();
void DestroyDoubleList(DoubleList *aList);


double AddDoubleValueToList(DoubleList *aList, double value);

void SwapNodesByIndex(DoubleList *aList, int aLeftIndex, int aRightIndex);


int  InsertDoubleValueAtIndex(DoubleList *aList, double value, int anIndex);


double DoubleValueAtIndex(DoubleList *aList, int anIndex);

// print list
void PrintList(DoubleList *aList);

int CountList(DoubleList* aList);

DoubleNode *NodeAtIndex( DoubleList *aList, int anIndex);

DoubleNode *createDoubleNodeWithValue(double value);

int partitionIt(DoubleList *aList, int aLeftIndex, int aRightIndex, double aPivot);

DoubleNode *RemoveNodeAtIndex(DoubleList *aList, int anIndex);

void quickSort(DoubleList *aList, int aLeftIndex, int aRightIndex);

void DeleteSameNodes(DoubleList* aList);
#endif // LIST_H_INCLUDED
