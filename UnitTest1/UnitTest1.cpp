#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.8/Lab_12.8.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = NULL,
				* last = NULL;
			for (int i = 0; i < 9; i++)
			{
				Enqueue(first, last, i);
			}
			Elem* L = first;
			for (int i = 0; i < 9; i++)
			{
				Assert::AreEqual(L->info, i);
				L = L->next;
			}
		}
	};
}
