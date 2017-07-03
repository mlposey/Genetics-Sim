#pragma once

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include "Organism.h"
#include "../utils/macros.h"
#include "ChromosomeFactory.h"

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
	 * @return A shared_ptr to the created Organism
	 */
	shared_ptr<Organism> createOrganism(
		const string& genus,
		const string& species,
		const string& name,
		const ChromosomeStrands &chromosomes);

	/**
	 * @brief Creates an Organism with a populated genotype
	 * @param parent1 One parent of the future organism
	 * @param parent2 One parent of the future organism
	 * @param crossoverCount The number of times a crossover occurs
	 *        It is incremented on each occurrence
	 * @return A shared_ptr to the created Organism
	 */
	shared_ptr<Organism> createOrganism(
		shared_ptr<Organism> parent1,
		shared_ptr<Organism> parent2,
		int &crossoverCount);
};

