#include <algorithm>

#include "MasterGeneIndex.h"
#include "../../../external/instructor_files/GeneticsSimDataParser.h"

MasterGeneIndex* MasterGeneIndex::getInstance() {
	static MasterGeneIndex *instance = new MasterGeneIndex();
	return instance;
}

shared_ptr<MasterGene> MasterGeneIndex::get(char symbol) {
	for (auto &master : _masterGenes) {
		if (master->getDominantSymbol() == symbol ||
			master->getRecessiveSymbol() == symbol) {
			return master;
		}
	}
	return nullptr;
}

void MasterGeneIndex::loadFromFile(const std::string &filename,
								   std::function<void(
										   shared_ptr<MasterGene>)> printer) {
	auto fileParser = GeneticsSimDataParser::getInstance();
	if (!fileParser->initDataFile(const_cast<char*>(filename.c_str()))) {
		throw std::ifstream::failure("Failed to open " + filename);
	}

	// Read each gene from the file parser, storing and printing them.
	for (int genesRemaining = fileParser->getGeneCount(); genesRemaining > 0;
			--genesRemaining) {
		// This length matches what is defined in GeneticsSimDataParser
		const int kMaxChar = 128;

		char
				trait[kMaxChar],
				domDesc[kMaxChar],
				recDesc[kMaxChar];
		char
				domSymbol,
				recSymbol;
		double crossoverChance;

		fileParser->getGeneData(trait, domDesc, &domSymbol, recDesc, &recSymbol,
								&crossoverChance);

		auto masterGene = make_shared<MasterGene>(string(trait), string(domDesc),
									  string(recDesc), domSymbol, recSymbol,
									  crossoverChance);

		_masterGenes.emplace_back(masterGene);
		printer(masterGene);
	}
}

void MasterGeneIndex::add(shared_ptr<MasterGene> gene) {
	_masterGenes.push_back(gene);
}
