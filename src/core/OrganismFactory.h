#pragma once

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include "Organism.h"
#include "util/Macros.h"
#include "ChromosomeFactory.h"

/**
 * @brief OrganismFactory is the preferred method for creating Organisms
 *
 * Organism objects can be created in two ways:
 *  (1) Using gene information encoded as strings
 *  (2) Using two existing Organisms to create a new, random one
 *
 * @see Organism
 */
class OrganismFactory
{
    SINGLETON(OrganismFactory)

public:
    /**
     * @brief Creates an Organism using data from chromosome strands
     *
     * This method is ideal if loading information about an organism which
     * was already created.
     *
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
        const ChromosomesStrands &chromosomes);

    /**
     * @brief Creates an Organism that is an offspring of two parents
     *
     * This method is ideal if you want to create a new organism from two
     * existing ones.
     *
     * @param parent1 One parent of the future organism
     * @param parent2 One parent of the future organism
     * @param crossoverCount The number of times a crossover occurs when
     *  creating the new organism
     * @return A shared_ptr to the created Organism
     */
    shared_ptr<Organism> createOrganism(
            shared_ptr<Organism> parent1,
            shared_ptr<Organism> parent2);

    int getCrossoverCount() const { return _crossoverCount; }

private:
    // The number of times organism creation triggered chromosomal crossover
    int _crossoverCount = 0;
};

