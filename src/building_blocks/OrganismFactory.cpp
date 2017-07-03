#include "OrganismFactory.h"
#include "ChromosomeFactory.h"
#include <ctime>
#include "gene/MasterGeneIndex.h"

shared_ptr<Organism> OrganismFactory::createOrganism(
		const string &genus,
		const string &species,
		const string &name,
		const ChromosomeStrands &chromosomes) {

	auto organism = make_shared<Organism>(genus, species, name);

	ChromosomeFactory *factory = ChromosomeFactory::getInstance();

	// Turn the raw chromosomes into actual Chromosome objects
	for (auto &rc : chromosomes) {
		organism->addChromosome(factory->createChromosome(rc));
	}

	return organism;
}

shared_ptr<Organism> OrganismFactory::createOrganism(
	shared_ptr<Organism> parent1,
	shared_ptr<Organism> parent2,
	int &crossoverCount) {

	ChromosomeStrands childChromosomes(parent1->getChromosomeCount());
	for (int i = 0; i < parent1->getChromosomeCount(); ++i) {
		auto& p1Chrom = parent1->serveChromosome();
		auto& p2Chrom = parent2->serveChromosome();

		// Acquire iterators to the collection of genes each chromosome has
		auto p1It = p1Chrom.begin();
		auto p2It = p2Chrom.begin();

		for (int j = 0; j < p1Chrom.size(); ++j , ++p1It , ++p2It) {
			// Get a random allele from each parent
			char a1 = p1It->getRandomAllele();
			char a2 = p2It->getRandomAllele();

			// Determine if each allele should have crossed over
			MasterGeneIndex* index = MasterGeneIndex::getInstance();
			srand(time(nullptr));

			int a1CrossoverChance = index->get(a1)->getCrossoverChance();
			if ((rand() % 101) > a1CrossoverChance) {
				// Get the allele at the same spot on the other chromosome
				auto strand = p1Chrom.getStrand(a1);
				if (strand == Chromosome::Strand::STRAND1) {
					a1 = p2It->first();
				}
				else {
					a1 = p2It->second();
				}
				++crossoverCount;
			}

			int a2CrossoverChance = index->get(a2)->getCrossoverChance();
			if ((rand() % 101) > a2CrossoverChance) {
				// Get the allele at the same spot on the other chromosome
				auto strand = p2Chrom.getStrand(a2);
				if (strand == Chromosome::Strand::STRAND1) {
					a2 = p1It->first();
				}
				else {
					a2 = p1It->second();
				}
				++crossoverCount;
			}

			childChromosomes[j].first += a1;
			childChromosomes[j].second += a2;

			// Add a trailing white space
			if (j + 1 != p1Chrom.size()) {
				childChromosomes[j].first += ' ';
				childChromosomes[j].second += ' ';
			}
		}
	}

		return createOrganism(
			parent1->getGenus(),
			parent1->getSpecies(),
			parent1->getName(),
			childChromosomes);
}
