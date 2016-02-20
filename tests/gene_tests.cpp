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

/**
 * This test assumes the following behavior:
 * 1.) The phenotype of a gene is the description of the dominant Allele
 *
 * Deviation from the above should result in a failed test.
 */
TEST_F(GeneTests, getPhenotype) {
	ASSERT_EQ("dominant description", gene.getPhenotype());
}


/**
 * This test assumes the following behavior:
 * The zygosity of a gene is:
 * 1.) "heterozygous dominant" if the Alleles do not match
 * 2.) "homozygous recessive" if both Alleles are recessive
 * 3.) "homozygous dominant" if both Alleles are dominant.
 *
 * Deviation from the above should result in a failed test.
 */
TEST_F(GeneTests, getZygosity) {
	Allele a1Copy(a1);
	Allele a2Copy(a2);

	Gene homozygousRecessive(a2, a2Copy, "desc");
	ASSERT_EQ("homozygous recessive", homozygousRecessive.getZygosity());

	Gene homozygousDominant(a1, a1Copy, "desc");
	ASSERT_EQ("homozygous dominant", homozygousDominant.getZygosity());

	// gene is declared in the class fixture as "Tt"
	ASSERT_EQ("heterozygous dominant", gene.getZygosity());
}