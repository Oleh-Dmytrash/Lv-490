#pragma once

#include <stdlib.h>
#include <string.h>

typedef char* String;

/* Initializes list */
void StringListInit(char*** list);
/* Destroy list and set pointer to NULL. */
void StringListDestroy(char*** list);

/* Inserts value at the end of the list. */
void StringListAdd(char** list, String str);
/* Removes all occurrences of str in the list. */
void StringListRemove(char** list, String str);

/* Returns the number of items in the list. */
int StringListSize(char** list);
/* Returns the index position of the first occurrence of str in the list. */
int StringListIndexOf(char** list, char* str);

/* Removes duplicate entries from the list. */
void StringListRemoveDuplicates(char** list);
/* Replaces every occurrence of the before, in each of the string lists's strings, with after. */
void StringListReplaceInStrings(char** list, char* before, char* after);
/* Sorts the list of strings in ascending order */
void StringListSort(char** list);


//read element in some position 'pos'
char** ReadElem(char*** list_head, int pos);
//swap strings in list elements
void swap(char** elem_1, char** elem_2);

////Create list and insert first element in list
//void CreateList(char*** head, char* str);
//
////Add element in last position
//void AddElem(char*** list_head, char* str);
//
////remove all element from list anf free memory
//void RemoveAllElem(char*** list_head);
//
////remove element in some position 'pos'
//void RemoveElem(char*** list_head, int pos);
//
////get size of list
//int ListSize(char*** list_head);
//
////get the index position of the first exact match of specified string
//int SearchFirst(char*** list_head, char* str);
//
////sorting list by selection sort
//void SortList(char*** list_head);