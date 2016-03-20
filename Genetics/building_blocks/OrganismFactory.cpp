#include "OrganismFactory.h"

std::unique_ptr<Organism> OrganismFactory::createOrganism(
		const string &genus,
		const string &species,
		const string &name,
		const std::vector<RawChromosome> &chromosomes) {

	std::unique_ptr<Organism> organism(new Organism(genus, species, name));

	// TODO: Use ChromosomeFactory to turn strands into chromosomes to add 
	return std::move(organism);
}
