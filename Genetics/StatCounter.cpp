#include "StatCounter.h"
#include <memory>


void StatCounter::notify(void* arg) {
	std::shared_ptr<string> tmp(reinterpret_cast<string*>(arg));
	if (_genotypeCounts.find(*tmp) == _genotypeCounts.end()) {
		_genotypeCounts[*tmp] = 0;
	}
	else {
		_genotypeCounts[*tmp]++;
	}
}

int StatCounter::count(const string& genotype) {
	return _genotypeCounts[genotype];
}
