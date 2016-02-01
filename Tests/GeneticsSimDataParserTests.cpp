#include "stdafx.h"
#include <string>
#include <cstdio>

#include "../Genetics/GeneticsSimDataParser.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(GeneticsSimDataParserTests)
	{
	public:
		
		TEST_METHOD(TestFunctionality)
		{
			const std::string filename("GeneticsSim1.xml");
			const int GENO_WIDTH = 32;

			char genotype[GENO_WIDTH];

			GeneticsSimDataParser parser(
				const_cast<char*>(filename.c_str()));

			parser.getParentGenotype(genotype);

			printf("%s\n", genotype);
		}

	};
}