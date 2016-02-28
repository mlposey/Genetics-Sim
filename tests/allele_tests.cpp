/*******************************************************************
*   allele_tests.cpp
*   CS 307 Programming Assignment 1
*   Author: Marcus Posey
*   Date Submitted: 02/23/2016
*
*   This program is entirely my own work.
*******************************************************************/
#include <gtest/gtest.h>

#include "../Genetics/building_blocks/Allele.cpp"

class AlleleTests : public testing::Test {};

/**
 * This test expects the following behavior:
 * 1.) Alleles with an uppercase symbol are dominant
 * 2.) Alleles with a lowercase symbol are not dominant
 *
 * Deviation from the above should result in a failed test.
 */
TEST_F(AlleleTests, isDominant) {
	Allele upper('T', "desc");
	ASSERT_TRUE(upper.isDominant());

	Allele lower('t', "desc");
	ASSERT_FALSE(lower.isDominant());
}
