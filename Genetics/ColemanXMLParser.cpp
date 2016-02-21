/*******************************************************************
*   ColemanXMLParser.cpp
*   CS 307 Programming Assignment 1
*   Author: Marcus Posey
*   Date Submitted: 02/23/2016
*
*   This program is entirely my own work.
*******************************************************************/
#include "ColemanXMLParser.h"
#include <unordered_map>
#include <utility>
#include <cstring>

#include "Allele.h"

ColemanXMLParser::ColemanXMLParser(const string &filename)
	: _parser(const_cast<char*>(filename.c_str()))
{
}

void ColemanXMLParser::parseFile(std::vector<Organism> &organisms) {
	organisms.emplace_back(_parser.getGenus(),
	                       _parser.getSpecies(),
						   _parser.getCommonName());

	// It can be assumed that both parents are the same
	// TODO: Determine if both parents will always be the same
	organisms.push_back(organisms[0]);


	char domSymbol;  // dominant allele symbol
	char recSymbol;  // recessive allele symbol

	const int WIDTH = 128; // max length of a trait or description
	char trait[WIDTH];     // name of the the trait
	char domDesc[WIDTH];   // description of the dominant allele
	char recDesc[WIDTH];   // description of the recessive allele

	// All possible alleles that a parent may have
	// The key is the symbol of the allele
	// The pair holds the allele and gene trait description
	std::unordered_map<char, std::pair<string, string>> possibleAlleles;

	// Survey the file to find all possible alleles that a parent may have
	while (_parser.getGeneData(trait, domDesc, &domSymbol, recDesc, &recSymbol)) {
		possibleAlleles[domSymbol] = std::make_pair<string, string>(domDesc, trait);
		possibleAlleles[recSymbol] = std::make_pair<string, string>(recDesc, trait);
	}

	char genotype[2][32];
	std::vector<Allele> alleles;

	// Load the genotype of each parent into the appropriate parent organisms
	for (int i = 0; i < 2; ++i) {
		_parser.getParentGenotype(genotype[i]);
		int genLength = strlen(genotype[i]);
		// Create alleles from each character and use pairs to create
		// genes to be added to the organism's genotype
		for (int j = 0; j < genLength + 1; ++j) {
			char c = genotype[i][j];
			if (alleles.size() == 2) {
				organisms[i].addGene(Gene(alleles[0], alleles[1],
					                 possibleAlleles[alleles[0].getSymbol()].second));
				alleles.clear();
				continue;
			}
			alleles.emplace_back(c, possibleAlleles[c].first);
		}
	}

}
