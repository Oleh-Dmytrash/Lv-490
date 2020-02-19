#pragma once

#include <stdlib.h>
#include <string.h>

//Create list and insert first element in list
void CreateList(char*** head, char* str);

//Add element in last position
void AddElem(char*** list_head, char* str);

//read element in some position 'pos'
char** ReadElem(char*** list_head, int pos);

//remove all element from list anf free memory
void RemoveAllElem(char*** list_head);

//remove element in spme position 'pos'
void RemoveElem(char*** list_head, int pos);

//get size of list
int ListSize(char*** list_head);

//get the index position of the first exact match of specified string
int SearchFirst(char*** list_head, char* str);

//swap strings in list elements
void swap(char** elem_1, char** elem_2);

//sorting list by selection sort
void SortList(char*** list_head);