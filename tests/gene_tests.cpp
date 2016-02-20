#include <gtest/gtest.h>

#include "../Genetics/Gene.cpp"

class GeneTests : public testing::Test {
public:
	Allele a1, a2;
	Gene gene;

	GeneTests()
		: a1('T', "dominant description")
		, a2('t', "recessive description")
		, gene(a1, a2, "gene description")
	{}
};

// TODO: Describe test's purpose
TEST_F(GeneTests, getPhenotype) {
	ASSERT_EQ("dominant description", gene.getPhenotype());
}