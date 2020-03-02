#include "pch.h"
#include "CppUnitTest.h"
#include "../Unit_Test_List/List.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLIist
{
	TEST_CLASS(UnitTestLIist)
	{
		char*** list = (char***)malloc(sizeof(char**));
	public:
		TEST_METHOD_INITIALIZE(Initialize)
		{
			Logger::WriteMessage("initialize");
			StringListInit(list);
		}

		TEST_METHOD_CLEANUP(Tear_down) {

			Logger::WriteMessage("destroy");
			StringListDestroy(list);
		}



		TEST_METHOD(ListAdd)
		{
			char str[] = "element";
			StringListAdd(*list, str);
			StringListAdd(*list, str);
			StringListAdd(*list, str);
			Assert::AreEqual(StringListSize(*list), 3);
		}
		TEST_METHOD(ListdDestroy)
		{
			char str[] = "element";
			StringListAdd(*list, str);
			StringListAdd(*list, str);
			Assert::AreEqual(StringListSize(*list), 2);
			StringListDestroy(list);
			Assert::IsTrue(*list == 0);
			StringListInit(list);
		}
		TEST_METHOD(ListSize)
		{
			char str[] = "element";
			char str1[] = "newstr";
			Assert::IsTrue(StringListSize(*list) == 0);
			StringListAdd(*list, str);
			Assert::IsTrue(StringListSize(*list) == 1);
			StringListAdd(*list, str);
			StringListAdd(*list, str1);
			StringListAdd(*list, str);
			Assert::IsTrue(StringListSize(*list) == 4);
			StringListDestroy(list);
			StringListInit(list);
			Assert::IsTrue(StringListSize(*list) == 0);


		}
		TEST_METHOD(ListRemove)
		{
			char str[] = "element";
			char str1[] = "newstr";
			StringListRemove(*list, str1);
			Assert::AreEqual(StringListSize(*list), 0);
			StringListAdd(*list, str);
			StringListAdd(*list, str);
			StringListAdd(*list, str1);
			StringListAdd(*list, str);
			Assert::AreEqual(StringListSize(*list), 4);
			StringListRemove(*list, str);
			Assert::AreEqual(StringListSize(*list), 1);
			StringListRemove(*list, str1);
			Assert::AreEqual(StringListSize(*list), 0);
			StringListRemove(*list, str);
			Assert::AreEqual(StringListSize(*list), 0);
		}
		TEST_METHOD(ListIndexOf) {
			char str[] = "element";
			char str1[] = "newstr";
			Assert::IsTrue(StringListIndexOf(*list, str1) == -1);
			StringListAdd(*list, str);
			StringListAdd(*list, str);
			StringListAdd(*list, str1);
			Assert::IsTrue(StringListIndexOf(*list, str1) == 2);
			Assert::IsTrue(StringListIndexOf(*list, str) == 0);
			StringListRemove(*list, str1);
			Assert::IsTrue(StringListIndexOf(*list, str1) == -1);
			StringListDestroy(list);
			StringListInit(list);
			Assert::IsTrue(StringListIndexOf(*list, str) == -1);
		}
		TEST_METHOD(ListRemoveDuplicates)
		{
			char str[] = "element";
			char str1[] = "newstr";
			StringListRemoveDuplicates(*list);
			Assert::AreEqual(StringListSize(*list), 0);
			StringListAdd(*list, str);
			StringListAdd(*list, str1);
			StringListAdd(*list, str1);
			StringListAdd(*list, str);
			Assert::AreEqual(StringListSize(*list), 4);
			StringListRemoveDuplicates(*list);
			Assert::AreEqual(StringListSize(*list), 2);
			Assert::AreEqual(StringListSize(*list), 2);
			StringListRemoveDuplicates(*list);
			StringListDestroy(list);
			StringListInit(list);
			Assert::AreEqual(StringListSize(*list), 0);
			StringListRemoveDuplicates(*list);
			Assert::AreEqual(StringListSize(*list), 0);
			StringListAdd(*list, str);
			StringListAdd(*list, str);
			StringListAdd(*list, str);
			StringListAdd(*list, str);
			StringListRemoveDuplicates(*list);
			Assert::AreEqual(StringListSize(*list), 1);
		}
		TEST_METHOD(ListReplaceInStrings)
		{
			char str[] = "element";
			char str1[] = "newstr";
			StringListReplaceInStrings(*list, str, str1);
			Assert::AreEqual(StringListSize(*list), 0);
			StringListAdd(*list, str);
			StringListAdd(*list, str);
			StringListAdd(*list, str1);
			StringListAdd(*list, str1);
			Assert::IsTrue(StringListIndexOf(*list, str1) == 2);
			StringListReplaceInStrings(*list, str, str1);
			Assert::IsTrue(StringListIndexOf(*list, str1) == 0);
			StringListRemove(*list, str1);
			Assert::IsTrue(StringListSize(*list) == 0);
			Assert::IsTrue(StringListIndexOf(*list, str1) == -1);
			StringListDestroy(list);
			StringListInit(list);
			StringListReplaceInStrings(*list, str1, str);
		}

		TEST_METHOD(ListSort)
		{
			char str[] = "aaaelement";
			char str1[] = "bbbnewstr";
			StringListAdd(*list, str1);
			StringListAdd(*list, str);
			StringListAdd(*list, str1);
			StringListAdd(*list, str);
			Assert::IsTrue(StringListIndexOf(*list, str) == 1);
			StringListSort(*list);
			Assert::IsTrue(StringListIndexOf(*list, str) == 0);
			StringListDestroy(list);
			StringListInit(list);
			StringListSort(*list);
		}



	};
}
