#include <gtest/gtest.h>
#include <utility>
#define name(FILENAME, EXISTS) std::make_pair(FILENAME, EXISTS)

#include <vector>
#include <fstream>

#include "../Genetics/GeneticsSimDataParser.cpp"
#include "../Genetics/ColemanXMLParser.cpp"

class ColemanXMLParserTests : public testing::Test {
public:
    // All the files to test
    std::vector<std::pair<const char*, bool/*exists*/>> fileNames;

    ColemanXMLParserTests() {
        fileNames = {
            name("GeneticsSim1.xml", true),
            name("NonexistantFile.xml", false),
            name("", false),
            name(".xml", false),
            name("32", false)
        };
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
