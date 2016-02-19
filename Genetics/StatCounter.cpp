#include <iostream>
#include "StatCounter.h"
#include "Organism.h"

using std::cout;

void StatCounter::notify(const Organism &arg) {
	string genotype;
	for (const Gene &g : arg.getGenotype()) {
		genotype += g.getAllelesString() + " ";

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

void StatCounter::printStats() {
	cout << "\n-----------------------Results---------------------\n";

	for (auto &t : _geneCounts) {
		// Print the description of the gene (e.g., "flower color")
		cout << "Gene: " << t.first << '\n';

		// Print the count of the gene and the gene as a string
		for (auto &u : t.second) {
			cout << "\t" << u.second << " " << u.first << '\n';
		}
	}
	cout << "\n\n\n";
	cout << "All occuring genotypes and their counts:\n";

	// Print the occurring genotypes and how many offspring had each
	for (auto &p : _genotypeCounts) {
		cout << "\tGenotype = " << p.first << "\t";
		cout << "Offspring count = " << p.second << '\n';
	}

	cout << "\n---------------------------------------------------\n";
}
