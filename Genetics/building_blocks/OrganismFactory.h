#pragma once

#include <memory>

#include "Organism.h"
#include "../utils/macros.h"

/**
 * @brief The OrganismFactory class is used to create Organisms
 */
class OrganismFactory
{
	SINGLETON(OrganismFactory)

public:
	/**
	 * @brief Creates an Organism with a populated genotype
	 * @param genus The genus of the organism
	 * @param species The species of the organism
	 * @param name The common name of the organism
	 * @param chromosomes The strand pairs that make up the Organism
	 * @return A unique_ptr to the created Organism
	 */
	std::unique_ptr<Organism> createOrganism(
		const string &genus,
		const string &species,
		const string &name,
		const std::vector<string[2]> &chromosomes);
};

