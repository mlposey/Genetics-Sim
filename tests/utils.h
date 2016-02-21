/*******************************************************************
*   utils.h
*   CS 307 Programming Assignment 1
*   Author: Marcus Posey
*   Date Submitted: 02/23/2016
*
*   This program is entirely my own work.
*******************************************************************/
#include <cstdio>
#include <functional>
#include <vector>
#include <fstream>
#include <sstream>

/**
 * @brief Determines if correct data was printed to stdout
 *
 * This ensures that data printed to stdout by callback contains strings
 * which are contained in expectedOutputs. This is done by redirecting stdout
 * to a file and reading data from it. After data has been read, output is then
 * directed back to stdout and the temp file is deleted.
 *
 * @param callback This function should print data to stdout
 * @param expectedOutputs These are strings that should have been in the output
 * @return True if all expected data was printed. False otherwise
 */
inline bool compareOutput(const std::function<void(void)> &callback,
                   const std::vector<const char*> &expectedOutputs) {
    static void (*swap_)(FILE*, FILE*) = [](FILE *a, FILE *b) {
        FILE tmp;
        memcpy(&tmp, a, sizeof(FILE));
        memcpy(a, b, sizeof(FILE));
        memcpy(b, &tmp, sizeof(FILE));
    };

	const char *fn = "console_output.txt";

    FILE *tmp = fopen(fn, "w");
    swap_(stdout, tmp);
    callback();
    swap_(stdout, tmp);
    fclose(tmp);

    std::ifstream consoleOutput(fn);
    if (!consoleOutput.is_open())
        return false;

    std::stringstream ss;
    ss << consoleOutput.rdbuf();

    std::string contents = ss.str();

	consoleOutput.close();
	std::remove(fn);

    for (auto str : expectedOutputs) {
        if (contents.find(str) == -1)
            return false;
    }
    return true;
}
