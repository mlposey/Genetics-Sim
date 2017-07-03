#include <gtest/gtest.h>
#include "core/gene/MasterGene.cpp"

// MasterGene.MasterGene should round negative crossover chances to zero
// and keep values which were already positive.
TEST(MasterGeneTest, forcePositiveCrossoverChance) {
    MasterGene negativeGene("","","",' ', ' ', -3.2);
    ASSERT_EQ(0, negativeGene.getCrossoverChance());

    MasterGene positiveGene("","","",' ', ' ', 2);
    ASSERT_EQ(2, positiveGene.getCrossoverChance());

    MasterGene zeroGene("","","",' ', ' ', -3.2);
    ASSERT_EQ(0, zeroGene.getCrossoverChance());
}

