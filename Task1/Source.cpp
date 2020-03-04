#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Header.h"


int main() {
	char** list;
	StringListInit(&list);
	char str111[] = "bbb";
	char str222[] = "aaa";
	char str333[] = "ddd";
	StringListAdd(list, str111);
	StringListAdd(list, str222);
	StringListAdd(list, str333);
	StringListAdd(list, str222);
	StringListAdd(list, str333);
	StringListRemove(list, str333);
	show(list);
	StringListRemoveDuplicates(list);
	int index = StringListSize(list);
	cout << index << endl;
	show(list);
	
	char str1[] = "bbb";
	char str2[] = "aaa";
	char str3[] = "ddd";
	char str4[] = "ccc";
	char str5[] = "str";
	StringListAdd(list, str1);
	StringListAdd(list, str2);
	StringListAdd(list, str3);
	show(list);
	cout << endl;
	StringListReplaceInStrings(list, str1, str2);

	show(list);
	StringListAdd(list, str1);
	StringListAdd(list, str2);
	StringListAdd(list, str3);
	cout << "List size=" << StringListSize(list) << endl;
	StringListAdd(list, str1);
	StringListAdd(list, str4);
	StringListAdd(list, str5);
	StringListAdd(list, str1);
	cout << "List size=" << StringListSize(list) << endl;

	char s[] = "12";
	show(list);
	
	int found = StringListIndexOf(list, s); // add if list is ampty return
	if (found) {
		cout << "Index of:" << s << "is=" << found << endl;
	}
	else {
		cout << "No such element in list" << endl;
	}

	char str7[] = "str6";
	StringListAdd(list, str7);
	StringListAdd(list, str2);
	StringListAdd(list, str7);
	show(list);
	cout << "here" << endl;
	StringListRemove(list, str2);
	cout << "List size=" << StringListSize(list) << endl;
	show(list);
	///system("pause");
	StringListAdd(list, str2);
	char str0[] = "00000";
	StringListReplaceInStrings(list,str2,str0);
	show(list);
	StringListSort(list);
	show(list);
	cout << "remove duplicates \n";
	StringListRemoveDuplicates(list);
	show(list);

	StringListDestroy(&list);
	system("pause");
	return 0;
}