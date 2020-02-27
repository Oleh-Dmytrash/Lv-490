//#include "list.h"
//
//
//void StringListInit(StringList* list)
//{
//	*list = (ListNode)malloc(sizeof(char*) * 2);
//	(*list)[0] = nullptr;
//	(*list)[1] = nullptr;
//}
//
//void StringListDestroy(StringList* list)
//{
//	if (list == nullptr || *list == nullptr) return;
//	ListNode next_element = (ListNode)(*list)[1], current_element = *list;
//	while (current_element != nullptr)
//	{
//		free((char*)current_element[0]);
//		free(current_element);
//		current_element = next_element;
//		if (next_element != nullptr)
//			next_element = (ListNode)next_element[1];
//	}
//}
//
//void StringListAdd(StringList list, const char* str)
//{
//	if (list == nullptr) return;
//
//	ListNode last_element = list;
//	
//	if (last_element[0] == nullptr)
//	{
//		last_element[0] = AllocateDynamically(str);
//		return;
//	}
//	
//	while (last_element[1] != nullptr)
//	{
//		last_element = (ListNode)(last_element[1]);
//	}
//
//
//	auto temp = last_element;
//	last_element = (ListNode)malloc(2 * sizeof(char**));
//
//	temp[1] = (char*)last_element;
//
//	char* dynamic_str = AllocateDynamically(str);
//	last_element[0] = dynamic_str;
//	last_element[1] = nullptr;
//
//}
//
//void StringListRemove(StringList list, const char* str)
//{
//	if (list == nullptr) return;
//	ListNode current_element = list, next_element;
//
//	// if the value in the head is to be removed
//	while (strcmp((char*)current_element[0], str) == 0)
//	{
//		if ((list)[1] == nullptr)
//		{
//			free(current_element[0]);
//			current_element[0] = nullptr;
//			return;
//		}
//		free(current_element[0]);
//		ListNode second_list_node = (ListNode)current_element[1];
//		current_element[0] = (second_list_node)[0];
//		current_element[1] = second_list_node[1];
//		free(second_list_node);
//	}
//	
//	next_element = (ListNode)current_element[1];
//	if (next_element == nullptr) return;
//	while (next_element[1] != nullptr)
//	{
//		if (strcmp(next_element[0], str) == 0)
//		{
//			char** temp = next_element;
//			current_element[1] = next_element[1];
//			next_element = (ListNode)current_element[1];
//			free((char*)temp[0]);
//			free(temp);
//		}
//		else
//		{
//			current_element = next_element;
//			next_element = (ListNode)next_element[1];
//		}
//	}
//
//	if (strcmp((char*)next_element[0], str) == 0)
//	{
//		current_element[1] = nullptr;
//		free((char*)next_element[0]);
//		free(next_element);
//	}
//}
//
//size_t StringListSize(const StringList list)
//{
//	if (list && list[0] == nullptr) return 0;
//	ListNode current_element = list;
//	size_t result{ 0 };
//	while (current_element != nullptr)
//	{
//		++result;
//		current_element = (ListNode)current_element[1];
//	}
//	return result;
//}
//
//int StringListIndexOf(const StringList list, const char* str)
//{
//	int item_index{ 0 };
//	ListNode current_element = list;
//	while (current_element != nullptr)
//	{
//		if (strcmp(current_element[0], str) == 0) return item_index;
//		++item_index;
//		current_element = (ListNode)current_element[1];
//	}
//	return -1;
//}
//
//void StringListRemoveDuplicates(StringList list)
//{
//	if (list == nullptr) return;
//	ListNode current_node = list;
//	while (current_node[1] != nullptr)
//	{
//		StringListRemove((StringList)current_node[1], current_node[0]);
//		current_node = (ListNode)current_node[1];
//	}
//}
//
//void QuickSort(StringList list, int start, int end)
//{
//	if (start < end)
//	{
//		size_t partition_index = StringListPartition(list, start, end);
//		QuickSort(list, start, partition_index - 1);
//		QuickSort(list, partition_index + 1, end);
//	}
//}
//
//void StringListReplaceInStrings(StringList list, const char * old_value, const char * new_value)
//{
//	size_t new_value_length = strlen(new_value);
//	ListNode current_node = list;
//	while (current_node != nullptr)
//	{
//		if (strcmp(current_node[0], old_value) == 0)
//		{
//			current_node[0] = (char*)realloc(current_node[0], new_value_length * sizeof(char) + 1);
//			strcpy(current_node[0], new_value);
//		}
//		current_node = (ListNode)current_node[1];
//	}
//}
//
//void StringListSort(StringList list)
//{
//	QuickSort(list, 0, StringListSize(list) - 1);
//}
//
//char * StringListGetItemByIndex(const StringList list, size_t index)
//{
//	ListNode needed_node;
//	return ((needed_node = StringListGetNodeByIndex(list, index)) != nullptr ? needed_node[0] : nullptr);
//}
//
//void StringListSwapItems(const StringList list, size_t index1, size_t index2)
//{
//	size_t list_size = StringListSize(list);
//	if (index1 >= list_size || index2 > list_size) return;
//
//	ListNode first_node = nullptr, second_node = nullptr, current_node = list;
//	size_t current_index{ 0 };
//	while (current_index < list_size)
//	{
//		if (current_index == index1)
//		{
//			first_node = current_node;
//		}
//		if (current_index == index2)
//		{
//			second_node = current_node;
//		}
//
//		current_node = (ListNode)current_node[1];
//		++current_index;
//	}
//
//	char* temp = first_node[0];
//	first_node[0] = second_node[0];
//	second_node[0] = temp;
//}
//
//
//
//
//ListNode StringListGetNodeByIndex(StringList list, size_t index)
//{
//	if (index >= StringListSize(list)) return nullptr;
//	int ind = index;
//	char** current_element = list;
//	while (ind > 0)
//	{
//		current_element = (char**)current_element[1];
//		ind--;
//	}
//	return current_element;
//}
//
//
//size_t StringListPartition(StringList list, int start_index, int end_index)
//{
//	ListNode pivot = StringListGetNodeByIndex(list, end_index);
//
//	int i = start_index - 1;
//	for (int j = start_index; j < end_index - 1; j++)
//	{
//		if (strcmp(StringListGetItemByIndex(list, j), pivot[0]) < 0)
//		{
//			i++;
//			StringListSwapItems(list, i, j);
//		}
//	}
//	StringListSwapItems(list, i + 1, end_index);
//	return i + 1;
//
//}
//
//void StringListPrint(const StringList list)
//{
//	if (list == nullptr) return;
//	ListNode current_element = list;
//	while (current_element != nullptr)
//	{
//		printf((char*)current_element[0]);
//		printf("\n");
//		current_element = (ListNode)current_element[1];
//	}
//	printf("\n");
//}
//
//char* AllocateDynamically(const char* staticly_allocated_ptr)
//{
//	char* dynamicly_allocated_ptr = (char*)malloc(strlen(staticly_allocated_ptr) * sizeof(char) + 1);
//	if(dynamicly_allocated_ptr != nullptr)
//	strcpy(dynamicly_allocated_ptr, staticly_allocated_ptr);
//	else return nullptr;
//	return dynamicly_allocated_ptr;
//}
//
//
