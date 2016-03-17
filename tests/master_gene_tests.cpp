#include <gtest/gtest.h>

#include "../Genetics/building_blocks/MasterGene.cpp"

class MasterGeneTests : public testing::Test {};

/**
 * This test expects that supplying negative crossover chance results in
 * the field being set to zero.
 *
 * Deviation from the above should result in a failed test.
 */
TEST_F(MasterGeneTests, negativeCrossoverChance) {
	MasterGene gene("", "", "", "", "", -27.2);

	ASSERT_EQ(0, gene.getCrossoverChance());
}
