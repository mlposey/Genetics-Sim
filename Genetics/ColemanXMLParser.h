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
 * @brief The ColemanXMLParser class wraps behavior of GeneticsSimDataParser
 *
 * This class acts as a wrapper around Dr. Coleman's GeneticsSimDataParser class.
 * It takes a filename which should contain organism data and then stores that
 * data in a supplied container.
 * @see GeneticsSimDataParser
 */
class ColemanXMLParser
{
public:
	explicit ColemanXMLParser(const string &filename);

	/**
	 * @brief Reads organism data from a file into a vector of organisms
	 *
	 * @param organisms The vector to store the organisms in
	 * @param expectedCount The expected organism count in the data file
	 * @see Organism
	 */
	void parseFile(std::vector<Organism>& organisms);

private:
	GeneticsSimDataParser _parser;
};
