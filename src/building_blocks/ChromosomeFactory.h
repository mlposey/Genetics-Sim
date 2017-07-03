#pragma once

#include "../utils/macros.h"
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
	 * 	pair must match.
	 * @return A chromosome object created from the strand information
	 */
	Chromosome createChromosome(const std::pair<string,string>
								&chromesomeStrands) const;
};

// A collection of string pairs that represent the strands of chromosomes
using ChromosomeStrands = std::vector<std::pair<string,string>>;
