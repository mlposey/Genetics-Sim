#include "ColemanXMLParser.h"

int main() {
	std::vector<Organism> parents;
	ColemanXMLParser parser("GeneticsSim1.xml");
	parser.parseFile(parents);


	return 0;
}
