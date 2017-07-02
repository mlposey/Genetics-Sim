#pragma once
#include "Gene.h"
#include "../../utils/macros.h"

/**
 * @brief GeneFactory is a singleton that creates Gene objects.
 *
 * This is the ideal method for creating Gene objects because it acquires a
 * reference to the MasterGene for you.
 * @see Gene
 */
class GeneFactory
{
	SINGLETON(GeneFactory)

public:
	/**
	 * @param allele1 A symbol for an allele
	 * @param allele2 A symbol for an allele
	 * @throws InvalidSymbolException
	 */
	Gene createGene(char allele1, char allele2);
};
