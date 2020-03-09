﻿#pragma once
#include "stdlib.h" 
#include "string.h"
#include <iostream>
using namespace std;
/* Initializes list */
void StringListInit(char*** list);
void PrintString(char* str);
void PrintList(char** list);
/* Destroy list and set pointer to NULL. */
void StringListDestroy(char*** list);
/* Inserts value at the end of the list. */
void StringListAdd(char** list, char* str);
/* Removes all occurrences of str in the list. */
void StringListRemove(char** list, char* str);
/* Returns the number of items in the list. */
int StringListSize(char** list);
/* Returns the index position of the first occurrence of str in the list. */
int StringListIndexOf(char** list, char* str);
/* Removes duplicate entries from the list. */
void StringListRemoveDuplicates(char** list);
/* Replaces every occurrence of the before, in each of the string lists's strings, with after. */
void StringListReplaceInStrings(char** list, char* before, char* after);
/* Sorts the list of strings in ascending order */
char** StringListSort(char** list);
void Delete(char** list);
char** elementOnPosition(char** list, int i);
/*removes nodeRemove from the list*/
char** RemoveElement(char** prevNode, char** nodeRemove);
char** merge(char** a, char**b);

























