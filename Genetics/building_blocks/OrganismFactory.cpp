#include "OrganismFactory.h"
#include "ChromosomeFactory.h"

std::unique_ptr<Organism> OrganismFactory::createOrganism(
		const string &genus,
		const string &species,
		const string &name,
		const std::vector<RawChromosome> &chromosomes) {

	std::unique_ptr<Organism> organism(new Organism(genus, species, name));

	ChromosomeFactory *factory = ChromosomeFactory::getInstance();

	for (auto &rc : chromosomes) {
		organism->addChromosome(factory->createChromosome(rc));
	}

	return std::move(organism);
}
