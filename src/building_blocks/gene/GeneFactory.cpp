#include "GeneFactory.h"
#include "MasterGeneIndex.h"
#include "../../utils/CustomExceptions.h"

Gene GeneFactory::createGene(char allele1, char allele2) {
	auto masterGene = MasterGeneIndex::getInstance()->get(allele1);
	if (masterGene == nullptr) {
		// It doesn't matter which allele would not exist, since they both should
		throw InvalidSymbolException("Allele '" + string() += allele1
									 + "' does not belong to a MasterGene");
	}
	return Gene(masterGene, allele1, allele2);
}
