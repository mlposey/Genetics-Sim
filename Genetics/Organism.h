#pragma once
#include <vector>

#include "Gene.h"

using std::string;

class Organism
{
public:
	Organism(const string &genus, const string &species, const string &name);

	void addGene(const Gene &gene);

	void serveGene(Gene &g);

	int getGeneCount() const { return _genotype.size(); }

	const std::vector<Gene> &getGenotype() const { return _genotype; };

	string getGenus() const { return _genus; }
	string getSpecies() const { return _species; }
	string getName() const { return _name; }

private:
	int _serveCounter;

	string _genus;
	string _species;
	string _name;

	std::vector<Gene> _genotype;
};

