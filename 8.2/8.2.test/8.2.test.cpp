#include "pch.h"
#include "CppUnitTest.h"
#include "../8.2/8.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My82test
{
	TEST_CLASS(My82test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			string s = "a";
			t = MinLength(s);
			Assert::AreEqual(t, 2);
		}
	};
}
