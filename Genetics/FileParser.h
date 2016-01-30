#include <vector>
#include <string>
#include "Organism.h"

/**
 * @brief The IFileParser struct provides an interface for reading
 * genotype information from various file formats.
 */
struct IFileParser {
	virtual ~IFileParser() {}

	virtual void parseFile(std::vector<Organism> &organisms,
		int expectedCount) = 0;
};