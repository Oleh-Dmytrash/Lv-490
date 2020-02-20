#include "list.h"

/* Initializes list */
void StringListInit(char*** list)
{
	if (*list)
	{
		StringListDestroy(list);
	}
	char** list_head = (char**)malloc(2 * sizeof(char*));

	*list = list_head;//set pointer to head

	list_head[0] = NULL;
	list_head[1] = NULL;
}

/* Destroy list and set pointer to NULL. */
void StringListDestroy(char*** list)
{
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


/* Inserts value at the end of the list. */
void StringListAdd(char** list, String str)
{
	char** current_elem = list;
	char** new_elem = (char**)malloc(2 * sizeof(char*));//create new elem
	char* current_str = NULL;
	current_str = (char*)malloc((strlen(str) + 1) * sizeof(char));
	strcpy(current_str, str);
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
	char** current_elem = list;
	int size = StringListSize(list);

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
				free(current_elem);
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
		if (strcmp(current_elem[0], str)==0)
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
	while (current_elem[1] != NULL)
	{
		StringListRemove(current_elem, current_elem[0]);
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
			current_elem[0] = after;
		}

		current_elem = (char**)current_elem[1];//go to next elemnt
	}
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
	char** current_elem = *list_head;
	int elem_count = 0;
	while (1)//search element in pos
	{
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

void swap(char** elem_1, char** elem_2)
{
	char* temp_elem = elem_1[0];//remember ptr to string in first element
	elem_1[0] = elem_2[0];//reset ptr to string in first element
	elem_2[0] = temp_elem;//set ptr to string in second element to remembered ptr
}

//void CreateList(char*** head, char* str)//create list and insert head
//{
//	char** list_head = (char**)malloc(2 * sizeof(char*));
//
//	*head = list_head;//set pointer to head
//
//	char* current_str = NULL;
//	current_str = (char*)malloc(strlen(str) * sizeof(char));
//	strcpy(current_str, str);
//
//	list_head[0] = current_str;
//	list_head[1] = NULL;
//}
//
//
//void AddElem(char*** list_head, char* str)
//{
//	char** current_elem = *list_head;
//	char** new_elem = (char**)malloc(2 * sizeof(char*));//create new elem
//	while (1)//search last elem
//	{
//		if (current_elem[1] == NULL)
//		{
//			current_elem[1] = (char*)new_elem;//add new elem to list
//			break;
//		}
//		else
//		{
//			//char** next_ptr = (char**)current_elem[1];
//			current_elem = (char**)current_elem[1];//go to next elem
//		}
//	}
//
//	char* current_str = NULL;
//	current_str = (char*)malloc(strlen(str) * sizeof(char));
//	strcpy(current_str, str);
//	new_elem[0] = current_str;//add string to list
//	new_elem[1] = NULL;//set next elen as NULL
//}
//
//void RemoveAllElem(char*** list_head)
//{
//	char** current_elem = *list_head;
//	while (1)
//	{
//		char** next_elem = (char**)current_elem[1];//get next element
//
//		char* str_for_delete = current_elem[0];
//
//		//free(str_for_delete);
//		//current_elem[0] = NULL;
//		free(current_elem);//delete current element
//		current_elem = NULL;
//
//		current_elem = next_elem;//go to next element
//
//		if (next_elem == NULL)
//		{
//			free(next_elem);//delete last element
//			current_elem = NULL;
//			return;
//		}
//	}
//}
//
//void RemoveElem(char*** list_head, int pos)
//{
//	char** current_elem = *list_head;
//	int current_pos = 0;
//	while (1)
//	{
//		if (pos == 0)//delete first element and set head in second position
//		{
//			*list_head = (char**)current_elem[1];
//			free(current_elem);
//			current_elem = NULL;
//		}
//
//		char** previous_elem = current_elem;//remember previous element
//		current_elem = (char**)current_elem[1];//go to next element
//		char** next_elem = (char**)current_elem[1];//remember next element
//
//		++current_pos;
//
//		if (current_pos == pos)//delete element in position 'pos'
//		{
//			free(current_elem);
//			current_elem = NULL;
//			previous_elem[1] = (char*)next_elem;
//			return;
//		}
//
//		if (next_elem == NULL)
//		{
//			return;
//		}
//	}
//}
//
//int ListSize(char*** list_head)
//{
//	char** current_elem = *list_head;
//	int count = 0;//number of elements
//	while (1)
//	{
//		if (current_elem == NULL)//return elemnt's number when
//		{
//			return count;
//		}
//		else
//		{
//			++count;
//		}
//		
//		current_elem = (char**)current_elem[1];//go to next element
//	}
//	return count;
//}
//
//int SearchFirst(char*** list_head, char* str)
//{
//	char** current_elem = *list_head;
//	int pos = 0;
//	if (str == NULL || current_elem == NULL)
//	{
//		return -1;
//	}
//	while (current_elem != NULL)
//	{
//		if (strlen(*current_elem) == strlen(str))
//		{
//			for (int i = 0; i < strlen(*current_elem); i++)
//			{
//				if ((*current_elem)[i] != str[i])
//				{
//					break;
//				}
//				if (i == strlen(str) - 1)
//				{
//					return pos;
//				}
//			}
//		}
//		else
//		{
//			++pos;
//		}
//		
//		current_elem = (char**)current_elem[1];//go to next elemnt
//	}
//	return pos;
//}
//
//void swap(char** elem_1, char** elem_2)
//{
//	char* temp_elem = elem_1[0];//remember ptr to string in first element
//	elem_1[0] = elem_2[0];//reset ptr to string in first element
//	elem_2[0] = temp_elem;//set ptr to string in second element to remembered ptr
//}
//
//void SortList(char*** list_head)
//{
//	char** current_elem = *list_head;
//	int size = ListSize(list_head);
//
//	char** min_str = NULL;
//	char** current_elem_for_compare = NULL;
//
//	for (int i = 0; i < size; ++i)//locking for min string compare by strcmp
//	{
//		min_str = current_elem;
//		current_elem_for_compare = current_elem;
//
//		while (current_elem_for_compare != NULL)
//		{
//			if (strcmp(min_str[0], current_elem_for_compare[0]) > 0)//compare strings
//			{
//				min_str = current_elem_for_compare;//set new min string
//			}
//			
//			current_elem_for_compare = (char**)current_elem_for_compare[1];
//		}
//		
//		swap(current_elem, min_str);//swap strings in list elements
//		current_elem = (char**)current_elem[1];//go to next elemnt
//	}
//}