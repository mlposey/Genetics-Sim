#pragma once
#include <vector>

#include "Chromosome.h"

using std::string;

/**
 * @brief Organism stores the genetic traits and structure of a living thing.
 *
 * Organism allows you to manipulate genetic data such as chromosomes, genes,
 * and alleles. Further, it categorizes this information in the form of common
 * and scientific names, etc. New organisms should be created with
 * OrganismFactory.
 *
 * @see Gene, OrganismFactory
 */
class Organism
{
public:
    /**
     * @brief Constructs an Organism with an initial genus, species, and name
     *
     * Newly-constructed Organisms have no Chromosomes. They can be added
     * with ::addChromosome.
     *
     * @param genus the genus of the organism
     * @param species the species of the organism
     * @param name the common name of the organism
     */
    Organism(const string &genus, const string &species, const string &name);


    /**
     * @brief Adds a Chromosome to the Organism's genetic makeup
     * @param c The chromosome to add
     */
    void addChromosome(const Chromosome &c);

    /**
     * @brief Retrieves the next unprocessed Chromosome
     *
     * Organisms are composed of many chromosomes. serveChromosome iterates
     * through them. After all chromosomes are processed, calling this method
     * will reset the position to the beginning.
     *
     * @return the next chromosome in the organism's genotype
     * @throws EmptyContainerException if the organism has no chromosomes
     */
    Chromosome &serveChromosome();

    /**
     * @brief Prints a full description of the Organism to stdout
     *
     * Prints the genus, species, and common name of the organism, as well as
     * the contents of the organism's genotype
     */
    void printDescription() const;

    /// Returns the number of Chromosomes in the Organism
    unsigned long getChromosomeCount() const { return _chromosomes.size(); }

    /// Returns the genus of the the Organism as a string
    string getGenus() const { return _genus; }

    /// Returns the species of the Organism as a string
    string getSpecies() const { return _species; }

    /// Returns the common name of the organism as a string
    string getName() const { return _name; }

private:
    // The position of the next Chromosome to serve from _chromosomes
    int _serveCounter;

    string _genus;
    string _species;
    string _name;

    // The collection of chromosomes that make up the Organism
    std::vector<Chromosome> _chromosomes;
};
