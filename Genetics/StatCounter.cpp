#include "StatCounter.h"
#include <memory>
#include <iostream>


void StatCounter::notify(const string &arg) {
	if (_genotypeCounts.find(arg) == _genotypeCounts.end()) {
		_genotypeCounts[arg] = 1;
	}
	else {
		_genotypeCounts[arg]++;
	}
}

int StatCounter::count(const string& genotype) {
	return _genotypeCounts[genotype];
}

void StatCounter::printStats() {
	std::cout << "Genotype stats:\n";
	for (auto i : _genotypeCounts) {
		std::cout << i.first << " : " << i.second << '\n';
	}
}
