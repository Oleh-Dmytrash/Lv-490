// dynamyc_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "list.h"

int main()
{
    char str[] = { "abcdefg" };
    char** list = NULL;
    StringListInit(&list);
    StringListAdd(list, str + 1);
    StringListAdd(list, str + 1);
    StringListAdd(list, str + 1);
    StringListAdd(list, str + 1);
    StringListAdd(list, str + 1);
    StringListAdd(list, str + 1);
    StringListAdd(list, str + 1);

    /*std::cout << "Size of list: " << StringListSize(list) << std::endl << std::endl;

    std::cout << "First position for " << str + 2 << ": " << StringListIndexOf(list, str + 2) << std::endl << std::endl;

    std::cout << "Non sorted array:\n" << std::endl;*/
    int pos = 0;
    char** elem = NULL;
    do
    {
        elem = ReadElem(&list, pos);
        if (elem != NULL)
        {
            printf("Element %i\n", pos);
            printf("Address: %p\n", elem);
            printf("Element: %s\n", elem[0]);
        }
        ++pos;
    } while (elem);

    StringListRemove(list, str + 1);

    std::cout << "\nSorted array:\n" << std::endl;
    pos = 0;
    elem = NULL;
    do
    {
        elem = ReadElem(&list, pos);
        if (elem != NULL)
        {
            printf("Element %i\n", pos);
            printf("Address: %p\n", elem);
            printf("Element: %s\n", elem[0]);
        }
        ++pos;
    } while (elem);

    StringListDestroy(&list);

    /*std::cout << "\n----------------------------------------------------------------------------------\n";

    std::cout << "\nList with dublicates:\n" << std::endl;

    StringListInit(&list);
    StringListAdd(list, str);
    StringListAdd(list, str);
    StringListAdd(list, str);
    StringListAdd(list, str);

    pos = 0;
    elem = NULL;
    do
    {
        elem = ReadElem(&list, pos);
        if (elem != NULL)
        {
            printf("Element %i\n", pos);
            printf("Address: %p\n", elem);
            printf("Element: %s\n", elem[0]);
        }
        ++pos;
    } while (elem);

    StringListRemoveDuplicates(list);

    std::cout << "\nList without dublicates:\n" << std::endl;

    pos = 0;
    elem = NULL;
    do
    {
        elem = ReadElem(&list, pos);
        if (elem != NULL)
        {
            printf("Element %i\n", pos);
            printf("Address: %p\n", elem);
            printf("Element: %s\n", elem[0]);
        }
        ++pos;
    } while (elem);

    StringListDestroy(&list);

    std::cout << "\n----------------------------------------------------------------------------------\n";

    StringListInit(&list);
    StringListAdd(list, str + 1);
    StringListAdd(list, str);
    StringListAdd(list, str + 1);
    StringListAdd(list, str);

    std::cout << "\nList before changes:\n" << std::endl;

    pos = 0;
    elem = NULL;
    do
    {
        elem = ReadElem(&list, pos);
        if (elem != NULL)
        {
            printf("Element %i\n", pos);
            printf("Address: %p\n", elem);
            printf("Element: %s\n", elem[0]);
        }
        ++pos;
    } while (elem);

    StringListReplaceInStrings(list, str + 1, str);

    std::cout << "\nList after changes:\n" << std::endl;
    std::cout << std::endl << str + 1 << " to " << str << std::endl << std::endl;

    pos = 0;
    elem = NULL;
    do
    {
        elem = ReadElem(&list, pos);
        if (elem != NULL)
        {
            printf("Element %i\n", pos);
            printf("Address: %p\n", elem);
            printf("Element: %s\n", elem[0]);
        }
        ++pos;
    } while (elem);

    StringListDestroy(&list);*/

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
