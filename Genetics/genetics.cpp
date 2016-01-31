#include "ColemanXMLParser.h"
#include "LoveChamber.h"
#include "StatCounter.h"

int main() {

	ColemanXMLParser parser("GeneticsSim1.xml");

	std::vector<Organism> parents;

	parser.parseFile(parents);

	LoveChamber loveChamber(parents[0], parents[1]);

	StatCounter counter;
	loveChamber.addObserver(counter);

	loveChamber.mate();

	return 0;
}
