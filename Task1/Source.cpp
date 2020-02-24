#define _CRT_SECURE_NO_WARNINGS
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
	*list = (char **)malloc(2 * sizeof(char*));
	(*list)[0] = NULL;
	(*list)[1] = NULL;
}


void StringListAdd(char** list, char* str){
	int str_size = strlen(str) + 1;
	if (!list[0]) {
		cout << "list empty" << endl;
		list[0] = (char*)malloc(str_size*sizeof(char));
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

	cout << "added item with data:"<<str << endl;
}


void show(char** list) {
	char** temp = list;
	int i = 0;
	if (list == NULL||!list||list[0]==NULL) {
		return;
	}
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
	int current_index=0;
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
	int size = 0;
	char **head = list;
	while (head!=NULL) {
		head = (char**)head[1];
		size++;
	}
	return size;
}


void StringListRemove(char** list, char* str) {
	char **head = list;
	char **prev = list;
	if (head == NULL) {
		return;
	}
	while (head != NULL) {
		if (strcmp(head[0], str) == 0 && head[1] == NULL) {
			char **del1 = head;
			cout << "found: " << del1[0] << endl;

			prev[1] = head[1];

			free(del1[0]);
			return;
		}
		if (strcmp(head[0], str) == 0) {
			char **del = head;
			cout << "found: " << del[0] << endl;
			
			prev[1] = head[1];

			free(del[0]);
		}
		prev = head;
		head = (char**)head[1];

	}
}




void StringListDestroy(char ***list) {

	char **head = *list;
	//char **prev = list;
	while (head) {
		char** del = head;
		cout << del[0] << "->to delete" << endl;
		head = (char**)head[1];
		free(del[0]);
		//free(del);
	}
	*list = NULL;
}




void StringListRemoveDuplicates(char** list) {
	char **current = list;
	char **helper = list;
	while (helper[1] != NULL) {
		while (current[1] != NULL) {
			if (strcmp(current[0], helper[0]) == 0) {
				cout << "!!!FOUND" << StringListIndexOf(list, helper[0]);
				free(current[0]);
			}
			//helper = current;
			current = (char**)current[1];
		}
		helper = (char**)helper[1];
		current = list;
	}
}

void StringListSort(char **list) {
	char **current = list;
	char **helper = list;//first
	while (helper != NULL) {
		while (current != NULL) {
			if (strcmp(current[0], helper[0])< 0) {
				int lenght_tmp = strlen(current[0]) + 1;
				char *tmp = (char*)malloc(lenght_tmp);
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

	int size_to_copy = strlen(after)+1;
	while (current != NULL) {
		if (strcmp(current[0], before) == 0) {
			realloc(current[0], size_to_copy);
			strcpy(current[0], after);			
			// copy into current 0  after string
		}
		current = (char**)current[1];
	}
}


int main() {
	char** list;
	StringListInit(&list);
	char str1[] = "bbb";
	char str2[] = "aaa";
	char str3[] = "ddd";
	char str4[] = "ccc";
	char str5[] = "str";

	show(list);
	StringListAdd(list, str1);
	StringListAdd(list, str2);
	StringListAdd(list, str3);
	StringListAdd(list, str4);
	StringListAdd(list, str5);

	char s[] = "12";
	show(list);
	
	int found = StringListIndexOf(list, s);
	if (found) {
		cout << "Index of:" << s << "is=" << found << endl;
	}
	else {
		cout << "No such element in list" << endl;
	}

	char str7[] = "str6";
	StringListAdd(list, str7);
	StringListAdd(list, str2);
	StringListAdd(list, str7);
	cout << "List size=" << StringListSize(list) << endl;
	show(list);
	StringListRemove(list, str2);
	cout << "List size=" << StringListSize(list) << endl;
	show(list);
	system("pause");
	StringListAdd(list, str2);
	char str0[] = "00000";
	StringListReplaceInStrings(list,str2,str0);
	show(list);
	StringListSort(list);
	show(list);
	//StringListRemoveDuplicates(list);
	//StringListDestroy(&list);//have a problem with correct deleting an item
	system("pause");
	return 0;
}