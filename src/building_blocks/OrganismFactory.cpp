#include "OrganismFactory.h"
#include "ChromosomeFactory.h"
#include <ctime>
#include "gene/MasterGeneIndex.h"

shared_ptr<Organism> OrganismFactory::createOrganism(
		const string &genus,
		const string &species,
		const string &name,
		const ChromosomesStrands &chromosomes) {

	auto organism = make_shared<Organism>(genus, species, name);
	ChromosomeFactory *factory = ChromosomeFactory::getInstance();

	for (auto &strandPair : chromosomes) {
		organism->addChromosome(factory->createChromosome(strandPair));
	}

	return organism;
}

shared_ptr<Organism> OrganismFactory::createOrganism(
		shared_ptr<Organism> parent1,
		shared_ptr<Organism> parent2,
		int &crossoverCount) {
	srand(time(nullptr));

	// TODO: Consider what happens when crossing different species.
	auto child = make_shared<Organism>(
			parent1->getGenus(),
			parent1->getSpecies(),
			parent1->getName()
	);
	auto factory = ChromosomeFactory::getInstance();

	// Create chromosomes for the child using ones from the parents.
	for (int i = 0; i < parent1->getChromosomeCount(); ++i) {
		child->addChromosome(factory->createChromosome(
				parent1->serveChromosome(),
				parent2->serveChromosome(),
				crossoverCount
		));
	}
    return child;
}
