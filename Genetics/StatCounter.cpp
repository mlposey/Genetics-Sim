#include "StatCounter.h"
#include <memory>


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
