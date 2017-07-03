#pragma once
#include <vector>

#include "Chromosome.h"

using std::string;

/**
 * @brief The Organism class represents a living thing
 *
 * The main purpose of the Organism is to store categorical information,
 * such as scientific name, as well as the genotype. New organisms should be
 * created with OrganismFactory.
 * @see Gene
 */
class Organism
{
public:
	/**
	 * @brief Constructs an Organism with an initial genus, species, and name
	 *
	 * The initial state is an Organism without Chromosomes. They can be added
	 * using ::addChromosome.
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
	 * @brief Retrieves the next Chromosome
	 *
	 * Repeated calls to ::serveChromosome will iterate through the Organism's list of
	 * Chromosomes. When the list has been fully traversed, the position returns to
	 * zero.
	 * @return the next chromosome in the organism's genotype
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
	int getChromosomeCount() const { return _chromosomes.size(); }

	/// Returns the Organism's collection of Chromosome objects
	const std::vector<Chromosome> &getChromosomes() const { return _chromosomes; }

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
