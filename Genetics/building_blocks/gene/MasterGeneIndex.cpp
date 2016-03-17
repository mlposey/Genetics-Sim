#include <algorithm>

#include "MasterGeneIndex.h"

MasterGeneIndex* MasterGeneIndex::getInstance() {
	static MasterGeneIndex *instance = new MasterGeneIndex();
	return instance;
}

void MasterGeneIndex::add(shared_ptr<MasterGene> master) {
	_masterGenes.push_back(master);
}

shared_ptr<MasterGene> MasterGeneIndex::get(const string& symbol) {
	for (auto &master : _masterGenes) {
		if (master->getDominantSymbol() == symbol ||
			master->getRecessiveSymbol() == symbol) {
			return master;
		}
	}
	return nullptr;
}
