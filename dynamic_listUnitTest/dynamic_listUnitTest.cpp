#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include "../dynamyc_list/list.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace dynamiclistUnitTest
{
	TEST_CLASS(ListTest)
	{
	private:
		char** list;
	public:
		TEST_METHOD_INITIALIZE(TestInit)
		{
			StringListInit(&list);
		}

		TEST_METHOD_CLEANUP(TestDestroy)
		{
			StringListDestroy(&list);
		}

		TEST_METHOD(StringListAddTest)
		{
			char str[] = { "abcdefg" };						
			StringListAdd(list, str);
			Assert::AreEqual(list[0], str, L"Function StringListAdd not working correctly");
		}

		TEST_METHOD(StringListSizeTest1)
		{
			char str[] = { "abcdefg" };
			StringListAdd(list, str);
			StringListAdd(list, str);
			StringListAdd(list, str);
			Assert::AreEqual(StringListSize(list), 3, L"Function StringListSize not working correctly");
		}

		TEST_METHOD(StringListSizeTest2)
		{		
			Assert::AreEqual(StringListSize(list), 0, L"Function StringListSize not working correctly");
		}

		TEST_METHOD(StringListRemoveTest1)
		{
			char str[] = { "abcdefg" };
			StringListAdd(list, str);
			StringListAdd(list, str);
			StringListAdd(list, str);
			StringListRemove(list, str);
			Assert::IsNull(*list, L"Function StringListReomve not working correctly");
		}

		TEST_METHOD(StringListRemoveTest2)
		{
			char str[] = { "abcdefg" };
			StringListAdd(list, str);
			StringListAdd(list, str + 1);
			StringListAdd(list, str);
			StringListRemove(list, str);
			Assert::AreEqual(StringListSize(list), 1, L"Function StringListReomve not working correctly");
		}

		TEST_METHOD(StringListIndexOfTest)
		{
			char str[] = { "abcdefg" };
			StringListAdd(list, str);
			StringListAdd(list, str + 1);
			StringListAdd(list, str);
			Assert::AreEqual(StringListIndexOf(list, str + 1), 1, L"Function StringListIndexOf not working correctly");
		}

		TEST_METHOD(StringListRemoveDuplicatesTest)
		{
			char str[] = { "abcdefg" };
			StringListAdd(list, str + 5);
			StringListAdd(list, str + 1);
			StringListAdd(list, str);
			StringListAdd(list, str + 1);
			StringListAdd(list, str + 1);
			StringListAdd(list, str);
			StringListRemoveDuplicates(list);
			Assert::AreEqual(StringListSize(list), 3, L"Function StringListRemoveDuplicates not working correctly");
		}

		TEST_METHOD(StringListReplaceInStringsTest)
		{
			char str[] = { "abcdefg" };
			StringListAdd(list, str + 5);
			StringListAdd(list, str + 1);
			StringListAdd(list, str);
			StringListAdd(list, str + 1);
			StringListAdd(list, str + 1);
			StringListAdd(list, str);
			StringListReplaceInStrings(list, str + 5, str);
			StringListReplaceInStrings(list, str + 1, str);			
			Assert::AreEqual(StringListSize(list), 6, L"Function StringListReplaceInStrings not working correctly");
		}

		TEST_METHOD(StringListSortTest)
		{
			char str[] = { "abcdefg" };
			StringListAdd(list, str + 5);
			StringListAdd(list, str + 4);
			StringListAdd(list, str + 2);
			StringListAdd(list, str + 1);
			StringListAdd(list, str + 3);
			StringListAdd(list, str);
			StringListSort(list);
			std::vector <std::string> string_list1;
			std::vector <std::string> string_list2;
			for (int i = 0; i < StringListSize(list); ++i)
			{				
				string_list1.push_back(std::string(str + i));
								
				string_list2.push_back(std::string(ReadElem(&list, i)[0]));
			}			
			Assert::IsTrue(string_list1 == string_list2 , L"Function StringListSort not working correctly");
		}
	};
}
