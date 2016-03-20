#include "ChromosomeFactory.h"
#include "gene/GeneFactory.h"

Chromosome ChromosomeFactory::createChromosome(const RawChromosome &rc) const {
    // TODO: Figure out if all factories should return copies or pointers

    Chromosome chromosome;

    // The starting index of a token
    unsigned long pos = 0;

    // The starting index of a space
    unsigned long space = pos;

    string allele1, allele2;

    GeneFactory *factory = GeneFactory::getInstance();

    // Create genes using the pairs of alleles from the strands
    while ((space = rc.strand1.find(' ', pos)) != -1) {
        allele1 = rc.strand1.substr(pos, space);
        allele2 = rc.strand2.substr(pos, space);
        chromosome.addGene(factory->createGene(allele1, allele2));
        pos = space + 1;
    }

    return chromosome;
}
