#pragma once
#include <vector>

#include "Gene.h"

using std::string;

class Organism
{
public:
	Organism(const string &genus, const string &species, const string &name);

	void addGene(const Gene &gene);

	void serveGene(Gene &g) const;

	string toString() const;

private:
	string _genus;
	string _species;
	string _name;

	std::vector<Gene> _genotype;
};

