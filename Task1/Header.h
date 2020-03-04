#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdlib.h>
#include<iostream>
#include<string.h>

using namespace std;

/*
0-data
1-pointer to the next elment
*/

void StringListInit(char ***list)
{
	if (*list == NULL) {
		return;
	}
	*list = (char **)malloc(2 * sizeof(char*));
	(*list)[0] = NULL;
	(*list)[1] = NULL;
}


void StringListAdd(char** list, char* str) {
	int str_size = strlen(str) + 1;
	if (list == NULL || !list[0]) {
		cout << "list empty" << endl;
		list[0] = (char*)malloc(str_size * sizeof(char));
		strcpy(list[0], str);
		cout << "added item with data:" << str << endl;
		return;
	}

	char **tmp = (char**)malloc(2 * sizeof(char*));
	tmp[0] = (char*)malloc(str_size * sizeof(char));
	strcpy(tmp[0], str);

	tmp[1] = 0;
	char **head = (list);
	while (head[1]) {
		head = (char**)head[1];
	}
	head[1] = (char*)tmp;

	cout << "added item with data:" << str << endl;
}


void show(char** list) {
	char** temp = list;
	if (list == NULL || list[0] == NULL /*|| list[0]*/) { //list[0] is present
		if (list == NULL)
			cout << "1" << endl;
		if (list[0] == NULL)
			cout << "2" << endl;
		if (list[0])
			cout << "3" << endl;
		return;
	}
	int i = 0;
	while (temp) {
		cout << i << "->" << temp[0] << endl;
		temp = (char**)(temp[1]);
		i++;
	}
}



/* Returns the index position of the first occurrence of str in the list. */
int StringListIndexOf(char** list, char* str) {
	int index = NULL;
	char **head = list;
	int current_index = 0;
	while (head != NULL) {
		if (strcmp(head[0], str) == 0) {
			index = current_index;
			return index;
		}
		head = (char**)head[1];
		current_index++;
	}
	return index;
}

int StringListSize(char**list) {
	char **head = list;
	int size = 0;

	if (head == NULL|| list[0] == NULL) {
		return size;
	}

	while (head != NULL ) {
		head = (char**)head[1];
		size++;
	}
	return size;
}

void StringListDestroy(char ***list) {
	if (*list == NULL || *list[0] == NULL) {
		return;
	}
	char **cur = *list;
	char **next = *list;

	while (cur) {
		//next=cur1
		if (next[1]!=NULL) {
			next = (char**)next[1];
		}
		else {
			break;
		}
		cout << "to del->" << cur[0] << endl;
		cur[1] = next[1];
		cur[0] = _strdup(next[0]);


		free(next[0]);
		free(next);
		 next= cur ;
	}
	cout << "to del->" << cur[0] << endl;	
	free(next[0]);
	free(next);
	(*list)[0] = NULL;
	(*list)[1] = NULL;

}

void StringListRemove(char** list, char* str)
{
	if (list == NULL || *list == NULL) return;
	int last = StringListSize(list);
	char** end = list;
	while (end[1]!=NULL)
	{
		end = (char**)end[1];
	}
	char** current = list;
	char** previous = NULL;
	char** next = list;
	if (next) {
		next = (char**)next[1];
	}
	while (current != NULL)
	{
		if (strcmp(current[0], str) == 0 && current == list) {
			//delete first
			next = (char**)current[1];
			free(list[0]);
			if (next)
			{
				list[0] = _strdup(next[0]);
				list[1] = next[1];
				free(next);
			}
			else //empty
			{
				list[0] = NULL;
				current = NULL; // end loop
			}
		}
		else if (strcmp(current[0], str) == 0 && current == end){
			previous[1] = NULL;
			free(current[0]);
			free(current);
			current = previous;
		}
		else if(strcmp(current[0], str) == 0){
			previous[1] = current[1];
			free(current[0]);
			free(current);
			current = previous;
		}
		previous = current;
		current = (char**)current[1];
	}
}


void StringListRemoveDuplicates(char**list) {
	char** current = list;
	char **next = list;
	if (next) {
		next = (char**)next[1];
	}
	else {
		return;
	}
	while (current != NULL)
	{
		while (next != NULL) {
			if (strcmp(current[0], next[0]) == 0) {
				StringListRemove(current, current[0]);

				next = current;
			}

			next = (char**)next[1];
		}
		current = (char**)current[1];
		next = current;
		if (next) {
			next = (char**)next[1];
		}
	}
	
}

void StringListSort(char **list) {
	char **current = list;
	char **helper = list;//first
	while (helper != NULL) {
		while (current != NULL) {
			if (strcmp(current[0], helper[0]) < 0) {
				int lenght_tmp = strlen(current[0]) + 1;
				char *tmp = (char*)malloc(lenght_tmp * sizeof(char));
				strcpy(tmp, current[0]);
				strcpy(current[0], helper[0]);
				strcpy(helper[0], tmp);
			}
			current = (char**)current[1];
		}
		helper = (char**)helper[1];
		current = helper;
	}
}


void StringListReplaceInStrings(char** list, char* before, char* after) {
	char **current = list;

	int size_to_copy = strlen(after) + 1;
	while (current != NULL) {
		if (strcmp(current[0], before) == 0) {
			current[0] = _strdup(after);/*
			realloc(current[0], size_to_copy+1);
			strcpy(current[0], after);*/
			// copy into current 0  after string
		}
		current = (char**)current[1];
	}
}