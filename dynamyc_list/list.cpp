#include "list.h"

void CreateList(char*** head, char* str)//create list and insert head
{
	char** list_head = (char**)malloc(2 * sizeof(char*));

	*head = list_head;//set pointer to head

	char* current_str = NULL;
	current_str = (char*)malloc(strlen(str) * sizeof(char));
	strcpy(current_str, str);
	
	list_head[0] = current_str;
	list_head[1] = NULL;
}

void AddElem(char*** list_head, char* str)
{
	char** current_elem = *list_head;
	char** new_elem = (char**)malloc(2 * sizeof(char*));//create new elem
	while (1)//search last elem
	{		
		if (current_elem[1] == NULL)
		{		
			current_elem[1] = (char*)new_elem;//add new elem to list
			break;
		}
		else
		{
			//char** next_ptr = (char**)current_elem[1];
			current_elem = (char**)current_elem[1];//go to next elem
		}
	}
	
	char* current_str = NULL;
	current_str = (char*)malloc(strlen(str) * sizeof(char));
	strcpy(current_str, str);
	new_elem[0] = current_str;//add string to list
	new_elem[1] = NULL;//set next elen as NULL
}

char* ReadElem(char*** list_head, int pos)
{
	char** current_elem = *list_head;
	int elem_count = 0;
	while (1)//search element in pos
	{
		if (elem_count == pos)
		{
			return *current_elem;
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


void RemoveAllElem(char*** list_head)
{
	char** current_elem = *list_head;
	while (1)
	{
		char** next_elem = (char**)current_elem[1];//get next element
				
		free(current_elem);//delete current element
		current_elem = NULL;

		current_elem = next_elem;//go to next element

		if (next_elem == NULL)
		{
			free(next_elem);//delete last element
			current_elem = NULL;
			return;
		}
	}
}

void RemoveElem(char*** list_head, int pos)
{
	char** current_elem = *list_head;
	int current_pos = 0;
	while (1)
	{
		if (pos == 0)
		{
			*list_head = (char**)current_elem[1];
			free(current_elem);
			current_elem = NULL;
		}

		//char** next_elem = (char**)current_elem[1];//get next element
		char** previous_elem = current_elem;//remember previous element
		current_elem = (char**)current_elem[1];//go to next element
		char** next_elem = (char**)current_elem[1];//remember next element
		
		++current_pos;

		if (current_pos == pos)//delete element in position 'pos'
		{				
			free(current_elem);
			current_elem = NULL;
			previous_elem[1] = (char*)next_elem;
			return;
		}
		
		if (next_elem == NULL)
		{
			return;
		}		
	}
}

int ListSize(char*** list_head)
{
	char** current_elem = *list_head;
	int count = 0;//number of elements
	while (1)
	{
		if (current_elem == NULL)//return elemnt's number when
		{			
			return count;
		}
		else
		{
			++count;
		}

		//char** next_elem = (char**)current_elem[1];//get next element
		current_elem = (char**)current_elem[1];//go to next element
	}
	return count;
}

int SearchFirst(char*** list_head, char* str)
{
	char** current_elem = *list_head;
	int pos = 0;
	if (str == NULL || current_elem == NULL)
	{
		return -1;
	}
	while (1)
	{
		if (strlen(*current_elem) == strlen(str))
		{
			for (int i = 0; i < strlen(*current_elem); i++)
			{
				if ((*current_elem)[i] != str[i])
				{
					break;
				}
				if (i == strlen(str) - 1)
				{
					return pos;
				}
			}
		}
		else
		{
			++pos;
		}

		//char** next_elem = (char**)current_elem[1];//get next element
		current_elem = (char**)current_elem[1];//go to next elemnt
	}
	return pos;
}

void swap(char** elem_1, char** elem_2)
{
	char* temp_elem = elem_1[0];
	elem_1[0] = elem_2[0];
	elem_2[0] = temp_elem;
}

void SortList(char*** list_head)
{
	char** current_elem = *list_head;
	int size = ListSize(list_head);

	char** min_str = NULL;
	char** current_elem_for_compare = NULL;

	for (int i = 0; i < size; ++i)
	{
		min_str = current_elem;
		current_elem_for_compare = current_elem;

		while (current_elem_for_compare != NULL)
		{
			if (strcmp(min_str[0], current_elem_for_compare[0]) > 0)
			{
				min_str = current_elem_for_compare;
			}

			//char** next_elem_for_compare = (char**)current_elem_for_compare[1];
			current_elem_for_compare = (char**)current_elem_for_compare[1];
		}

		//char** next_elem = (char**)current_elem[1];//get next element
		swap(current_elem, min_str);
		current_elem = (char**)current_elem[1];//go to next elemnt
	}
}