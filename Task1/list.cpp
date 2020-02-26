//#pragma once
//#include"list.h"
//
//
//void StringListInit(char*** list)
//{
//	*list = (char**)malloc(sizeof(char*) * 2);
//	list[0][0] = NULL;
//	list[0][1] = NULL;
//	return;
//}
//
//
//void StringListDestroy(char*** head)
//{
//	if (*head != NULL)
//	{
//		while ((*head)[1] != NULL)
//		{
//			char** current = *head;
//			char** previous = current;
//			while (current[1] != NULL)
//			{
//				previous = current;
//				current = (char**)current[1];
//			}
//			previous[1] = NULL;
//			free(current[0]);
//			free(current);
//		}
//		free(head[0][0]);
//		free(head[0]);
//		free(head);
//		head = NULL;
//	}
//	else return;
//	return;
//}
//
//void StringListAdd(char** node, const char* str)
//{
//	char*dyn_str = (char*)malloc(sizeof(char)*(strlen(str) + 1));//make input string dynamicly allocated for future free()
//	strcpy(dyn_str, str);
//	dyn_str[strlen(str)] = '\0';
//
//	char** temp = node;
//
//	if (!temp)
//		return;
//	while (1)
//	{
//		if (temp[0] == NULL)
//		{
//			temp[0] = dyn_str;
//			break;
//		}
//		if (temp[1] == NULL)
//		{
//			char** node = (char**)malloc(sizeof(char*) * 2);
//			if (!node)
//				return;
//			node[0] = dyn_str;
//			node[1] = NULL;
//			temp[1] = (char*)node;
//			break;
//		}
//		temp = (char**)temp[1];
//	}
//	return;
//}
//
//void StringListRemove(char** head, const char* str)
//{
//	char**current = head;
//	char**prev = current;
//	while (1)
//	{
//		if (strcmp(str, current[0]) == 0)
//		{
//			if (current == prev)//if first
//			{
//				if (current[1] == NULL)//if one node
//				{
//					free(current[0]);
//					current[0] = NULL;
//					break;
//				}
//				//more then one node
//				char**temp_next = (char**)current[1];
//				free(current[0]);//remove data from head
//				current[0] = temp_next[0];//change data from next node to head
//				current[1] = temp_next[1];//change ptr to next->next node
//				free(temp_next);
//				continue;
//			}
//
//			if (current[1] == NULL)//if it's last node
//			{
//				free(current[0]);
//				free(current);
//				prev[1] = NULL;
//				break;
//			}
//			else//not last
//			{
//				prev[1] = current[1];
//				free(current[0]);
//				free(current);
//				current = prev;
//			}
//		}
//		else
//		{
//			if (current[1] != NULL)
//			{
//				prev = current;
//				current = (char**)current[1];
//			}
//			else break;
//		}
//
//	}
//	return;
//}
//
//int StringListSize(char** list)
//{
//	int counter = 0;
//	while (list != NULL)
//	{
//		++counter;
//		list = (char**)list[1];
//	}
//	return counter;
//
//}
//
//int StringListIndexOf(char** list, const char* str)
//{
//	if (str == NULL || list == NULL)
//		return -1;
//
//	int index = 0;
//	while (strcmp(list[0], str) != 0)
//	{
//		list = (char**)list[1];
//		++index;
//	}
//	return index;
//}
//
//void StringListRemoveDuplicates(char** list)
//{
//	if (list == NULL)
//		return;
//	char**prev = list;
//	char** current = list;
//	char** next = list;
//
//	while (next[1]!=NULL)
//	{
//		next =(char**)current[1];
//		if (strcmp(current[0] , next[0])==0)//current->next
//		{
//			next = (char**)((char**)current[1])[1];
//			current[1] = next[1];
//			free(next[0]);
//			free(next);
//			current = (char**)current[1];
//		}
//		else
//		{
//			prev = current;
//			current = (char**)current[1];
//		}
//	}
//	return;
//}
//
//void StringListReplaceInStrings(char** list, char* before, char* after)
//{
//	if (list == NULL)
//		return;
//
//	char** current = list;
//	int new_size = strlen(after);
//
//	while (current != NULL)
//	{
//		if (strcmp(current[0], before) == 0)
//		{
//			current[0] = (char*)realloc(current[0], new_size * sizeof(char) + 1);
//			strcpy(current[0], after);
//		}
//
//		current = (char**)current[1];
//	}
//	return;
//}
//
//void StringListSort(char** list)
//{
//	if (list == NULL || list[1] == NULL)
//		return;
//
//	int size = StringListSize(list);
//	char** current = list;
//
//	char** current_cmp = NULL;
//	char** min_str = NULL;
//
//	while (current != NULL)
//	{
//		min_str = current;
//		current_cmp = current;
//
//		while (current_cmp != NULL)
//		{
//			if (strcmp(min_str[0], current_cmp[0]) > 0)
//			{
//				min_str = current_cmp;
//			}
//
//			current_cmp = (char**)current_cmp[1];
//		}
//
//		swap_str(current, min_str);
//
//		current = (char**)current[1];
//	}
//	return;
//}
//
//void swap_str(char** first, char** second)
//{
//	char* temp_elem = first[0];
//	first[0] = second[0];
//	second[0] = temp_elem;
//	return;
//}
//
//void show_list( char** list)
//{
//	if (list == NULL) 
//		return;
//
//	char** current = list;
//	while (current != NULL)
//	{
//		printf((char*)current[0]);
//		printf("\n");
//		current = (char**)current[1];
//	}
//	printf("\n");
//}




//void StringListRemoveDuplicates(char** list)
//{
//	if (list == NULL)
//		return;
//
//	char** current = list;
//
//
//	while (current[1] != NULL)
//	{
//		StringListRemove((char**)current[1], current[0]);
//		current = (char**)current[1];
//	}
//	return;
//}