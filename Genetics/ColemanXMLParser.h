/*******************************************************************
*   ColemanXMLParser.h
*   CS 307 Programming Assignment 1
*   Author: Marcus Posey
*   Date Submitted: 02/23/2016
*
*   This program is entirely my own work.
*******************************************************************/
#pragma once
#include <string>

using std::string;

#include "GeneticsSimDataParser.h"
#include "Organism.h"

/**
 * @brief The ColemanXMLParser class acts as a wrapper around Dr. Rick Coleman's
 * genetic xml format and _parser.
 */
class ColemanXMLParser
{
public:
	explicit ColemanXMLParser(const string &filename);

	/**
	 * @brief Uses Coleman's _parser to read genotype information from his xml
	 * format
	 *
	 * @param organisms The vector to store the organisms in
	 * @param expectedCount The expected organism count in the data file
	 * @see Organism
	 */
	void parseFile(std::vector<Organism>& organisms);

private:
	GeneticsSimDataParser _parser;
};
