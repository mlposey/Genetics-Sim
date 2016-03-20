#pragma once
#include "Gene.h"
#include "../../utils/macros.h"

/**
 * @brief The GeneFactory class is a singleton that creates Gene objects
 * @see Gene
 */
class GeneFactory
{
	SINGLETON(GeneFactory)

public:
	/**
	 * @brief Creates a Gene object with the given symbols
	 * @param allele1 A symbol for an allele
	 * @param allele2 A symbol for an allele
	 * @return A Gene with the given symbols and associated MasterGene
	 * @throws InvalidSymbolException
	 */
	Gene createGene(const string &allele1, const string &allele2);
};
