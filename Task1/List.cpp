#include "List.h"
#include "stdlib.h"
#include "string.h"
#include <iostream>
using namespace std;

/* Initializes list */
void StringListInit(char*** list)
{
	//деструктор 
	*list = (char **)malloc(2 * sizeof(char *));
	(*list)[0] = (char *)malloc(1 * sizeof(char));
	(*list)[1] = (char *)malloc(1 * sizeof(char));
	(*list)[0] = NULL;
	(*list)[1] = NULL;
	return;
}
void PrintString(char* str)
{
	cout << str;
	for (int i = 0; i < int(strlen(str)); ++i)
	{
		cout << str[i];
	}
	cout << endl;
}
void PrintList(char** list)
{
	if (list == NULL)
	{
		cout << "List is empty";
		return;
	}
	char* h = list[1];
	while (reinterpret_cast<char**>(list[1])) {
		list = reinterpret_cast<char**>(list[1]);
		PrintString((list)[0]);
	}
}
/* Destroy list and set pointer to NULL. */
void StringListDestroy(char*** list)
{
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
	int length = strlen(str);
	while (reinterpret_cast<char**>(list[1])!=NULL) {
		list = reinterpret_cast<char**>(list[1]);
	} 
	char** r = (char **)malloc(2 * sizeof(char *));
	r[0] = (char *)malloc(length * sizeof(char));
	r[1] = (char *)malloc(1 * sizeof(char));
	r[0] = str;
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
	cout << 1;
}

/* Returns the number of items in the list. */
int StringListSize(char** list) {
	int i = 0;
	while (reinterpret_cast<char**>(list[1])) 
	{
		list = reinterpret_cast<char**>(list[1]);
		++i;
	}
	return i;
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
	//free(list[0]);
	//free(list[1]);
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

		delete(nodeRemove);
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
void StringListSort(char** list);
