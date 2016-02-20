#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Genetics/Allele.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{		
	TEST_CLASS(AlleleTests)
	{
	public:
		
		/**
		 * In this method, we are testing that Alleles represented by an
		 * uppercase symbol are dominant. Lowercase symbols should
		 * represent recessive (not dominant).
		 */
		TEST_METHOD(testIsDominant)
		{
			const char *description = "some description";

			Allele upper('T', description);
			
			Assert::IsTrue(upper.isDominant());

			Allele lower('t', description);

			Assert::IsFalse(lower.isDominant());
		}

	};
}