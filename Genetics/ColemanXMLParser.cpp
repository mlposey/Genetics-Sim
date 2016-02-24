/*******************************************************************
*   ColemanXMLParser.cpp
*   CS 307 Programming Assignment 1
*   Author: Marcus Posey
*   Date Submitted: 02/23/2016
*
*   This program is entirely my own work.
*******************************************************************/
#include "ColemanXMLParser.h"
#include <cstring>
#include <algorithm>

#include "Allele.h"
#include "CustomExceptions.h"

ColemanXMLParser::ColemanXMLParser(const string &filename)
	: _parser(const_cast<char*>(filename.c_str()))
{
}

// TODO: Split this up
void ColemanXMLParser::parseFile(std::vector<Organism> &organisms) {
	organisms.emplace_back(_parser.getGenus(),
	                       _parser.getSpecies(),
						   _parser.getCommonName());

	// It can be assumed that both parents are the same
	// TODO: Determine if both parents will always be the same
	organisms.push_back(organisms[0]);

	// Keep a record of all Alleles the organisms can contain
	storeAlleles();

	char genotype[2][32];
	_parser.getParentGenotype(genotype[0]);
	_parser.getParentGenotype(genotype[1]);

	// Make sure there's nothing fishy about the genotypes of each parent
	verifyConformity(genotype[0], genotype[1]);

	// Keep alleles here until a pair can be formed
	std::vector<Allele> tmp;

	// Load the genotype of each parent into the appropriate parent organisms
	for (int i = 0; i < 2; ++i) {
		int genLength = strlen(genotype[i]);
		// Create alleles from each character and use pairs to create
		// genes to be added to the organism's genotype
		for (int j = 0; j < genLength + 1; ++j) {
			char c = genotype[i][j];
			if (tmp.size() == 2) {
				organisms[i].addGene(Gene(tmp[0], tmp[1],
					                 _alleles[tmp[0].getSymbol()].second));
				tmp.clear();
				continue;
			}
			tmp.emplace_back(c, _alleles[c].first);
		}
	}
}

void ColemanXMLParser::verifyConformity(char *genotypeA, char *genotypeB) {
	// If genotype[0] or genotype[1] equal "</GENOTYPE>", then either are missing
	// a genotype definition in the sim file

	if (strcmp(genotypeA, "</GENOTYPE>") == 0) {
		throw MalformedFileException("First parent in file is missing a genotype.");
	}

	if (strcmp(genotypeB, "</GENOTYPE>") == 0) {
		throw MalformedFileException("Second parent in file is missing a genotype.");
	}

	// The length of each genotype
	unsigned long length[] = {strlen(genotypeA), strlen(genotypeB)};


	if (isGenotypeMissingAlleles(length[0], genotypeA)) {
		throw MalformedFileException("First parent in file is missing an allele.");
	}

	if (isGenotypeMissingAlleles(length[1], genotypeB)) {
		throw MalformedFileException("Second parent in file is missing an allele.");
	}

	if (length[0] != length[1]) {
		throw MalformedFileException("Mismatched genotype counts in supplied file.");
	}
}

void ColemanXMLParser::storeAlleles() {
	char domSymbol;  // dominant allele symbol
	char recSymbol;  // recessive allele symbol

	const int WIDTH = 128; // max length of a trait or description
	char trait[WIDTH];     // name of the the trait
	char domDesc[WIDTH];   // description of the dominant allele
	char recDesc[WIDTH];   // description of the recessive allele

	std::cout << "\nMaster Genes: \n";

	// TODO: This creates some redundant data. It could get out of hand
	// Survey the file to find all possible alleles that a parent may have
	// and print the results
	while (_parser.getGeneData(trait, domDesc, &domSymbol, recDesc, &recSymbol)) {
		std::cout << "\tTrait Name: " << trait << '\n';
		std::cout << "\t\tDominant Name: " << domDesc << "(" << domSymbol << ")\n";
		std::cout << "\t\tRecessive Name: " << recDesc << "(" << recSymbol << ")\n";
		_alleles[domSymbol] = std::make_pair<string, string>(domDesc, trait);
		_alleles[recSymbol] = std::make_pair<string, string>(recDesc, trait);
	}
	std::cout << '\n';
}

bool ColemanXMLParser::isGenotypeMissingAlleles(int size, char *genotype) {
	for (int i = 0; i < size - 1; ++i) {
		if (genotype[i] == ' ' && genotype[i + 1] == ' ') {
			return true;
		}
		else if (i == size - 2 && genotype[i] == ' ' && genotype[i + 1] != ' ') {
			return true;
		}
	}
	return false;
}
