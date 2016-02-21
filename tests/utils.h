#include <cstdio>
#include <functional>
#include <vector>
#include <fstream>
#include <sstream>

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
    if (!consoleOutput.good())
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
