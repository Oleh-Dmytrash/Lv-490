#include "PtrStringList.h"
#include <iostream>

void PrintList(char** head);
void PrintListSize(char** head);
std::ostream& operator<<(std::ostream& out, char** node);

int main(int argc, char** argv)
{
	char** list;
	constexpr size_t initialSize = 5;
	slst::StringListInit(&list, initialSize);

	{
		char** head = list;
		for (size_t i = 0; i < initialSize; i++)
		{
			head[0] = util::allocate_memory<char>(2);
			head[0][0] = initialSize - i + '0';
			head[0][1] = '\0';
			slst::StringListForward(&head);
		}
	}
	std::cout << "Initial list: \n";
	PrintList(list);
	PrintListSize(list);
	for (size_t k = 0; k < 5; k++)
	{
		char* str = util::allocate_memory<char>(2);
		str[0] = k + '0';
		str[1] = '\0';
		slst::StringListAdd(list, str);
		slst::StringListAdd(list, str);
	}
	std::cout << "\nList with appended elements: \n";
	PrintList(list);
	PrintListSize(list);

	slst::StringListRemove(list, (char*)"4");
	std::cout << "\nList with removed [ 4 ]: \n";
	PrintList(list);
	PrintListSize(list);

	slst::StringListRemove(list, (char*)"5");
	std::cout << "\nList with removed [ 5 ]: \n";
	PrintList(list);
	PrintListSize(list);

	constexpr const char* toFind = "0";
	std::cout << "\nIndex of " << toFind << " is " << slst::StringListIndexOf(list, toFind) << '\n';

	slst::StringListRemoveDuplicates(list);
	std::cout << "\nList with removed duplicates: \n";
	PrintList(list);
	PrintListSize(list);

	slst::StringListRemove(list, (char*)"3");
	slst::StringListRemove(list, (char*)"2");
	slst::StringListRemove(list, (char*)"1");
	slst::StringListRemove(list, (char*)"0");
	std::cout << "\nList with removed everything: \n";
	PrintList(list);
	PrintListSize(list);

	for (size_t k = 0; k < 5; k++)
	{
		char* str = util::allocate_memory<char>(3);
		str[0] = k + '0';
		str[1] = 1 + '0';
		str[2] = '\0';
		slst::StringListAdd(list, str);
		slst::StringListAdd(list, str);
	}
	std::cout << "\nList with added elements that is gonna be edited with StringListReplaceInStrings: \n";
	PrintList(list);
	PrintListSize(list);

	slst::StringListReplaceInStrings(list, (char*)"1", (char*)"RI");
	std::cout << "\nEdited list, 1 is replacesd with RI: \n";
	PrintList(list);
	PrintListSize(list);

	slst::StringListReplaceInStrings(list, (char*)"IR", (char*)"Hello World");
	std::cout << "\nEdited list, IR is replaced with Hello World: \n";
	PrintList(list);
	PrintListSize(list);

	slst::StringListReplaceInStrings(list, (char*)"Hello World", (char*)"Just Hi");
	std::cout << "\nEdited list, Hello World is replaced with Just Hi: \n";
	PrintList(list);
	PrintListSize(list);

	slst::StringListSort(list);
	std::cout << "\nList, sorted in ascending order: \n";
	PrintList(list);
	PrintListSize(list);

	slst::StringListDestroy(&list);
	std::cout << "\nDestroyed list(strings were free'd):\n";
	PrintList(list);
	PrintListSize(list);

	std::cin.get();
}

std::ostream& operator<<(std::ostream& out, char** node)
{
	return out << (node[0] ? node[0] : "NULL");
}

void PrintList(char** head)
{
	if (!head)
		std::cout << "NULL_LIST\n";
	else
	{
		while (head)
		{
			std::cout << head << ' ';
			slst::StringListForward(&head);
		}
		std::cout << '\n';
	}
}

void PrintListSize(char** head)
{
	std::cout << "List size: " << slst::StringListSize(head) << '\n';
}