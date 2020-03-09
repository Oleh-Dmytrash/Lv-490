#include "stdafx.h"
#include "CppUnitTest.h"
#include"C:\Users\Dell\source\repos\Task1\Task1\list.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace Unit_test_task1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		char*** list=NULL;

		TEST_METHOD_INITIALIZE(StringInit)
		{
			list = (char***)malloc(sizeof(char*));
			StringListInit(list);
		}
		TEST_METHOD_CLEANUP(StringDestroy)
		{
			StringListDestroy(list);
		}
		////////////////////////////////////////////////
		TEST_METHOD(StrInit)//if list1=NULL nothing happened
		{
			char*** list1 = NULL;
			StringListInit(list1);
			Assert::IsTrue(list1==NULL);
		}
		/////StrInit//test//done/////////////////
		TEST_METHOD(StrDestroy)//if list=NULL nothing happened
		{
			char*** list1 = NULL;
			StringListDestroy(list1);
			Assert::IsTrue(list1 == NULL);			
		}
		/////StrDestroy//test//done/////////////////
		TEST_METHOD(StrAdd0)//0 nodes+add(only initialized)
		{
			StringListAdd(*list, "smth");
			Assert::AreEqual(list[0][0], "smth");
		}
		TEST_METHOD(StrAdd1)//1 node+add
		{
			StringListAdd(*list, "smth");//first
			StringListAdd(*list, "smth1");//testing
			Assert::AreEqual(((char**)(list[0][1]))[0], "smth1");
		}
		/////StrAdd//tests//done/////////////////

		TEST_METHOD(StringListRemoveTest1)//one node
		{		
			StringListAdd(*list, "hi");
			StringListRemove(*list, "hi");
			Assert::AreEqual(list[0][0],NULL);
		}

		TEST_METHOD(StringListRemoveTest2)//removing 2 nodes
		{
			StringListAdd(*list, "hi");
			StringListAdd(*list, "hi1");
			StringListAdd(*list, "hi1");
			StringListRemove(*list, "hi1");
			Assert::AreEqual(list[0][0], "hi");
		}
		/////StrRemove//tests//done/////////////////

		TEST_METHOD(StrSize0)//testing after initilizing(should return 0 as empty data)
		{
			Assert::AreEqual(StringListSize(*list),0);
		}
		TEST_METHOD(StrSize2)//testing 2 nodes
		{
			StringListAdd(*list, "hi");
			StringListAdd(*list, "hi1");
			Assert::AreEqual(StringListSize(*list), 2);
		}
		/////StrSize//tests//done/////////////////

		TEST_METHOD(StrIndexOf0)//cheak for invalid input
		{
			StringListAdd(*list, "hi");
			Assert::AreEqual(StringListIndexOf(*list, NULL),-1);
		}

		TEST_METHOD(StrIndexOf1)//cheak for 1 node
		{
			StringListAdd(*list, "hi");
			Assert::AreEqual(StringListIndexOf(*list,"hi"), 0);
		}
		TEST_METHOD(StrIndexOf3)//cheak for 3 nodes
		{
			StringListAdd(*list, "hi");
			StringListAdd(*list, "hi1");
			StringListAdd(*list, "hi2");
			Assert::AreEqual(StringListIndexOf(*list, "hi1"), 1);
		}
		/////StrIndexOf//tests//done/////////////////
		TEST_METHOD(StrRemoveDup1)//cheak invalid arguments(1 not enought for using this func)
		{			
			StringListAdd(*list, "hi");
			StringListRemoveDuplicates(*list);
			Assert::AreEqual(StringListSize(*list),1);
		}
		TEST_METHOD(StrRemoveDup2)//cheak for 2 nodes
		{
			StringListAdd(*list, "hi");
			StringListAdd(*list, "hi");
			StringListRemoveDuplicates(*list);
			Assert::AreEqual(StringListSize(*list), 1);
		}
		TEST_METHOD(StrRemoveDup3)//cheak for 4 nodes(multi duplicates)
		{
			StringListAdd(*list, "hi");
			StringListAdd(*list, "hi");
			StringListAdd(*list, "hi1");
			StringListAdd(*list, "hi");
			StringListRemoveDuplicates(*list);
			Assert::AreEqual(StringListSize(*list), 2);
		}
		/////StrRemoveDuplicates//tests//done/////////////////
		
			TEST_METHOD(StrReplace0)//cheak for invalid parameter
		{
			StringListAdd(*list, "hi");
			StringListAdd(*list, "hi");
			StringListAdd(*list, "hi1");
			StringListReplaceInStrings(*list,NULL,"hi");
			Assert::AreEqual(list[0][0],"hi");			
		}
		TEST_METHOD(StrReplace1)//cheak for 1 replacing
		{
			StringListAdd(*list, "hi");
			StringListAdd(*list, "hi1");
			StringListReplaceInStrings(*list,"hi", "hi1");
			Assert::AreEqual(list[0][0], "hi1");
		}
		TEST_METHOD(StrReplace3)//cheak for multi replacing
		{
			StringListAdd(*list, "hi");
			StringListAdd(*list, "hi1");
			StringListAdd(*list, "hi");
			StringListAdd(*list, "hi");
			StringListReplaceInStrings(*list, "hi", "hi1");
			char**second_node = (char**)list[0][1];
			char**third_node = (char**)second_node[1];
			char**fourth_node = (char**)third_node[1];
			Assert::IsTrue(strcmp(list[0][0],"hi1")==0
					  &&strcmp(third_node[0],"hi1")==0
					  &&strcmp(fourth_node[0],"hi1")==0);
		}
		/////StrReplace//tests//done/////////////////
		
		TEST_METHOD(StrSort0)//cheak for invalid
		{
			StringListSort(NULL);
			Assert::IsTrue(list[0][0] == NULL);
		}
		TEST_METHOD(StrSort2)//cheak for 1 sorting 
		{
			StringListAdd(*list, "hi1");
			StringListAdd(*list, "hi");
			StringListSort(*list);
			Assert::IsTrue(strcmp(list[0][0], "hi") == 0
				&& strcmp(((char**)list[0][1])[0], "hi1") == 0);
		}
		TEST_METHOD(StrSort4)//cheak for multi sorting 
		{
			StringListAdd(*list, "hi1");
			StringListAdd(*list, "hi");
			StringListAdd(*list, "hi");
			StringListAdd(*list, "hi1");
			StringListSort(*list);
			char**second_node = (char**)list[0][1];
			char**third_node = (char**)second_node[1];
			char**fourth_node = (char**)third_node[1];
			Assert::IsTrue(strcmp(list[0][0], "hi") == 0
				&& strcmp(second_node[0],"hi")==0
				&& strcmp(third_node[0], "hi1") == 0
				&& strcmp(fourth_node[0], "hi1") == 0);
		}
		/////StrSort//tests//done/////////////////


	};
}