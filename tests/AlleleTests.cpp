#include <gtest/gtest.h>
#include "../src/building_blocks/Allele.cpp"

// Allele.isDominant should identify uppercase symbols as dominant
// and lowercase symbols as recessive.
TEST(AlleleTest, isDominant) {
    Allele dominantAllele('T', "tall");
    ASSERT_TRUE(dominantAllele.isDominant());

    Allele recessiveAllele('t', "tall");
    ASSERT_FALSE(recessiveAllele.isDominant());
}
