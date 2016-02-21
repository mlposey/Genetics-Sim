/*******************************************************************
*   coleman_xml_parser_tests.cpp
*   CS 307 Programming Assignment 1
*   Author: Marcus Posey
*   Date Submitted: 02/23/2016
*
*   This program is entirely my own work.
*******************************************************************/
#include <gtest/gtest.h>
#include <utility>

#include <vector>
#include <fstream>

#include "../Genetics/GeneticsSimDataParser.cpp"
#include "../Genetics/ColemanXMLParser.cpp"

class ColemanXMLParserTests : public testing::Test {
public:
    // All the files to test
    std::vector<std::pair<const char*, bool/*exists*/>> fileNames;

    ColemanXMLParserTests() {
		// This is ugly. Blame VS2012
	    fileNames.emplace_back("GeneticsSim1.xml", true);
	    fileNames.emplace_back("NonexistantFile.xml", false);
	    fileNames.emplace_back("", false);
	    fileNames.emplace_back(".xml", false);
	    fileNames.emplace_back("32", false);
    }
};

/**
 * This test expects the following behavior:
 * 1.) An exception is thrown if the filename provided is for a nonexistant file
 *
 * Deviation from the above should result in a failed test.
 */
TEST_F(ColemanXMLParserTests, constructor) {
    // Try to open each file in fileNames
    for (auto &fileName : fileNames) {
        bool isExceptionThrown = false;
        try {
            ColemanXMLParser parser(fileName.first);
        } catch (std::ifstream::failure &e) {
            isExceptionThrown = true;
        }

        if (!isExceptionThrown) {
            // The file should have existed
            ASSERT_TRUE(fileName.second);
        }
        else {
            // The file should not have existed
            ASSERT_TRUE(!fileName.second);
        }
    }
}

/**
 * This test expects the following behavior:
 * 1.) ::parseFile takes information for two organisms
 * 2.) ::parseFile ensures that both organisms have the same gene count
 * 3.) ::parseFile stores both organisms in the provided vector
 *
 * Deviation from the above should result in a failed test.
 */
TEST_F(ColemanXMLParserTests, parseFile) {
    for (auto &fileName : fileNames) {
        try {
            ColemanXMLParser parser(fileName.first);

            // The organisms found in the file
            std::vector<Organism> parents;
            parser.parseFile(parents);

            ASSERT_EQ(2, parents.size());

            // Check that the data was loaded into each parent
            for (auto &organism : parents) {
                ASSERT_FALSE(organism.getSpecies().empty());
                ASSERT_FALSE(organism.getGenus().empty());
                ASSERT_FALSE(organism.getName().empty());

                ASSERT_TRUE(organism.getGeneCount() > 0);
            }

            ASSERT_EQ(parents[0].getGeneCount(), parents[1].getGeneCount());

        } catch (std::ifstream::failure &e) {
            // Okay, the file didn't exist
            ASSERT_TRUE(!fileName.second);
        }
    }
}
