#include"list.h"
#pragma warning(disable:4996)

int main()
{	
	char*** list=(char***)malloc(sizeof(char*));
	StringListInit(list);
	
	StringListAdd(*list, "hi5");
	StringListAdd(*list, "hi4");
	StringListAdd(*list, "hi3");
	StringListAdd(*list, "hi2");
	StringListAdd(*list, "hi");
	StringListSort(*list);
	show_list(*list);
	StringListDestroy(list);
	return 0;
}







