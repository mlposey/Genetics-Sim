#include "ColemanXMLParser.h"
#include <unordered_map>
#include <utility>

#include "Allele.h"

ColemanXMLParser::ColemanXMLParser(const std::string &filename)
	: _parser(const_cast<char*>(filename.c_str()))
{
}

// TODO: Verify that expectedCount should always be 2 for ColemanXML
void ColemanXMLParser::parseFile(std::vector<Organism> &organisms,
								 int expectedCount) {

	string genus(_parser.getGenus());
	string species(_parser.getSpecies());
	string name(_parser.getCommonName());

	organisms.emplace_back(genus, species, name);
	organisms.emplace_back(genus, species, name);


	char domSymbol;  // dominant allele symbol
	char recSymbol;  // recessive allele symbol

	const int WIDTH = 128; // max length of a trait or description
	char trait[WIDTH];     // name of the the trait
	char domDesc[WIDTH];   // description of the dominant allele
	char recDesc[WIDTH];   // description of the recessive allele

	// All possible alleles that a parent may have
	// The key is the symbol of the allele
	// The pair holds the allele and it's gene trait description
	// e.g. <'t', <Allele(), Color>>
	std::unordered_map<char, std::pair<Allele, string>> possibleAlleles;

	// Survey the file to find all possible alleles that a parent may have
	while (_parser.getGeneData(trait, domDesc, &domSymbol, recDesc, &recSymbol)) {
		possibleAlleles[domSymbol] = std::make_pair<Allele, string>(Allele(domSymbol, domDesc), trait);
		possibleAlleles[recSymbol] = std::make_pair<Allele, string>(Allele(recSymbol, recDesc), trait);
	}

	// TODO: Please fix this algorithm... It works. It's just bad. So bad...

	char genotype[2][32];
	Allele al[2];
	int t = 0;
	// Load the genotype of each parent into the appropriate parent organisms
	for (int i = 0; i < 2; ++i) {
		_parser.getParentGenotype(genotype[i]);
		int genLength = strlen(genotype[i]);
		for (int j = 0; j < genLength; ++j) {
			char c = genotype[i][j];
			if (c == ' ' || j + 1 == genLength) {
				if (j + 1 == genLength) {
					al[t++] = possibleAlleles[c].first;
				}
				organisms[i].addGene(Gene(al[0], al[1], possibleAlleles[al[0].getSymbol()].second));
				t = 0;
				continue;
			}
			al[t++] = possibleAlleles[c].first;
		}
	}

}
