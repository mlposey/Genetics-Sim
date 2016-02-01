#include <iostream>
#include "StatCounter.h"
#include "Organism.h"

void StatCounter::notify(const Organism &arg) {
	string genotype;
	for (const Gene &g : arg.getGenotype()) {
		genotype += g.allelesAsString() + " ";

		// Increment the count of each new gene occurance
		auto &tmp = _geneCounts[g.getDescription()];
		if (tmp.find(g.toString()) == tmp.end()) {
			tmp[g.toString()] = 1;
		}
		else {
			tmp[g.toString()]++;
		}
	}
	genotype = genotype.substr(0, genotype.size() - 1);
	// Increment the count of the new genotype occurance
	if (_genotypeCounts.find(genotype) == _genotypeCounts.end()) {
		_genotypeCounts[genotype] = 1;
	}
	else {
		_genotypeCounts[genotype]++;
	}
}

int StatCounter::count(const string& genotype) {
	return _genotypeCounts[genotype];
}

void StatCounter::printStats() {
	std::cout << "\n-----------------------Results---------------------\n";
	
	for (auto &t : _geneCounts) {
		std::cout << "Gene: " << t.first << '\n';
		for (auto &u : t.second) {
			std::cout << "\t" << u.second << " " << u.first << '\n';
		}
	}
	std::cout << "\n\n\n";
	std::cout << "All occuring genotypes and their counts:\n";

	for (auto &p : _genotypeCounts) {
		std::cout << "\tGenotype = " << p.first << "\t";
		std::cout << "Offspring count = " << p.second << '\n';
	}

	std::cout << "\n-----------------------Results---------------------\n";
}
