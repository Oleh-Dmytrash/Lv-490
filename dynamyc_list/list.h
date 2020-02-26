#pragma once

#include <stdlib.h>
#include <string.h>

typedef char* String;

/* Destroy list and set pointer to NULL. */
void StringListDestroy(char*** list)
{
	if (*list == NULL)
	{
		return;
	}
	char** current_elem = *list;
	while (current_elem != NULL)
	{
		char** next_elem = (char**)current_elem[1];//get next element

		free(current_elem[0]);//delete string in current_element
		current_elem[0] = NULL;
		free(current_elem);//delete current element
		current_elem = NULL;

		current_elem = next_elem;//go to next element
	}
	*list = NULL;
}


/* Initializes list */
void StringListInit(char*** list)
{
	if (*list)
	{
		StringListDestroy(list);
	}
	char** list_head = (char**)malloc(2 * sizeof(char*));

	if (list_head == NULL)
	{
		return;
	}

	*list = list_head;//set pointer to head

	list_head[0] = NULL;
	list_head[1] = NULL;
}


/* Inserts value at the end of the list. */
void StringListAdd(char** list, String str)
{
	char** current_elem = list;
	char** new_elem = (char**)malloc(2 * sizeof(char*));//create new elem
	char* current_str = NULL;
	current_str = (char*)malloc((strlen(str) + 1) * sizeof(char));

	if (!current_elem || !new_elem)
	{
		return;
	}

	if (strlen(current_str) > strlen(str) && current_str)
	{
		strcpy(current_str, str);
	}
	new_elem[0] = current_str;//add string to list
	new_elem[1] = NULL;//set next elen as NULL

	while (current_elem[1] != NULL)//search last elem
	{
		current_elem = (char**)current_elem[1];//go to next elem
	}

	if (current_elem[0] == NULL)
	{
		current_elem[0] = new_elem[0];//add new elem to list
	}
	else
	{
		current_elem[1] = (char*)new_elem;//add new elem to list
	}
}

/* Removes all occurrences of str in the list. */
void StringListRemove(char** list, String str)
{
	if (list == NULL) return;
	if (*list == NULL) return;

	char** current_elem = list;
	char** previous_elem = NULL;

	while (current_elem != NULL)//locking for and remove the elements with the same strings 'str'
	{
		if (current_elem == list && strcmp(current_elem[0], str) == 0)
		{
			char** next_elem = (char**)current_elem[1];
			free(list[0]);
			if (next_elem)
			{
				list[0] = next_elem[0];
				list[1] = next_elem[1];
				free(next_elem);
			}
			else
			{
				list[0] = NULL;
				current_elem = NULL;
			}			
		}
		else
		{
			previous_elem = current_elem;
			current_elem = (char**)current_elem[1];
			if (current_elem == NULL) return;
			if (strcmp(current_elem[0], str) == 0)//count elements with same strings 'str'
			{
				previous_elem[1] = current_elem[1];
				free(current_elem[0]);//delete string
				current_elem[0] = NULL;
				free(current_elem);//delete element
				current_elem = previous_elem;
			}
		}
	}
}

void StringListRemoveElemDublicates(char** list, String str)
{
	char** current_elem = list;

	int count_of_elem_with_str = 0;

	if (strcmp(current_elem[0], str) == 0)
	{
		++count_of_elem_with_str;
	}

	char** previous_elem = current_elem;
	current_elem = (char**)current_elem[1];

	while (current_elem != NULL)//locking for and remove the elements with the same strings 'str'
	{
		if (strcmp(current_elem[0], str) == 0)//count elements with same strings 'str'
		{
			if (count_of_elem_with_str)
			{
				previous_elem[1] = current_elem[1];
				free(current_elem[0]);//delete string
				current_elem[0] = NULL;
				free(current_elem);//delete element
				current_elem = (char**)previous_elem[1];
			}
			++count_of_elem_with_str;
		}
		else
		{
			previous_elem = current_elem;
			current_elem = (char**)current_elem[1];//go to next element
		}
	}
}


/* Returns the number of items in the list. */
int StringListSize(char** list)
{
	if (list == NULL) return 0;
	if (*list == NULL) return 0;
	char** current_elem = list;
	int count = 0;//number of elements
	while (current_elem != NULL)
	{
		++count;

		current_elem = (char**)current_elem[1];//go to next element
	}
	return count;
}

/* Returns the index position of the first occurrence of str in the list. */
int StringListIndexOf(char** list, char* str)
{
	char** current_elem = list;
	int pos = 0;
	if (str == NULL || current_elem == NULL)
	{
		return -1;
	}
	while (current_elem != NULL)
	{
		if (strcmp(current_elem[0], str) == 0)
		{
			return pos;
		}
		else
		{
			++pos;
		}

		current_elem = (char**)current_elem[1];//go to next elemnt
	}
	return -1;
}


/* Removes duplicate entries from the list. */
void StringListRemoveDuplicates(char** list)
{
	char** current_elem = list;
	while (current_elem != NULL)
	{
		StringListRemoveElemDublicates(current_elem, current_elem[0]);
		current_elem = (char**)current_elem[1];
	}
}

/* Replaces every occurrence of the before, in each of the string lists's strings, with after. */
void StringListReplaceInStrings(char** list, char* before, char* after)
{
	char** current_elem = list;
	if (after == NULL || current_elem == NULL)
	{
		return;
	}
	while (current_elem != NULL)
	{
		if (strcmp(current_elem[0], before) == 0)
		{
			char* str = (char*)malloc((strlen(after) + 1) * sizeof(char));
			if (!str)
			{
				return;
			}

			if (strlen(str) > strlen(after))
			{
				strcpy(str, after);
			}
			current_elem[0] = str;
		}

		current_elem = (char**)current_elem[1];//go to next elemnt
	}
}

void swap(char** elem_1, char** elem_2)
{
	char* temp_elem = elem_1[0];//remember ptr to string in first element
	elem_1[0] = elem_2[0];//reset ptr to string in first element
	elem_2[0] = temp_elem;//set ptr to string in second element to remembered ptr
}

/* Sorts the list of strings in ascending order */
void StringListSort(char** list)
{
	char** current_elem = list;
	int size = StringListSize(list);

	char** min_str = NULL;
	char** current_elem_for_compare = NULL;

	for (int i = 0; i < size; ++i)//locking for min string compare by strcmp
	{
		min_str = current_elem;
		current_elem_for_compare = current_elem;

		while (current_elem_for_compare != NULL)
		{
			if (strcmp(min_str[0], current_elem_for_compare[0]) > 0)//compare strings
			{
				min_str = current_elem_for_compare;//set new min string
			}

			current_elem_for_compare = (char**)current_elem_for_compare[1];
		}

		swap(current_elem, min_str);//swap strings in list elements
		current_elem = (char**)current_elem[1];//go to next elemnt
	}
}


char** ReadElem(char*** list_head, int pos)
{
	if (*list_head == NULL) return NULL;
	char** current_elem = *list_head;
	int elem_count = 0;
	while (current_elem != NULL)//search element in pos
	{
		if (*current_elem == NULL) return NULL;
		if (elem_count == pos)
		{
			return current_elem;
		}

		current_elem = (char**)current_elem[1];//go to next element

		if (current_elem == NULL)
		{
			return NULL;
		}

		++elem_count;
	}
	return NULL;
}


///* Initializes list */
//void StringListInit(char*** list);
///* Destroy list and set pointer to NULL. */
//void StringListDestroy(char*** list);
//
///* Inserts value at the end of the list. */
//void StringListAdd(char** list, String str);
///* Removes all occurrences of str in the list. */
//void StringListRemove(char** list, String str);
//
///* Returns the number of items in the list. */
//int StringListSize(char** list);
///* Returns the index position of the first occurrence of str in the list. */
//int StringListIndexOf(char** list, char* str);
//
///* Removes duplicate entries from the list. */
//void StringListRemoveDuplicates(char** list);
///* Replaces every occurrence of the before, in each of the string lists's strings, with after. */
//void StringListReplaceInStrings(char** list, char* before, char* after);
///* Sorts the list of strings in ascending order */
//void StringListSort(char** list);
//
//
////read element in some position 'pos'
//char** ReadElem(char*** list_head, int pos);
////swap strings in list elements
//void swap(char** elem_1, char** elem_2);

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