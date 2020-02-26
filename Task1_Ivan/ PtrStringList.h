#pragma once
#include <string.h>
#include <stdlib.h>

#include "Utility.h"

namespace slst
{
    /*
        List of strings:

        char*** - list;
        char**  - node;
        char*   - string;
        
        *
        */

    #pragma region Misc
    using String = char*;
    using Node = char**;
    constexpr unsigned int NODE_SIZE = 2;
    constexpr unsigned int NODE_BYTE_COUNT = NODE_SIZE * sizeof(Node); 
    constexpr void* LIST_END = nullptr;
    #pragma endregion Misc

    #pragma region Task
    /* Initializes list */
    void StringListInit(char*** list);
    /* Destroy list and set pointer to NULL. */
    void StringListDestroy(char*** list);

    /* Inserts value at the end of the list. */
    void StringListAdd(char** list, String str);
    /* Removes all occurrences of str in the list. Never free's head(only it's content) */
    void StringListRemove(char** head, const String str);

    /* Returns the number of items in the list. */
    size_t StringListSize(char** list);
    /* Returns the index position of the first occurrence of str in the list. */
    int StringListIndexOf(char** list, const char* str);

    /* Removes duplicate entries from the list. */
    void StringListRemoveDuplicates(char** list);
    /* Replaces every occurrence of the before, in each of the string lists's strings, with after. */
    void StringListReplaceInStrings(char** list, char* before, char* after);
    /* Sorts the list of strings in ascending order */
    void StringListSort(char** list);
    #pragma endregion Task

    #pragma region Helpers
    /* Copies string into the node. Returns that copy */
    char* StringListAssignVal(char** node, char* value);

    /* Get next node */
    char** StringListGetNext(char** node);

    /* Sets target's next node. Returns previously assigned next */
    char** StringListSetNext(char** target, char** next);

    /* Sets node to it's next element, returns that next element */
    char** StringListForward(char*** target);

    /* Manulally allocates new node, that is nullptr terminated */
    char** StringListAllocateNode();

    /* Initializes list of given size */
    void StringListInit(char*** list, size_t size);

    /* !Might invalidate external pointers to the head! Removes all occurences of str in the list. If list is homogenous clears it.*/
    void StringListRemoveOrClear(char*** list, char* str);
    #pragma endregion Helpers
}
