#pragma warning(disable:4996)
#include <stdlib.h>
#include <string.h>
#include<iostream>//printf,cout
using namespace std;

void StringListInit(char*** list);

void StringListDestroy(char*** head);

void StringListAdd(char** node, const char* str);

void StringListRemove(char** head, const char* str);

int StringListSize(char** list);

int StringListIndexOf(char** list, const char* str);

void StringListRemoveDuplicates(char** list);

void StringListReplaceInStrings(char** list,const char* before,const char* after);

void StringListSort(char** list);

void swap_str(char** first, char** second);//swap strings

void show_list(char** list);//show list's data

//////////////////////////////////////////////////////

void StringListInit(char*** list)
{
	if (list == NULL)
		return;

	*list = (char**)malloc(sizeof(char*) * 2);
	if (*list == NULL)
		return;
	list[0][0] = NULL;
	list[0][1] = NULL;
	return;
}

void StringListDestroy(char*** head)
{
	if (head!=NULL)
	{
		if (*head != NULL)//to avoid access violation
		{
			while ((*head)[1] != NULL)
			{
				char** current = *head;
				char** previous = current;
				while (current[1] != NULL)
				{
					previous = current;
					current = (char**)current[1];
				}
				if (previous != current)
				{
					previous[1] = NULL;
					free(current[0]);
					free(current);
				}
				else//when only head was left
				{
					free(current[0]);
					free(current);
					current[1] = NULL;
					current[0] = NULL;
				}
			}
			free(head[0][0]);
			free(head[0]);
			free(head);
		}
	}
	return;
}

void StringListAdd(char** node, const char* str)
{
	if (!node)
		return;
	if (!str)
		return;

	char*dyn_str = (char*)malloc(sizeof(char)*(strlen(str) + 1));//make input string dynamicly allocated for future free()
	
	if (!dyn_str)
		return;
	strcpy(dyn_str, str);
	dyn_str[strlen(str)] = '\0';

	if (node[0] == NULL)//null data can be only in first node
	{
		node[0] = dyn_str;
		return;
	}

	while (node[1] != NULL)
		node = (char**)node[1];//to tail

	char** added_node = (char**)malloc(sizeof(char*) * 2);
	if (!added_node)
	{
		free(dyn_str);//avoid memory leak and return
		return;
	}
	added_node[0] = dyn_str;
	added_node[1] = NULL;
	node[1] = (char*)added_node;

	return;
}

void StringListRemove(char** head, const char* str)
{
	if (!head)
		return;
	if (!str)
		return;
	char**current = head;
	char**prev = current;

	while (current)
	{
		if (strcmp(str, current[0]) == 0)//equal data
		{
			if (current == prev)//if first
			{
				if (current[1] == NULL)//if one node
				{
					free(current[0]);
					current[0] = NULL;
					break;
				}
				//more then one node
				char**temp_next = (char**)current[1];
				free(current[0]);//remove data from head
				current[0] = temp_next[0];//change data from next node to head
				current[1] = temp_next[1];//change ptr to next->next node
				free(temp_next);
				continue;
			}

			if (current[1] == NULL)//if it's last node
			{
				free(current[0]);
				free(current);
				prev[1] = NULL;
				break;
			}
			else//not last
			{
				prev[1] = current[1];
				free(current[0]);
				free(current);
				current = prev;
			}
		}
		else//not equal data
		{
			if (current[1] != NULL)
			{
				prev = current;
				current = (char**)current[1];
			}
			else break;
		}
	}
	return;
}

int StringListSize(char** list)
{
	if (!list)
		return -1;
	if (list[0] == NULL)//it means there is only one node exist and it's empty, so return 0;
		return 0;
	int counter = 0;
	while (list != NULL)
	{
		++counter;
		list = (char**)list[1];
	}
	return counter;
}

int StringListIndexOf(char** list, const char* str)
{
	if (str == NULL || list == NULL)
		return -1;

	int index = 0;
	while (strcmp(list[0], str) != 0)
	{
		list = (char**)list[1];
		++index;
	}
	return index;
}

void StringListRemoveDuplicates(char** list)
{
	if (list == NULL || list[1]==NULL)//at least 2 nodes
		return;

	StringListSort(list);//to simplify this function I'll sort it before removing

	char** current = list;
	char** next = (char**)current[1];

	while ( next!=NULL)
	{		
		if (strcmp(current[0], next[0]) == 0)
		{	
			if (next[1] == NULL)//when last and penultimate nodes
			{
				current[1] = NULL;
				free(next[0]);
				free(next);
				break;
			}
			else
			{
				current[1] = next[1];
				free(next[0]);
				free(next);
				next = (char**)current[1];
			}
		}
		else
		{			
			current = (char**)current[1];
			next = (char**)current[1];
		}
	}
	return;
}

void StringListReplaceInStrings(char** list,const char* before,const char* after)
{
	if (list[0]==NULL)//at least 1 node with data
		return;
	if (!before || !after)//strings should be not null
		return;

	char** current = list;
	int new_size = strlen(after);

	while (current != NULL)
	{
		if (strcmp(current[0], before) == 0)
		{
			current[0] = (char*)realloc(current[0], new_size * sizeof(char) + 1);//just change data
			strcpy(current[0], after);
		}

		current = (char**)current[1];
	}
	return;
}

void StringListSort(char** list)
{
	if (list == NULL || list[1] == NULL)//at least 2 nodes
		return;

	int size = StringListSize(list);
	char** current = list;

	char** current_cmp = NULL;
	char** min_str = NULL;

	while (current != NULL)//selection sort
	{
		min_str = current;
		current_cmp = current;

		while (current_cmp != NULL)
		{
			if (strcmp(min_str[0], current_cmp[0]) > 0)
				min_str = current_cmp;

			current_cmp = (char**)current_cmp[1];
		}

		swap_str(current, min_str);

		current = (char**)current[1];
	}
	return;
}

void swap_str(char** first, char** second)
{
	char* temp_elem = first[0];
	first[0] = second[0];
	second[0] = temp_elem;
	return;
}

void show_list(char** list)
{
	if (list == NULL)
		return;

	char** current = list;
	while (current != NULL)
	{
		printf((char*)current[0]);
		printf("\n");
		current = (char**)current[1];
	}
	printf("\n");
}
