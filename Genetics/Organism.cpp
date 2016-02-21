#include "Organism.h"

#include <iostream>
using std::cout;

#include <exception>

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
	if (_genotype.size() == 0) {
		// TODO: Make a proper exception for cases like this
		throw std::exception();
	}
	
	if (_serveCounter >= _genotype.size()) {
		// All genes have been served. Start over.
		_serveCounter = 0;
	}
	return _genotype[_serveCounter++];
}

void Organism::printDescription() const {
	cout << "\tOrganism genus-species: " << _genus << " "
			  << _species << '\n';
	cout << "\tCommon name: " << _name << '\n';
	cout << "\tGenes: \n";

	for (const Gene &g : _genotype) {
		cout << "\t\tGene type = " << g.getDescription() << '\n';
		cout << "\t\t\tGenotype = " << g.getAllelesString() << '\n';
	}
}
