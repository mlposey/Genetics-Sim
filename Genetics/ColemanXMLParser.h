#pragma once
#include "FileParser.h"

/**
 * The ColemanXMLParser class acts as a wrapper around Dr. Rick Coleman's
 * genetic xml format and parser.
 */
class ColemanXMLParser : public IFileParser
{
public:
	ColemanXMLParser();
	~ColemanXMLParser();

	/**
	 * Uses Coleman's parser to read genotype information from his xml format
	 *
	 * @param genotypes The vector to read the genotype from each organism into
	 * @param expectedCount The expected organism count in the data file
	 */
	void parseFile(std::vector<std::string>& genotypes,
		int expectedCount) override;
};

