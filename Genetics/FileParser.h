#include <vector>
#include <string>

/**
 * The IFileParser struct provides an interface for reading
 * genotype information from various file formats.
 */
struct IFileParser {
	virtual ~IFileParser() {}

	virtual void parseFile(std::vector<std::string>& genotypes,
		int expectedCount) = 0;
};