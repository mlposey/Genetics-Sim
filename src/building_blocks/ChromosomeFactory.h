#pragma once

#include "../util/macros.h"
#include "Chromosome.h"

/**
 * @brief ChromosomeFactory creates Chromosome objects.
 *
 * @see Chromosome
 */
class ChromosomeFactory
{
	SINGLETON(ChromosomeFactory)

public:
	/**
	 * @param chromesomeStrands A pair of two strings which represent the first
	 * 	and second strand of a chromosome. The sizes of each string in the
	 * 	pair must match. If they do not, createChromosome will return a
	 * 	Chromosome object with no Genes.
	 *
	 * @return A chromosome object created from the strand information
	 */
	Chromosome createChromosome(const std::pair<string,string>
								&chromesomeStrands) const;

    /**
     * @brief Creates a new chromosome from two existing ones
     *
     * This is ideally used when creating an organism from two parents. Calls
     * to this method would consistently have the first argument be a chromosome
     * from the first parent and the second argument a chromosome from the
     * second parent.
     *
     * @param crossoverCount Chromosomal crossover is a process that can occur
     * 	when creating a new chromosome. This is set to true if crossover
     * 	happens during creation.
     */
    Chromosome createChromosome(Chromosome &a, Chromosome &b,
								bool &hasCrossoverOccurred);

private:
	/**
	 * @brief Attempts a chromosomal crossover
	 *
	 * @param parent1Allele An allele from the first parent
	 * @param parent1Chromosome The chromosome where the allele resides
	 * @param parent2It This should be aligned with the allele from parent1
	 * @return true if crossover occurred; false otherwise
	 */
	bool tryCrossover(char &parent1Allele,
					  Chromosome &parent1Chromosome,
					  Chromosome::iterator &parent2It);
};

// A collection of string pairs that represent the strands of chromosomes
using ChromosomesStrands = std::vector<std::pair<string,string>>;
