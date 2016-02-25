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
#include <unordered_map>
#include <utility>

using std::string;

#include "GeneticsSimDataParser.h"
#include "Organism.h"

// TODO: Maybe change the name of this to ColemanXMLInterpreter
//       see comment for _parser

// TODO: This class contains some functionality that could be common to all
//       file readers. Put that code in a base class and let this be a
//       generalization.

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
	/**
	 * @brief Verifies that the data conforms to format rules and standards
	 *
	 * The function checks for consistency errors in the file, such as mismatched
	 * genotype lengths. It also ensures that rules are being followed. For
	 * instance, it is illegal to have an Organism that is missing a genotype.
	 *
	 * @param genotypeA One parent genotype to check
	 * @param genotypeB One parent genotype to check
	 * @throws MalformedFileException
	 */
	void verifyConformity(char *genotypeA, char *genotypeB);

	/**
	 * @brief Stores information about each Allele found in the file
	 * @see Allele
	 */
	void storeAlleles();

	/// @return True if genotype is missing alleles
	static bool isGenotypeMissingAlleles(int size, char *genotype);

	// This retrieves the data from the file. We just interpret it
	GeneticsSimDataParser _parser;

	// This contains information about every Allele found in the file
	// The key is the symbol of the Allele
	// The pair holds the Allele and Gene trait description
	std::unordered_map<char, std::pair<string, string>> _alleles;
};
