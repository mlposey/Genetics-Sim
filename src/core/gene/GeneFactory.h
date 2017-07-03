#pragma once
#include "Gene.h"
#include "util/macros.h"
#include "sim/Observable.h"

/**
 * @brief GeneFactory is a singleton that creates Gene objects.
 *
 * This is the ideal method for creating Gene objects because it acquires a
 * reference to the MasterGene for you.
 * @see Gene
 */
class GeneFactory : public Observable<Gene>
{
    SINGLETON(GeneFactory)

public:
    /**
     * @brief Creates a Gene from alleles already loaded in a MasterGene
     *
     * The alleles must be of the same Gene type. Supplying alleles from
     * two different types of MasterGene is invalid. Further, the references
     * to the MasterGene are checked in MasterGeneIndex. Make sure the
     * MasterGene is stored there.
     *
     * @param allele1 A symbol for an allele
     * @param allele2 A symbol for an allele
     * @throws InvalidSymbolException
     */
    Gene createGene(char allele1, char allele2);
};
