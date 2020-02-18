#pragma once

#include <stdlib.h>
#include <string.h>

void CreateList(char*** head, char* str);

void AddElem(char*** list_head, char* str);

char* ReadElem(char*** list_head, int pos);

void RemoveAllElem(char*** list_head);

void RemoveElem(char*** list_head, int pos);