#include "Organism.h"

#include <iostream>
#include "gene/MasterGeneIndex.h"
using std::cout;

#include "../utils/CustomExceptions.h"

Organism::Organism(const string& genus, const string& species, const string& name)
	: _serveCounter(0)
	, _genus(genus)
	, _species(species)
	, _name(name) {
}

void Organism::addChromosome(const Chromosome& c) {
	_chromosomes.push_back(c);
}

Chromosome &Organism::serveChromosome() {
	if (_chromosomes.size() == 0) {
		throw EmptyContainerException("The Organism contains no chromosomes");
	}

	if (_serveCounter >= _chromosomes.size()) {
		// All chromosomes have been served. Start over.
		_serveCounter = 0;
	}
	return _chromosomes[_serveCounter++];
}

void Organism::printDescription() const {
	std::cout << "\tOrganism genus-species: " << getGenus() << " "
			  << getSpecies() << '\n' << "\tChromosomes:\n";

	// Print the description of each chromosome in the organism
	for (int i = 0; i < _chromosomes.size(); ++i) {
		cout << "\t\tChromosome " << i + 1 << '\n';

		// Print the description of each gene of the chromosome
		for (auto &gene : _chromosomes[i]) {
			gene.printDescription();
		}
	}
}
