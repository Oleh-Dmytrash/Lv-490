#include"list.h"
#pragma warning(disable:4996)

int main()
{	
	
	//------
	char*** list=(char***)malloc(sizeof(char*));
	StringListInit(list);

	const char str[]={ "AslkjgSHl" };
	
	StringListAdd(*list, str);
	StringListAdd(*list, str+1);
	StringListAdd(*list, str+3);
	StringListAdd(*list, str+2);
	StringListAdd(*list, str+2);
	StringListAdd(*list, str+5);

	cout << "Size of list: " << StringListSize(*list) << endl;

	cout << "First position for " << str + 2 << " : " << StringListIndexOf(*list, str + 2)  << endl;

	cout << "Before sorting: " << endl;

	show_list(*list);
	
	StringListSort(*list);

	cout<<"After sorting: "<<endl;

	show_list(*list);

	cout << "Remove " << str + 1 << endl;
	StringListRemove(*list, str + 1);
	cout << "Remove " << str + 5 << endl << endl;
	StringListRemove(*list, str + 5);

	cout << "Show List: " << endl;
	show_list(*list);

	cout << "Remove dublicates:" << endl << endl;

	StringListRemoveDuplicates(*list);
	cout << "Show List: " << endl;
	show_list(*list);
	cout << endl;

	cout << "Add 2 more nodes with "<<str+3<<" data";
	StringListAdd(*list, str + 3);
	StringListAdd(*list, str + 3);
	cout << "Show List: " << endl;
	show_list(*list);
	cout << endl;

	
	cout << "Replaces every occurrence of the " << str + 3 << " in each of the string  " << str + 2 << endl;
	StringListReplaceInStrings(*list, str + 3, str + 2);
	cout << "Show List: " << endl;
	show_list(*list);
	cout << endl;	
	
	cout << "Destroying" << endl;
	StringListDestroy(list);	

	//----
	return 0;
}







