/*******************************************************************
*   coleman_xml_parser_tests.cpp
*   CS 307 Programming Assignment 1
*   Author: Marcus Posey
*   Date Submitted: 02/23/2016
*
*   This program is entirely my own work.
*******************************************************************/
#include <gtest/gtest.h>

#include <vector>
#include <fstream>

#include "../Genetics/GeneticsSimDataParser.cpp"
#include "../Genetics/ColemanXMLParser.cpp"

class ColemanXMLParserTests : public testing::Test {
public:
	// Stores metadata about a file to test
	struct TestFile {
		TestFile(const char *n, bool e, bool m)
			: name(n), exists(e), isMalformed(m){}
		const char *name;
		bool exists;
		bool isMalformed;
	};

    // All the files to test
    std::vector<TestFile> testFiles;


// Sets up a file for testing with ColemanXMLParser
#define SETFILE(FILE_NAME, EXISTS, MALFORMED) \
	testFiles.emplace_back(FILE_NAME, EXISTS, MALFORMED);


    ColemanXMLParserTests() {
		// TODO: Read these from a file
		SETFILE("test_files/GeneticsSim1.xml", true, false);
		SETFILE("test_files/GeneticsSim2.xml", true, false);
		SETFILE("test_files/GeneticsSim3.xml", true, true);
		SETFILE("test_files/GeneticsSim4.xml", true, true);
		SETFILE("test_files/GeneticsSim5.xml", true, true);
		SETFILE("test_files/GeneticsSim6.xml", true, true);
		SETFILE("test_files/GeneticsSim7.xml", true, true);
		SETFILE("test_files/GeneticsSim8.xml", true, true);
	    SETFILE("NonexistantFile.xml", false, false);
	    SETFILE("", false, false);
	    SETFILE(".xml", false, false);
	    SETFILE("32", false, false);
    }
};

/**
 * This test expects the following behavior:
 * 1.) An exception is thrown if the filename provided is for a nonexistant file
 *
 * Deviation from the above should result in a failed test.
 */
TEST_F(ColemanXMLParserTests, constructor) {
    // Try to open each file in testFiles
    for (auto &file : testFiles) {
        bool isExceptionThrown = false;
        try {
            ColemanXMLParser parser(file.name);
        } catch (std::ifstream::failure &e) {
            isExceptionThrown = true;
        }

        if (!isExceptionThrown) {
            // The file should have existed
            ASSERT_TRUE(file.exists);
        }
        else {
            // The file should not have existed
            ASSERT_TRUE(!file.exists);
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
    for (auto &file : testFiles) {
        // The organisms found in the file
		std::vector<Organism> parents;
		bool caughtMalformedFile = false;
        try {
            ColemanXMLParser parser(file.name);

            parser.parseFile(parents);

            ASSERT_EQ(2, parents.size());

            // Check that the data was loaded into each parent
            for (auto &organism : parents) {
                ASSERT_FALSE(organism.getSpecies().empty());
                ASSERT_FALSE(organism.getGenus().empty());
                ASSERT_FALSE(organism.getName().empty());

                ASSERT_TRUE(organism.getGeneCount() > 0);
            }

        } catch (std::ifstream::failure &e) {
            // Okay, the file didn't exist
            ASSERT_TRUE(!file.exists);
        } catch (MalformedFileException &e) {
			// Make sure it was actually a bad file
			ASSERT_TRUE(file.isMalformed);
			caughtMalformedFile = true;
        }
		// Make sure malformed files didn't avoid detection
		ASSERT_EQ(caughtMalformedFile, file.isMalformed);
    }
}

// TODO: Write test for checking master gene output
