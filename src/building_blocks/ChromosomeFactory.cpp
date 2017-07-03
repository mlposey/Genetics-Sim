#include "ChromosomeFactory.h"
#include "gene/GeneFactory.h"

Chromosome ChromosomeFactory::createChromosome(
		const std::pair<string,string> &chromesomeStrands) const {
    Chromosome chromosome;

	if (chromesomeStrands.first.size() == chromesomeStrands.second.size()) {
		GeneFactory *factory = GeneFactory::getInstance();

		// Create genes using the pairs of alleles from the strands
		for (int i = 0; i < chromesomeStrands.first.size(); ++i) {
			if (chromesomeStrands.first[i] != ' ') {
				chromosome.addGene(factory->createGene(
						chromesomeStrands.first[i],
						chromesomeStrands.second[i]));
			}
		}
	}
    return chromosome;
}
