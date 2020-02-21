#include "list.h"
int main()
{
	StringList list;
	StringListInit(&list);
	StringListAdd(list, "hello");
	StringListAdd(list, "hi");
	StringListAdd(list, "hey");
	StringListAdd(list, "bonjour");
	StringListAdd(list, "hello");

	StringListPrint(list);
	StringListReplaceInStrings(list, "hi", "Welcome");
	StringListPrint(list);
	StringListRemoveDuplicates(&list);
	StringListPrint(list);
	StringListSort(list);
	StringListPrint(list);
	StringListDestroy(&list);

	
}
