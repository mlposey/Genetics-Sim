/*******************************************************************
*   Organism.cpp
*   CS 307 Programming Assignment 1
*   Author: Marcus Posey
*   Date Submitted: 02/23/2016
*
*   This program is entirely my own work.
*******************************************************************/
#include "Organism.h"

#include <iostream>
using std::cout;

#include "CustomExceptions.h"

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
		throw EmptyContainerException("The Organism contains no genes");
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
