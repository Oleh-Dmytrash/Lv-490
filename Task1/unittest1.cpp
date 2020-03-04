#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "CppUnitTest.h"
#include "../string_list/Header.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ListUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
		char** list;
	public:
		BEGIN_TEST_METHOD_ATTRIBUTE(TestMethodAddList)
		TEST_OWNER( L"illya")
		TEST_PRIORITY(1)
		END_TEST_METHOD_ATTRIBUTE()
	
		TEST_METHOD_INITIALIZE(Initialize) {
			Logger::WriteMessage("initialize");
			StringListInit(&list);
		}
		TEST_METHOD_CLEANUP(Tear_down) {

			Logger::WriteMessage("destroy");
			StringListDestroy(&list);
		}


		



		TEST_METHOD(TestMethodAddList)
		{
			
			char str1[] = "bbb";
			char str2[] = "aaa";
			char str3[] = "ddd";
			StringListAdd(list, str1);
			StringListAdd(list, str2);
			StringListAdd(list, str3);
			int size = StringListSize(list);
			Assert::IsTrue(size == 3, L"list size must be 3");
			Logger::WriteMessage("in add");
			//Assert::AreEqual()
			// TODO: Разместите здесь код своего теста
		}

		TEST_METHOD(TestMethodStringListInitTWO) {
			StringListInit(&list);
			Logger::WriteMessage("in StringListInit");
			Assert::IsNotNull(list, L"StringListDestroy must be 0");
		}

		TEST_METHOD(TestMethodStringListIndexOf) {
			char str1[] = "bbb";
			char str2[] = "aaa";
			char str3[] = "ddd";
			StringListAdd(list, str1);
			StringListAdd(list, str2);
			StringListAdd(list, str3);
			char str_to_find[] = "aaa";
			int index = StringListIndexOf(list, str_to_find);
			Logger::WriteMessage("in index");
			Assert::IsTrue(index == 1, L"StringListIndexOf must be 1");
		
		}
	
		TEST_METHOD(TestMethodListReplaceInStrings) {
			char str1[] = "bbb";
			char str2[] = "aaa";
			char str3[] = "ddd";
			StringListAdd(list, str1);
			StringListAdd(list, str2);
			StringListAdd(list, str3);
			StringListAdd(list, str3);
			char to[] = "12345";
			StringListReplaceInStrings(list, str1, to);
			int index = StringListIndexOf(list, to);
			Logger::WriteMessage("in replace");
			Logger::WriteMessage(list[0]);
			Assert::IsTrue(index==0, L"StringListReplaceInStrings must be 0");
		}/*	*/

		
	
		TEST_METHOD(TestMethodStringListRemove) {
			char str1[] = "bbb";
			char str2[] = "aaa";
			char str3[] = "ddd";
			StringListAdd(list, str1);
			StringListAdd(list, str2);
			StringListAdd(list, str3);
			StringListRemove(list, str3);
			int index = StringListIndexOf(list, str1);
			Logger::WriteMessage("in StringListRemove");
			Assert::IsTrue(index == NULL, L"StringListRemove must be NULL");
		}
		TEST_METHOD(TestMethodStringListRemoveDuplicates) {
			char str1[] = "bbb";
			char str2[] = "aaa";
			char str3[] = "ddd";
			StringListAdd(list, str1);
			StringListAdd(list, str2);
			StringListAdd(list, str3);
			StringListAdd(list, str2);
			StringListRemoveDuplicates(list);
			int index = StringListSize(list);
			Logger::WriteMessage("in tryff");
			Assert::IsTrue(index == 3, L"tryff must be 3");
		}

		TEST_METHOD(TestMethodStringListSize) {
			char str1[] = "bbb";
			char str2[] = "aaa";
			char str3[] = "ddd";
			StringListAdd(list, str1);
			StringListAdd(list, str2);
			StringListAdd(list, str3);
			int size=StringListSize(list);
			Logger::WriteMessage("in StringListSize");
			Assert::AreEqual(size ,3, L"StringListSize must be NULL");
		}
		
		TEST_METHOD(TestMethodStringListSort) {

			Logger::WriteMessage("in StringListSort");
			char str1[] = "bbb";
			char str2[] = "aaa";
			char str3[] = "ddd";
			StringListAdd(list, str1);
			StringListAdd(list, str2);
			StringListAdd(list, str3);
			StringListSort(list);
			char **list2;
			StringListInit(&list2);
			StringListAdd(list2, str2);
			StringListAdd(list2, str1);
			StringListAdd(list2, str3);
			int idx1 = StringListIndexOf(list, str1);
			int idx2 = StringListIndexOf(list2, str1);
			int idx2_1 = StringListIndexOf(list, str2);
			int idx2_2 = StringListIndexOf(list2, str2);
			int idx3_1 = StringListIndexOf(list, str3);
			int idx3_2 = StringListIndexOf(list2, str3);
			StringListDestroy(&list2);
			bool expected = ((idx1 == idx2) && (idx2_1 == idx2_2) && (idx3_1 == idx3_2));
			Assert::IsTrue(expected, L"StringListSort must be true");
		}/*
*/
	};
}