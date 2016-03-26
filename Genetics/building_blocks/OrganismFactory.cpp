#include "OrganismFactory.h"
#include "ChromosomeFactory.h"

shared_ptr<Organism> OrganismFactory::createOrganism(
		const string &genus,
		const string &species,
		const string &name,
		const std::vector<RawChromosome> &chromosomes) {

	auto organism = make_shared<Organism>(genus, species, name);

	ChromosomeFactory *factory = ChromosomeFactory::getInstance();

	// Turn the raw chromosomes into actual Chromosome objects
	for (auto &rc : chromosomes) {
		organism->addChromosome(factory->createChromosome(rc));
	}

	return organism;
}
