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

void Organism::serveGene(Gene& g) {
	if (_serveCounter >= _genotype.size()) {
		_serveCounter = 0;
	}
	g = _genotype[_serveCounter++];
}

string Organism::toString() const {
	return "";
}
