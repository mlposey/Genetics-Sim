#include "ChromosomeFactory.h"
#include "gene/GeneFactory.h"
#include "gene/MasterGeneIndex.h"

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

Chromosome
ChromosomeFactory::createChromosome(Chromosome &a, Chromosome &b,
		bool &hasCrossoverOccurred) {
	Chromosome offspring;

	auto aIterator = a.begin();
	auto bIterator = b.begin();
	const unsigned long length = a.size();

    // Create the offspring's genes using those from its parents.
	for (unsigned long i = 0; i < length; ++i, ++aIterator, ++bIterator) {
		char a1 = aIterator->getRandomAllele();
		char a2 = bIterator->getRandomAllele();

		if (tryCrossover(a1, a, bIterator)) hasCrossoverOccurred = true;
		if (tryCrossover(a2, b, aIterator)) hasCrossoverOccurred = true;

		offspring.addGene(GeneFactory::getInstance()->createGene(a1, a2));
	}

    return offspring;
}

bool
ChromosomeFactory::tryCrossover(char &parent1Allele,
								Chromosome &parent1Chromosome,
								Chromosome::iterator &parent2It) {
	const double crossoverChance = MasterGeneIndex::getInstance()->
			get(parent1Allele)->getCrossoverChance();

	if (100 * ((double)rand() / (double)RAND_MAX) <= crossoverChance) {
		// Get the allele at the same spot on the other chromosome
		auto strand = parent1Chromosome.getStrand(parent1Allele);
		if (strand == Chromosome::Strand::STRAND1) {
			parent1Allele = parent2It->first();
		}
		else {
			parent1Allele = parent2It->second();
		}
		return true;
	}
	return false;
}
