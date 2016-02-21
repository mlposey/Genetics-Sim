#include <gtest/gtest.h>
#include <fstream>
#include <cstdio>
#include <sstream>

#include "utils.h"

#include "../Genetics/LoveChamber.cpp"

class LoveChamberTests : public testing::Test {
public:
    Organism o1, o2;

    LoveChamberTests()
        : o1("Pisum", "Sativum", "Pea Plant")
        , o2(o1)
    {}
};

/**
 * This test expects the following behavior:
 * 1.) The constructor takes the organisms and prints to the screen both of
 *     their descriptions
 *
 * Deviation from the above should result in a failing test.
 */
TEST_F(LoveChamberTests, constructor) {
    // Even in the event that the organisms themselves cannot properly print
    // data, we still expect the LoveChamber to output this basic information.
    std::vector<const char*> expected;
    expected.push_back("\n-----------------------Parent Data-----------------\n");
    expected.push_back("Sim parent 1\n");
    expected.push_back("Sim parent 2\n");
    expected.push_back("---------------------------------------------------\n\n");

    ASSERT_TRUE(compareOutput([&](){ LoveChamber(o1, o2); }, expected));
}

/**
 * This test expects the following behavior:
 * 1.)
 *
 * Deviation from the above should result in a failed test.
 */
TEST_F(LoveChamberTests, mate) {

}
