#pragma once

#include "../utils/macros.h"
#include "Chromosome.h"

class ChromosomeFactory
{
	SINGLETON(ChromosomeFactory)

public:
	Chromosome createChromosome(const RawChromosome &rc) const;
};
