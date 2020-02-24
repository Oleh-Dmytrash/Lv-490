#pragma once
#include <string.h>
#include <stdlib.h>

#include <stdio.h>

using StringList = char**;
using ListNode = char**;

/*
	Initialize a new list
*/
void StringListInit(StringList* list);

/*
	Dellocate the entire list and set head to nullptr
*/
void StringListDestroy(StringList* list);

/*
	Add a single element to a list
*/
void StringListAdd(StringList list, const char* str);

/*
	Deallocate and remove all the entries of the element in the list
*/
void StringListRemove(StringList list, const char* str);

/*
	Get count of elements in the list
*/
size_t StringListSize(const StringList list);

/*
	Get index of first entry of str in the list
*/
int StringListIndexOf(const StringList list, const char* str);

/*
	Get a list element(char*) by given index
*/
char* StringListGetItemByIndex(const StringList list, size_t index);

/*
	Swap 2 list elements
*/
void StringListSwapItems(const StringList list, size_t index1, size_t index2);

/*
	Remove all duplicated elements, leaving a list with unique values
*/
void StringListRemoveDuplicates(StringList list);

/*
	Replace all the entries of old_value with new_value
*/
void StringListReplaceInStrings(StringList list, const char* old_value, const char* new_value);

/*
	Sorts the list in accending order using QuickSort
*/
void StringListSort(StringList list);


//////////////////////////////////////////////////////////////
///////////////// Additional help functions //////////////////
//////////////////////////////////////////////////////////////

static void QuickSort(StringList list, int start, int end);

static ListNode StringListGetNodeByIndex(StringList list, size_t index);

static void StringListRemoveByIndex(StringList* list, size_t index);

static size_t StringListPartition(StringList list, int start_index, int end_index);

static char* AllocateDynamically(const char* statically_allocated_ptr);

static bool StringListHasSameElementBefore(StringList list, ListNode element);

void StringListPrint(const StringList list);
