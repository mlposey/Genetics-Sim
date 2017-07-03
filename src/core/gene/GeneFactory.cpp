#include "GeneFactory.h"
#include "MasterGeneIndex.h"
#include "../../util/CustomExceptions.h"

Gene GeneFactory::createGene(char allele1, char allele2) {
    auto masterGene1 = MasterGeneIndex::getInstance()->get(allele1);
    auto masterGene2 = MasterGeneIndex::getInstance()->get(allele2);

    if (!masterGene1 || !masterGene2 || masterGene1 != masterGene2) {
        throw InvalidSymbolException(string("Invalid allele combination: ") +
            allele1 + " " + allele2);
    }

    Gene gene(masterGene1, allele1, allele2);
    notifyAll(gene);
    return gene;
}
