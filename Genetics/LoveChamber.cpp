#include "LoveChamber.h"
#include "Organism.h"
#include <ctime>

LoveChamber::LoveChamber(Organism o1, Organism o2)
	: _o1(o1)
	, _o2(o2) {
		srand(time(nullptr));
}

void LoveChamber::mate() {
	int size = _o1.getGeneCount();

	Organism offspring(_o1.getGenus(), _o1.getSpecies(), _o1.getName());
	Gene gene;
	Allele al[2];
	string tmp;

	for (int i = 0; i < size; ++i) {
		_o1.serveGene(gene);
		al[0] = gene.getRandomAllele();
		
		_o2.serveGene(gene);
		al[1] = gene.getRandomAllele();

		offspring.addGene(Gene(al[0], al[1], gene.getDescription()));
	}

	notifyAll(offspring);
}
