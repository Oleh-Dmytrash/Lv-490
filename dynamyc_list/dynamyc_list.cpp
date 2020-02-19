// dynamyc_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "list.h"

int main()
{
    char str[] = { "abcdefg" };
    char** list = NULL;
    CreateList(&list, str);
    AddElem(&list, str + 3);
    AddElem(&list, str + 1);
    AddElem(&list, str + 4);
    AddElem(&list, str + 2);
    
    std::cout << "Size of list: " << ListSize(&list) << std::endl << std::endl;

    std::cout << "First position for " << str + 3 << ": " << SearchFirst(&list, str + 3) << std::endl << std::endl;

    int pos = 0;
    char** elem = NULL;
    do
    {
        elem = ReadElem(&list, pos);
        if (elem != NULL)
        {
            printf("Element %i\n", pos);
            printf("Address: %p\n", elem[0]);
            printf("Element: %s\n", elem[0]);
        }
        ++pos;
    } while (elem); 

    std::cout << std::endl;
    
    RemoveElem(&list, 3);
    std::cout << "Element in position '3' deleted" << std::endl << std::endl;

    SortList(&list);

    pos = 0;
    elem = NULL;
    do
    {
        elem = ReadElem(&list, pos);
        if (elem != NULL)
        {
            printf("Element %i\n", pos);
            printf("Address: %p\n", elem[0]);
            printf("Element: %s\n", elem[0]);
        }
        ++pos;
    } while (elem);

    RemoveAllElem(&list);

    std::cout << "\n-------------------------------Remove dublicats example---------------------------\n" << std::endl;
        
    list = NULL;
    CreateList(&list, str);
    AddElem(&list, str);
    AddElem(&list, str+4);
    AddElem(&list, str);
    AddElem(&list, str+2);
    AddElem(&list, str);

    std::cout << "List before diblicat's removed:\n\n";
    pos = 0;
    elem = NULL;
    do
    {
        elem = ReadElem(&list, pos);
        if (elem != NULL)
        {
            printf("Element %i\n", pos);
            printf("Address: %p\n", elem[0]);
            printf("Element: %s\n", elem[0]);
        }
        ++pos;
    } while (elem);
    
    RemoveElemDuplicates(&list, str);

    std::cout << std::endl;

    std::cout << "List after diblicat's removed:\n\n";
    pos = 0;
    elem = NULL;
    do
    {
        elem = ReadElem(&list, pos);
        if (elem != NULL)
        {
            printf("Element %i\n", pos);
            printf("Address: %p\n", elem[0]);
            printf("Element: %s\n", elem[0]);
        }
        ++pos;
    } while (elem);

    RemoveAllElem(&list);

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
