/*******************************************************************
*   gene_tests.cpp
*   CS 307 Programming Assignment 1
*   Author: Marcus Posey
*   Date Submitted: 02/23/2016
*
*   This program is entirely my own work.
*******************************************************************/
#include <gtest/gtest.h>
#include <string>

#include "../Genetics/Gene.cpp"

class GeneTests : public testing::Test {
public:
	Allele a1, a2;
	Gene mixedGene;     // "Tt"
	Gene recessiveGene; // "tt"
	Gene dominantGene;  // "TT"

	GeneTests()
		: a1('T', "dominant description")
		, a2('t', "recessive description")
		, mixedGene(a1, a2, "gene description")
		, recessiveGene(a2, a2, "gene description")
		, dominantGene(a1, a1, "gene description")
	{}
};

/**
 * This test expects the following behavior:
 * 1.) Gene::getRandomAllele returns a random Allele from the two stored
 *
 * Deviation from the above should result in a failed test.
 */
TEST_F(GeneTests, getRandomAllele) {
	/* Try this many times to get both alleles. If both are not retrieved
	   after this count, it can be assumed that the random function is not
	   suitable for this application--even if it is working correctly. */
	const int kTryCount = 1000;

	std::string alleleSymbols;
	bool isBothFound = false;  // Did we find both alleles?

	for (int i = 0; i < kTryCount; ++i) {
		if (alleleSymbols.size() == 2) {
			isBothFound = true;
			break;
		}
		char c = mixedGene.getRandomAllele().getSymbol();
		if (alleleSymbols.find(c) == -1) {
			alleleSymbols += c;
		}
	}

	ASSERT_TRUE(isBothFound);
}

/**
 * This test expects the following behavior:
 * 1.) The phenotype of a gene is the description of the dominant Allele
 *
 * Deviation from the above should result in a failed test.
 */
TEST_F(GeneTests, getPhenotype) {
	ASSERT_EQ("dominant description", mixedGene.getPhenotype());
}


/**
 * This test expects the following behavior:
 * The zygosity of a gene is:
 * 1.) "heterozygous dominant" if the Alleles do not match
 * 2.) "homozygous recessive" if both Alleles are recessive
 * 3.) "homozygous dominant" if both Alleles are dominant.
 *
 * Deviation from the above should result in a failed test.
 */
TEST_F(GeneTests, getZygosity) {
	ASSERT_EQ("homozygous recessive", recessiveGene.getZygosity());

	ASSERT_EQ("homozygous dominant", dominantGene.getZygosity());

	ASSERT_EQ("heterozygous dominant", mixedGene.getZygosity());
}

/**
 * This test expects the following behavior:
 * 1.) Gene::toString returns a concatenated string that consists of
 *     a) zygosity
 *     b) phenotype
 *     c) alleles as a string
 * ex.) "[zygosity] ([phenotype] [alleles])"
 *
 * Deviation from the above should result in a failed test.
 */
TEST_F(GeneTests, toString) {
	const char *expected[] = {
		"heterozygous dominant (dominant description Tt)",
		"homozygous recessive (recessive description tt)",
		"homozygous dominant (dominant description TT)"
	};

	ASSERT_STREQ(expected[0], mixedGene.toString().c_str());

	ASSERT_STREQ(expected[1], recessiveGene.toString().c_str());

	ASSERT_STREQ(expected[2], dominantGene.toString().c_str());
}
