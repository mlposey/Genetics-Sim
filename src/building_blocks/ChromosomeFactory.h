#pragma once

#include "../utils/macros.h"
#include "Chromosome.h"

/**
 * @brief The ChromosomeFactory class creates Chromosome objects
 * @see Chromosome
 */
class ChromosomeFactory
{
	SINGLETON(ChromosomeFactory)

public:
	/**
	 * @brief Creates and returns a Chromosome object
	 * @param rc A RawChromosome containing basic strand information
	 * @return A chromosome object containing information from rc
	 */
	Chromosome createChromosome(const RawChromosome &rc) const;
};
