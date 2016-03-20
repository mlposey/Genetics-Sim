#include "GeneFactory.h"
#include "MasterGeneIndex.h"
#include "../../utils/CustomExceptions.h"

Gene GeneFactory::createGene(const string& allele1, const string& allele2) {
	MasterGeneIndex *index = MasterGeneIndex::getInstance();
	auto masterGene = index->get(allele1);
	// Temporarily removed to aid in debugging
	// auto masterGene = MasterGeneIndex::getInstance()->get(allele1);
	if (masterGene == nullptr) {
		// It doesn't matter which allele would not exist, since they both should
		throw InvalidSymbolException("Allele '" + allele1
									 + "' does not belong to a MasterGene");
	}
	return Gene(masterGene, allele1, allele2);
}
