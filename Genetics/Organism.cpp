#include "Organism.h"

Organism::Organism(const string& genus, const string& species, const string& name)
	: _serveCounter(0)
	, _genus(genus)
	, _species(species)
	, _name(name) {
}

void Organism::addGene(const Gene& gene) {
	_genotype.push_back(gene);
}

Gene &Organism::serveGene() {
	if (_serveCounter >= _genotype.size()) {
		_serveCounter = 0;
	}
	return _genotype[_serveCounter++];
}

