#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../list.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ListUnitTests
{		
	TEST_CLASS(ListUnitTests)
	{
	private:
		StringList list{nullptr};

	public:
		TEST_METHOD_INITIALIZE(Initialize)
		{
			StringListInit(&list);
		}
		TEST_METHOD_CLEANUP(Destroy)
		{
			StringListDestroy(&list);
		}

		/////////////////////// TESTS ////////////////////////
		
		TEST_METHOD(SLInitTest1)
		{
			StringList _list{ nullptr };
			StringListInit(&_list);
			if(_list != nullptr)
			{
				Assert::IsTrue(_list[0] == nullptr, L"The function must set the string of first element to nullptr");
			}
		}

		TEST_METHOD(SLDestroyTest1)
		{
			StringList _list{ nullptr };
			StringListInit(&_list);

			StringListDestroy(&_list);
			Assert::IsTrue(_list == nullptr, L"The function must null the list pointer after destruction");
		}
		
		TEST_METHOD(SLSizeTest1)
		{
			Assert::AreEqual(StringListSize(list), 0u, L"The list size must be 0");
		}

		TEST_METHOD(SLSizeTest2)
		{
			StringListAdd(list, "Element");
			Assert::AreEqual(StringListSize(list), 1u, L"The list size must be 1");

		}
		
		TEST_METHOD(SLSizeTest3)
		{
			StringListAdd(list, "Hi");
			StringListAdd(list, "Hello");
			StringListAdd(list, "Welcome");
			StringListAdd(list, "Hallo");
			StringListAdd(list, "Gracias");
			StringListAdd(list, "Hallo");

			Assert::IsTrue(StringListSize(list) == 6, L"The list size must be 6");
		}
		
		
		TEST_METHOD(SLAddTest1)
		{
			StringListAdd(list, "Hi");
			Assert::IsTrue(strcmp(list[0], "Hi") == 0, L"First element must coincide the added element");
		}

		TEST_METHOD(SLAddTest2)
		{
			StringListAdd(list, "Hi");
			StringListAdd(list, "Hello");
			StringListAdd(list, "Welcome");
			StringListAdd(list, "Hallo");
			StringListAdd(list, "Gracias");
			StringListAdd(list, "Hallo");
			Assert::IsTrue(strcmp(StringListGetItemByIndex(list, 1), "Hello") == 0 &&
						   strcmp(StringListGetItemByIndex(list, 2), "Welcome") == 0 &&
						   strcmp(StringListGetItemByIndex(list, 3), "Hallo") == 0 &&
						   strcmp(StringListGetItemByIndex(list, 4), "Gracias") == 0 &&
						   strcmp(StringListGetItemByIndex(list, 5), "Hallo") == 0, L"List elements must coincide the added ones");
		}
		
		
		TEST_METHOD(SLRemoveTest1)
		{
			StringListAdd(list, "Hi");
			StringListAdd(list, "Hello");
			
			StringListRemove(list, "Hi");
			StringListRemove(list, "Hello");
			
			Assert::IsTrue(StringListSize(list) == 0, L"Must remove all elements of the list");
		}

		TEST_METHOD(SLRemoveTest2)
		{
			StringListAdd(list, "Hi");
			StringListAdd(list, "Hello");

			StringListRemove(list, "Hi");

			Assert::IsTrue(StringListSize(list) == 1, L"First element must be removed properly");
		}

		TEST_METHOD(SLRemoveTest3)
		{
			StringListAdd(list, "Hi");
			StringListAdd(list, "Hello");
			StringListAdd(list, "Welcome");
			StringListAdd(list, "Hallo");
			StringListAdd(list, "Gracias");
			StringListAdd(list, "Hallo");

			StringListRemove(list, "Hallo");
			StringListRemove(list, "Gracias");

			Assert::IsTrue(StringListSize(list) == 3, L"3 elements must be left");
		}

		TEST_METHOD(SLIngexOfTest1)
		{
			StringListAdd(list, "Hi");

			Assert::IsTrue(StringListIndexOf(list, "Hi") == 0,
				L"The returned index must be 0");
		}

		TEST_METHOD(SLIngexOfTest2)
		{
			StringListAdd(list, "Hi");
			StringListAdd(list, "Hello");

			Assert::IsTrue(StringListIndexOf(list, "Hello") == 1,
				L"The returned index must be 1");
		}

		TEST_METHOD(SLRemoveDuplicatesTest1)
		{
			StringListAdd(list, "Hi");
			StringListAdd(list, "Hi");
			StringListAdd(list, "Hi");
			StringListAdd(list, "Hi");
			StringListAdd(list, "Hi");

			StringListRemoveDuplicates(list);
			
			Assert::IsTrue(StringListSize(list) == 1,
				L"The size must be 1");
		}

		TEST_METHOD(SLRemoveDuplicatesTest2)
		{
			StringListAdd(list, "Hi");
			StringListAdd(list, "Hello");
			StringListAdd(list, "Hi");
			StringListAdd(list, "Hello");
			StringListAdd(list, "Hello");

			StringListRemoveDuplicates(list);

			Assert::IsTrue(StringListSize(list) == 2,
				L"The size must be 2");
		}

		TEST_METHOD(SLRemoveDuplicatesTest3)
		{
			StringListAdd(list, "a");
			StringListAdd(list, "b");
			StringListAdd(list, "c");
			StringListAdd(list, "d");
			StringListAdd(list, "e");

			StringListRemoveDuplicates(list);

			Assert::IsTrue(StringListSize(list) == 5,
				L"The size must be 5");
		}

		TEST_METHOD(SLReplaceInStringsTest1)
		{
			StringListAdd(list, "Hi");
			StringListAdd(list, "Hello");
			StringListAdd(list, "Hi");
			StringListAdd(list, "Hello");
			StringListAdd(list, "Hello");

			StringListReplaceInStrings(list, "Hi", "H");
			StringListReplaceInStrings(list, "Hello", "h");
			Assert::IsTrue(strcmp(StringListGetItemByIndex(list, 0), "H") == 0 &&
				strcmp(StringListGetItemByIndex(list, 1), "h") == 0 &&
				strcmp(StringListGetItemByIndex(list, 2), "H") == 0 &&
				strcmp(StringListGetItemByIndex(list, 3), "h") == 0 &&
				strcmp(StringListGetItemByIndex(list, 4), "h") == 0, L"1 and 3 elements must be \"H\" and others - \"h\"");
		}

		TEST_METHOD(SLSortTest1)
		{
			StringListAdd(list, "a");
			StringListAdd(list, "b");
			StringListAdd(list, "c");
			StringListAdd(list, "d");
			StringListAdd(list, "e");

			StringListSort(list);
			StringListPrint(list);
			Assert::IsTrue(strcmp(StringListGetItemByIndex(list, 0), "a") == 0 &&
				strcmp(StringListGetItemByIndex(list, 1), "b") == 0 &&
				strcmp(StringListGetItemByIndex(list, 2), "c") == 0 &&
				strcmp(StringListGetItemByIndex(list, 3), "d") == 0 &&
				strcmp(StringListGetItemByIndex(list, 4), "e") == 0, L"The list must not change after sorting");
			
		}
		TEST_METHOD(SLSortTest2)
		{
			StringListAdd(list, "e");
			StringListAdd(list, "d");
			StringListAdd(list, "c");
			StringListAdd(list, "b");
			StringListAdd(list, "a");

			StringListSort(list);
			StringListPrint(list);
			Assert::IsTrue(strcmp(StringListGetItemByIndex(list, 0), "a") == 0 &&
				strcmp(StringListGetItemByIndex(list, 1), "b") == 0 &&
				strcmp(StringListGetItemByIndex(list, 2), "c") == 0 &&
				strcmp(StringListGetItemByIndex(list, 3), "d") == 0 &&
				strcmp(StringListGetItemByIndex(list, 4), "e") == 0, L"The list must be sorted");

		}
		
	};
}