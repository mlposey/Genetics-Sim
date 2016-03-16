#include <gtest/gtest.h>

#include "../Genetics/building_blocks/Chromosome.cpp"

class ChromosomeTests : public testing::Test {
public:
	Chromosome chromosome;

	ChromosomeTests() {
		Gene g(Allele('s', ""), Allele('S', ""), "");

		chromosome.addGene(g);
		chromosome.addGene(g);
	}
};

// ---------------------------------------------------------------------------
/*
 * The following set of tests assume the following behaviors:
 * 1.) If two iterators are in different locations in the Chromosome strand,
 *     they are not equal.
 * 2.) The converse of behavior 1 holds true.
 *
 * Deviation from the above should result in failed tests.
 */

TEST_F(ChromosomeTests, iteratorNotEqual_DifferentPosition) {
	// Get two iterators to the beginning of the chromosome
	auto iterator1 = chromosome.begin();
	auto iterator2 = chromosome.begin();

	// Advance the second one forward by one Gene
	iterator2++;

	// They are now in different positions
	ASSERT_TRUE(iterator1 != iterator2);
}

TEST_F(ChromosomeTests, iteratorNotEqual_BeginVsEnd) {
	// Get two iterators to the beginning and end of the chromosome
	auto iterator1 = chromosome.begin();
	auto iterator2 = chromosome.end();

	// They are in different positions
	ASSERT_TRUE(iterator1 != iterator2);
}

TEST_F(ChromosomeTests, iteratorNotEqual_SamePositions) {
	// Get two iterators to the beginning of the chromosome
	auto iterator1 = chromosome.begin();
	auto iterator2 = chromosome.begin();

	ASSERT_FALSE(iterator1 != iterator2);

	// Get two iterators to the end of the chromosome
	auto iterator3 = chromosome.end();
	auto iterator4 = chromosome.end();

	ASSERT_FALSE(iterator3 != iterator4);

	// The test fixture class put two genes in. Advance forward to the end
	iterator1++;
	iterator1++;

	// iterator1 should now also be at the end
	ASSERT_FALSE(iterator1 != iterator3);
}
// ---------------------------------------------------------------------------

/**
 * This test assumes that the * operator returns a character
 * representing an Allele
 *
 * Deviation from the above should result in a failed test.
 */
TEST_F(ChromosomeTests, iteratorDereference_CharReturn) {
	// Get an iterator to the first Gene element in the Chromosome
	auto iterator = chromosome.begin();

	char symbol = *iterator;

	// The symbol should be either an s or an S
	ASSERT_TRUE(symbol == 's' || symbol == 'S');
}

/**
 * This test assumes that the * operator throws a range_error exception if
 * called on an end iterator.
 *
 * Deviation from the above should result in a failed test.
 */
TEST_F(ChromosomeTests, iteratorDereference_EndIterator) {
	// Get an iterator to the first Gene element in the Chromosome
	auto iterator = chromosome.end();

	ASSERT_THROW(*iterator, std::range_error);
}
