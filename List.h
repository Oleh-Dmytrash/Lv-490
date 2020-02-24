#pragma once

void StringListInit(char*** list);
void StringListDestroy(char*** list);
void StringListAdd(char** list, const char* el);
void StringListRemove(char** list, char* str);
int StringListSize(char** list);
int StringListIndexOf(char** list, char* str);
void StringListRemoveDuplicates(char** list);
void StringListReplaceInStrings(char** list, char* before, char* after);
void StringListSort(char** list);
