#include "ChromosomeFactory.h"
#include "gene/GeneFactory.h"

Chromosome ChromosomeFactory::createChromosome(
		const std::pair<string,string> &chromesomeStrands) const {
    // TODO: Indicate problem if the strings aren't the same size.

    Chromosome chromosome;

    GeneFactory *factory = GeneFactory::getInstance();

    // Create genes using the pairs of alleles from the strands
	for (int i = 0; i < chromesomeStrands.first.size(); ++i) {
		if (chromesomeStrands.first[i] != ' ') {
			chromosome.addGene(factory->createGene(
					chromesomeStrands.first[i], chromesomeStrands.second[i]));
		}
	}

    return chromosome;
}
