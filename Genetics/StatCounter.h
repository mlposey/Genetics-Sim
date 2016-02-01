#pragma once
#include <unordered_map>
#include <utility>
#include <string>

using std::string;

#include "IObserver.h"

class Organism;
class Gene;

#define map std::unordered_map

class StatCounter : public IObserver<Organism>
{
public:
	void notify(const Organism &arg) override;

	void printStats();

private:
	/** A count of how many times each genotype occurs */
	map<string, int> _genotypeCounts;

	/** A count of how many times each gene occurs */
	map<string/*desc*/, map<string/*gene*/, int>> _geneCounts;
};
