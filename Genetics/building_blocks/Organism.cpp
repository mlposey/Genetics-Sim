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
	// TODO
}
