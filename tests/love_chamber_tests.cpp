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
    // Output console data here
    const char *consoleOutputFileName = "console_output.txt";

	FILE *file = fopen(consoleOutputFileName, "w");
    // LoveChamber::LoveChamber() should ouput the organism data to stdout
    // We are interested in if it was printed correctly, so we redirect stdout
    // to this file.
	swapOutput(stdout, file);

    LoveChamber chamber(o1, o2);

    // Close the file so we can examine it
	swapOutput(stdout, file);
	fclose(file);

    // Even in the event that the organisms themselves cannot properly print
    // data, we still expect the LoveChamber to output this basic information.
    const char* expectedInformation[] = {
        "\n-----------------------Parent Data-----------------\n",
        "Sim parent 1\n",
        // parent1.printDescription() should put information here
        "Sim parent 2\n",
        // parent2.printDescription() should put information here
        "---------------------------------------------------\n\n"
    };

    std::ifstream consoleOuputFile(consoleOutputFileName);
    ASSERT_TRUE(consoleOuputFile.is_open());

    std::stringstream ss;
    ss << consoleOuputFile.rdbuf();
    std::string fileContents = ss.str();

    // Check that each component of the expected output was printed
    for (auto str : expectedInformation) {
        ASSERT_TRUE(fileContents.find(str) != -1);
    }

    // Close and delete the file
    consoleOuputFile.close();
    std::remove(consoleOutputFileName);
}
