#include "OrganismFactory.h"

std::unique_ptr<Organism> OrganismFactory::createOrganism(
		const string &genus,
		const string &species,
		const string &name,
		const string &strand1,
		const string &strand2) {

	std::unique_ptr<Organism> organism(new Organism(genus, species, name));

	// TODO: Use ChromosomeFactory to turn strands into chromosomes to add 
	return nullptr;
}
