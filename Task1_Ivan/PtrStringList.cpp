#include "PtrStringList.h"

namespace slst
{

    void slst::StringListInit(char*** list)
    {
        list[0] = StringListAllocateNode();
    }

    void slst::StringListDestroy(char*** list)
    {
        if (list == nullptr || list[0] == nullptr)
            return;
        char** currentNode = list[0];
        while (currentNode /* != LIST_END */)
        {
            char** next = StringListGetNext(currentNode);
            free(currentNode[0]);
            free(currentNode);
            currentNode = next;
        }
        list[0] = nullptr;                                      // Terminate end of the list
    }

    void slst::StringListAdd(char** list, String str)
    {  
        char** newNode = nullptr;
        if (list && str) // If list is not empty then append
        {
            newNode = StringListAllocateNode();
            StringListAssignVal(newNode, str);
            char** currentNode = list;
            char** next;
            while (next = StringListGetNext(currentNode))       // Find end of the list
                currentNode = next;
            StringListSetNext(currentNode, newNode);            // Append new node
        }
        //else throw...                                       
    }

    void slst::StringListRemove(char** head, const String str)
    {
        char** currentNode = head;
        while (currentNode != nullptr && currentNode == head)
        {
            char** next = StringListGetNext(currentNode);
            if (util::StringsEqual(currentNode[0], str))
            {
                if (next == nullptr)    // Head was the last element
                {
                    if (head[0]) free(head[0]);
                    head[0] = nullptr;
                    head[1] = nullptr;
                    return;
                }
                else                    // There are still some elements left
                {
                    head[0] = next[0];
                    StringListSetNext(head, StringListGetNext(next));
                    free(next);
                }    
            }       
            else
                currentNode = next;
        }

        char** prev = head;
        while (currentNode != nullptr)  // List is not empty, check after the head
        {
            char** next = StringListGetNext(currentNode);
            if (util::StringsEqual(currentNode[0], str))
            {
                StringListSetNext(prev, next);
                if (currentNode[0]) free(currentNode[0]);
                free(currentNode);
            }
            else
                prev = currentNode;
            currentNode = next;
        }
    }

    size_t slst::StringListSize(char** list)
    {
        if (!list)
            return 0;

        char** currentNode = list;
        size_t i = 1;                           // Head not null -> size >= 1
        while (StringListForward(&currentNode)) // Traverse list until reached tail, increment each iteration
            ++i;
        return i;
    }

    int slst::StringListIndexOf(char** node, const char* str)
    {
        int index = 0;
        while (node)
        {
            char* nextValue = *node;
            if (util::StringsEqual(nextValue, str))
                return index;
            ++index;
            StringListForward(&node);
        }
        return -1;
    }

    void slst::StringListRemoveDuplicates(char** currentNode)
    {
        while (currentNode /* != LIST_END */)
        {
            char** next = StringListGetNext(currentNode);
            StringListRemoveOrClear(&next, currentNode[0]);  // Next might be a duplicate, and be deleted,
            currentNode[1] = reinterpret_cast<char*>(next);  // which will make currentNode.next a wild pointer, so reassign
            currentNode = next;
        }
    }

    void slst::StringListReplaceInStrings(char** node, char* before, char* after)
    {
        if (!node || (before == after) || !before || !after || (strcmp(before, after) == 0))
            return;

        do
        {
            if (node[0])
            {
                char* needsReplace = strstr(node[0], before);
                if (needsReplace)
                {
                    char* res = util::StringReplace(node[0], before, after);
                    free(node[0]);
                    node[0] = res;
                }
            }
        
            StringListForward(&node);
        } while (node  /* != LIST_END */);
    }

    void slst::StringListSort(char** list)
    { // Uses selection sort
        char** currentNode = list;
        while (currentNode  /* != LIST_END */)       // Traverse the List 
        {
            char** maxValNode = currentNode;
            char** unsortedNode = StringListGetNext(currentNode);

            while (unsortedNode)                     // Traverse the unsorted sublist 
            {
                if ((maxValNode[0] != unsortedNode[0]) &&
                    (maxValNode[0] && unsortedNode[0]) &&  // Both not null for strcmp
                    (strcmp(maxValNode[0], unsortedNode[0]) > 0))
                    maxValNode = unsortedNode;

                StringListForward(&unsortedNode);
            }

            char* dataTemp = currentNode[0];         // Swap
            currentNode[0] = maxValNode[0];
            maxValNode[0] = dataTemp;

            StringListForward(&currentNode);
        }
    }

    /* Helpers */
#pragma region HelperFunctions
    char** slst::StringListAllocateNode()
    {
        char** node = util::allocate_memory<char*>(NODE_SIZE);  // Allocate space for 2 pointers to char*
        node[0] = nullptr;
        node[1] = nullptr;                                      // Terminate list
        return node;
    }

    char* slst::StringListAssignVal(char** node, char* value)
    {
        if (!value)
            return nullptr;

        size_t valueLength = strlen(value) + 1;
        node[0] = util::reallocate_memory<char>(&node[0], valueLength); // node[0] was malloc char*
        strcpy_s(node[0], valueLength, value);

        return node[0];
    }

    char** slst::StringListGetNext(char** node)
    {
        return reinterpret_cast<char**>(node[1]);
    }

    char** slst::StringListSetNext(char** target, char** next)
    {
        char** oldNext = reinterpret_cast<char**>(target[1]);
        target[1] = reinterpret_cast<char*>(next);
        return oldNext;
    }

    char** slst::StringListForward(char*** target)
    {
        char** next = StringListGetNext(target[0]);
        target[0] = next;
        return next;
    }

    void slst::StringListInit(char*** list, size_t size)
    {
        list[0] = StringListAllocateNode();                     // Create first node
        char** currentNode = list[0];
        for (size_t i = 1; i < size; i++)
        {
            currentNode[0] = nullptr;
            char** next = StringListAllocateNode();             // Create next node, that is already terminated with nullptr
            currentNode[1] = reinterpret_cast<char*>(next);     // Link next to current node
            currentNode = reinterpret_cast<char**>(next);
        }
        //currentNode[1] = nullptr;                             // Terminate end of the list with the nullptr
    }

    void slst::StringListRemoveOrClear(char*** list, char* str)
    {
        char** currentNode = list[0];
        char** prev = nullptr;

        while (currentNode)
        {
            char** next = StringListGetNext(currentNode);
            if (util::StringsEqual(currentNode[0], str))
            {
                if (prev)           // Element about to be deleted isn't list's actual head 
                    StringListSetNext(prev, next);
                else                // If it was then assign next as the head
                    list[0] = next; // List is considered cleared if next will be null here

                if (currentNode[0]) free(currentNode[0]);
                free(currentNode);
            }
            else
                prev = currentNode;
            currentNode = next;
        }
    }
#pragma endregion HelperFunctions

}
