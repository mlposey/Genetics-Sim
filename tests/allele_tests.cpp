#include <gtest/gtest.h>

#include "../Genetics/Allele.cpp"

class AlleleTests : public testing::Test {};

/**
 * This test assumes the following behavior:
 * 1.) Alleles with an uppercase symbol are dominant
 * 2.) Alleles with a lowercase symbol are not dominant
 *
 * Deviantion from the above should result in a failed test.
 */
TEST_F(AlleleTests, is_dominant) {
	Allele upper('T', "desc");
	ASSERT_TRUE(upper.isDominant());

	Allele lower('t', "desc");
	ASSERT_FALSE(lower.isDominant());
}