#include "LoveChamber.h"
#include "Organism.h"
#include <algorithm>
#include <ctime>

LoveChamber::LoveChamber(Organism& o1, Organism& o2)
	: _o1(o1)
	, _o2(o2) {
		srand(time(nullptr));
}

void LoveChamber::mate() {
	int size = _o1.getGeneCount();
	string offspringGenotype;

	Gene gene;
	string tmp;
	for (int i = 0; i < size; ++i) {
		_o1.serveGene(gene);
		tmp += gene.getRandomAllele().getSymbol();
		
		_o2.serveGene(gene);
		tmp += gene.getRandomAllele().getSymbol();

		std::sort(tmp.begin(), tmp.end());

		offspringGenotype += tmp + " ";
		tmp = "";
	}
	// chop off trailing space
	offspringGenotype = offspringGenotype.substr(0, offspringGenotype.size() - 1);

	notifyAll(offspringGenotype);
}
