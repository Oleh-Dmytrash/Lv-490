#pragma warning(disable : 4996)
#pragma once
#include <stdlib.h>
#include <string.h>

void StringListInit(char*** list)
{
	*list = (char**)malloc(2 * sizeof(char*));
	if (!*list) return;
	(*list)[0] = NULL;
	(*list)[1] = NULL;
}

void StringListDestroy(char*** list)
{
	char** nextElement = *list;
	while (nextElement)
	{
		nextElement = (char**)((*list)[1]);
		free((*list)[0]);
		free(*list);
		*list = nextElement;
	}
	*list = 0;
}

void StringListAdd(char** list, const  char* strForAdd)
{
	if (!(list)[0])
	{
		list[0] = (char*)malloc((strlen(strForAdd) + 1) * sizeof(char));
		if (!list[0]) return;
		strcpy(list[0], strForAdd);
		return;
	}
	char** elementForAdd = (char**)malloc(2 * sizeof(char*));
	elementForAdd[0] = (char*)malloc((strlen(strForAdd) + 1) * sizeof(char));
	if (!elementForAdd || !elementForAdd[0]) return;
	strcpy(elementForAdd[0], strForAdd);
	elementForAdd[1] = 0;
	char** goToTail = (list);
	while (goToTail[1])
	{
		goToTail = (char**)(goToTail[1]);
	}
	goToTail[1] = (char*)(elementForAdd);
}

void StringListRemove(char** list, char* str)
{
	if (!(list)[0])
		return;
	while (strcmp((list)[0], str) == 0)
	{
		if (!list[1])
		{
			free(list[0]);
			list[0] = 0;
			return;
		}
		char** delElement = (char**)list[1];
		char* delStr = list[0];
		list[0] = delElement[0];
		list[1] = delElement[1];
		free(delStr);
		free(delElement);
	}
	char** goForAllElements = list;
	while (goForAllElements && goForAllElements[1])
	{
		if (strcmp(((char**)goForAllElements[1])[0], str) == 0)
		{
			char** delElement = (char**)goForAllElements[1];
			goForAllElements[1] = delElement[1];
			free(delElement[0]);
			free(delElement);
		}
		else
		{
			goForAllElements = (char**)goForAllElements[1];

		}
	}

}

int StringListSize(char** list)
{
	int countElements = 0;
	char** goForAllElements = list;
	while (goForAllElements) {
		if (goForAllElements[0])
			countElements++;
		goForAllElements = (char**)(goForAllElements[1]);
	}
	return countElements;
}

int StringListIndexOf(char** list, char* str)
{
	int elementIndex = 0;
	char** temp = list;
	while (temp && temp[0])
	{
		if (strcmp(temp[0], str) == 0)
		{
			return elementIndex;
		}
		temp = (char**)(temp[1]);
		elementIndex++;
	}
	return -1;
}
void StringListRemoveDuplicates(char** list)
{
	if (!list[1])
	{
		return;
	}
	char** goForAllElements = list;
	while (goForAllElements && goForAllElements[1])
	{
		StringListRemove((char**)goForAllElements[1], goForAllElements[0]);
		if (!((char**)goForAllElements[1])[0]) {
			char** del = (char**)goForAllElements[1];
			free(del);
			goForAllElements[1] = 0;
		}
		goForAllElements = (char**)goForAllElements[1];
	}
}

void StringListReplaceInStrings(char** list, char* before, char* after)
{
	char** goForAllElements = list;
	while (goForAllElements) {
		if (goForAllElements[0] && strcmp(goForAllElements[0], before) == 0)
		{
			free(goForAllElements[0]);
			goForAllElements[0] = _strdup(after);
			/*(char*)malloc((strlen(after) + 1) * sizeof(char));

		strcpy(goForAllElements[0], after);
		*/
		}
		goForAllElements = (char**)goForAllElements[1];
	}
}

void StringListSort(char** list)
{
	char** curentHead = list;
	while (curentHead && curentHead[1])
	{
		char** minimumElement = curentHead;
		char** goForAllElements = (char**)curentHead[1];
		while (goForAllElements && goForAllElements[0])
		{
			if (strcmp(goForAllElements[0], minimumElement[0]) < 0)
			{
				minimumElement = goForAllElements;
			}
			goForAllElements = (char**)goForAllElements[1];
		}

		if (strcmp(curentHead[0], minimumElement[0]) != 0)
		{
			char* swap = minimumElement[0];
			minimumElement[0] = curentHead[0];
			curentHead[0] = swap;
		}

		curentHead = (char**)(curentHead[1]);
	}
}