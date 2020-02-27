#include "list.h"
#include <iostream>
int main()
{
	StringList list;
	StringListInit(&list);
	StringListAdd(list, "a");
	StringListAdd(list, "b");
	StringListAdd(list, "c");
	StringListAdd(list, "d");
	StringListAdd(list, "e");

	StringListRemoveDuplicates(list);

	
	StringListPrint(list);
	std::cout << StringListSize(list);
	
	std::cin.get();
}
