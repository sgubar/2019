
#include <stdio.h>
#include "TLIntList.h"

int main(int argc, const char * argv[])
{
	IntList *theList = TLCreateIntList();
	if (NULL == theList)
	{
		return -1;
	}
	
	TLAddIntValueToList(theList, "vasia");
	TLAddIntValueToList(theList, "dima");
	TLAddIntValueToList(theList, "one");
	TLAddIntValueToList(theList, "to");
	TLAddIntValueToList(theList, "list");
	TLAddIntValueToList(theList, "const");
	TLAddIntValueToList(theList, "vitalii");
	TLAddIntValueToList(theList, "hunting");
	TLAddIntValueToList(theList, "news");
	TLAddIntValueToList(theList, "tools");
	TLAddIntValueToList(theList, "translation");
	

	TLPrintList(theList);

	
	TLDestroyIntList(theList);
	
	return 0;
}
