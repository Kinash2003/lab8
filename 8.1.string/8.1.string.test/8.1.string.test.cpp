#include "pch.h"
#include "CppUnitTest.h"
#include "../8.1.string/8.1.string.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My81stringtest
{
	TEST_CLASS(My81stringtest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string str = "123***";
			string functionResult = Change(str);
			("123!!", functionResult);
		}
	};
}
