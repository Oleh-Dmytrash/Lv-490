#include "List.h"
#include "stdlib.h"
#include "string.h"
#include <iostream>
using namespace std;

/* Initializes list */
void StringListInit(char*** list)
{
	*list = (char **)malloc(2 * sizeof(char *));
	if (!*list) return;
	/*(*list)[0] = (char *)malloc(1 * sizeof(char));
	(*list)[1] = (char *)malloc(1 * sizeof(char));*/
	(*list)[0] = NULL;
	(*list)[1] = NULL;	
}
void PrintList(char** list)
{
	if (list == NULL)
	{
		cout<< "empty\n";
		return;
	}
	char* h = list[1];
	cout << "list: ";
	while (reinterpret_cast<char**>(list[1])) {
		list = reinterpret_cast<char**>(list[1]);
		cout<<list[0]<<" ";
	}
}
/* Destroy list and set pointer to NULL.*/
void StringListDestroy(char*** list)
{
	if (*list == NULL)
		return;
	char** curN = *list;
	char**prevN = NULL;
	while (reinterpret_cast<char**>(curN[1]) != NULL) {
		char** temp = curN;
		curN = reinterpret_cast<char**>(curN[1]);
		Delete(prevN);
		prevN = curN;
	}
	*list = NULL;
}

/* Inserts value at the end of the list. */
void StringListAdd(char** list, char* str)
{
	while (reinterpret_cast<char**>(list[1])!=NULL) {
		list = reinterpret_cast<char**>(list[1]);
	} 
	char** r = (char **)malloc(2 * sizeof(char *));
	r[0] = _strdup(str);
	r[1] = NULL;
	list[1] = reinterpret_cast<char*>(r);
}

/* Removes all occurrences of str in the list. */
void StringListRemove(char** list, char* str)
{
	if (list == NULL)
		return;
	char ** curNode = list;
	char**prevNode = NULL;
	while (curNode!=NULL)//&&reinterpret_cast<char**>(curNode[1]))
	{
		if (curNode[0]!=NULL && strcmp(str, curNode[0]) == 0)
		{

			curNode = RemoveElement(prevNode, curNode);
		}
		prevNode = curNode;
		if (reinterpret_cast<char**>(curNode[1]))
		curNode = reinterpret_cast<char**>(curNode[1]);
		else curNode = NULL;
	}
}

/* Returns the number of items in the list. */
int StringListSize(char** list) {
	if (list == NULL || list[0] == NULL && list[1] == NULL)
		return 0;
	int i = 0;
	while (reinterpret_cast<char**>(list[1])) 
	{
		list = reinterpret_cast<char**>(list[1]);
		++i;
	}
	return i+1;
}
/* Returns the index position of the first occurrence of str in the list. */
int StringListIndexOf(char** list, char* str)
{
	int i = 0;
	while (reinterpret_cast<char**>(list[1])) {
		list = reinterpret_cast<char**>(list[1]);
		if (list[0] == str)
			return i;
		++i;
	}
	return -1;
}

/* Removes duplicate entries from the list. */
void StringListRemoveDuplicates(char** list) 
{
	
}
void Delete(char** list)
{
	if (list == NULL)
		return;
	free(list);
	list = NULL;
}
/*removes nodeRemove from the list*/
char** RemoveElement(char** prevNode, char** nodeRemove)
{
	char** res;
	if (!nodeRemove)
		return prevNode;
	else
	{
		if (reinterpret_cast<char**>(nodeRemove[1]))
			res = reinterpret_cast<char**>(nodeRemove[1]);
		else res = NULL;
		if (prevNode)
		prevNode[1] = nodeRemove[1];
		

		Delete(nodeRemove);
	};
	return prevNode;
}
/* Replaces every occurrence of the before, in each of the string lists's strings, with after. */
void StringListReplaceInStrings(char** list, char* before, char* after)
{

	if (list == NULL)
		return;
	char ** curNode = list;
	char**prevNode = NULL;
	while (curNode != NULL)//&&reinterpret_cast<char**>(curNode[1]))
	{
		if (curNode[0] != NULL && strcmp(before, curNode[0]) == 0)
		{

			curNode[0] = after;
		}
		prevNode = curNode;
		if (reinterpret_cast<char**>(curNode[1]))
			curNode = reinterpret_cast<char**>(curNode[1]);
		else curNode = NULL;
	}
	cout << 1;
}
/* Sorts the list of strings in ascending order */
char** StringListSort(char** list) 
{
	if (list == NULL || !reinterpret_cast<char**>(list[1]))
		return NULL;
	int num = StringListSize(list)/2;
	cout << num << endl;
	if (num == 0)
		return NULL;
	if (num == 1 )
		return list;
	char** b  = elementOnPosition(list, num);
	char** d = NULL;
	if (reinterpret_cast<char**>(b[1]))
	{
		d = reinterpret_cast<char**>(b[1]);
	}
	b[1] = NULL;
	char** k = StringListSort(list);
	PrintList(k);
	cout << endl;
	char** r = StringListSort(d);
	
	PrintList(r);
	cout << "\nbefore merging" << endl;
	PrintList(r);
	cout << "\nk = \n";
	PrintList(k);
	char ** res = merge(k, r);
	cout << "\nafter merging" << endl;
	PrintList(res);
	cout << "\nkeke" << endl;
	return res;
}
char** merge(char** a, char**b) 
{

	if (a ==NULL|| reinterpret_cast<char**>(a[0]) == NULL)
		return b;
	if (b == NULL ||reinterpret_cast<char**>(b[0]) == NULL)
		return a;
	char** new_list = NULL;
	StringListInit(&new_list);
	
	while (reinterpret_cast<char**>(b[0]) && reinterpret_cast<char**>(a[0])&&reinterpret_cast<char**>(a[1])&&reinterpret_cast<char**>(b[1]))
	{
		if (strcmp(a[0], b[0]) >= 0) 
		{
			StringListAdd(new_list, a[0]);
			a = reinterpret_cast<char**>(a[1]);
		}
		else
		{
			StringListAdd(new_list, b[0]);
			b = reinterpret_cast<char**>(b[1]);
		}
		
	}
	
	StringListDestroy(&a);
	StringListDestroy(&b);
	return new_list;
}
char** elementOnPosition(char** list, int i) 
{
	int j = 0;
	while (reinterpret_cast<char**>(list[1])&&j!=i) {
		list = reinterpret_cast<char**>(list[1]);
		++j;
	}
	return list;
}
