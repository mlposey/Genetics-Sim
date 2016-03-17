#include "GeneFactory.h"
#include "MasterGeneIndex.h"
#include "../../utils/CustomExceptions.h"

GeneFactory* GeneFactory::getInstance() {
	static GeneFactory *instance = new GeneFactory();
	return instance;
}

Gene GeneFactory::createGene(const string& allele1, const string& allele2) {
	auto masterGene = MasterGeneIndex::getInstance()->get(allele1);
	if (masterGene == nullptr) {
		// It doesn't matter which allele would not exist, since they both should
		throw InvalidSymbolException(allele1 + " does not belong to a MasterGene");
	}
	return Gene(masterGene, allele1, allele2);
}
