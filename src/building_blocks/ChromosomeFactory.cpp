#include "ChromosomeFactory.h"
#include "gene/GeneFactory.h"

Chromosome ChromosomeFactory::createChromosome(const RawChromosome &rc) const {
    // TODO: Figure out if all factories should return copies or pointers

    Chromosome chromosome;

    GeneFactory *factory = GeneFactory::getInstance();

    // Create genes using the pairs of alleles from the strands
	for (int i = 0; i < rc.strand1.size(); ++i) {
		if (rc.strand1[i] != ' ') {
			chromosome.addGene(
				factory->createGene(rc.strand1[i], rc.strand2[i]));
		}
	}

    return chromosome;
}
