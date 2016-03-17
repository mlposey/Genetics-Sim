/*******************************************************************
*   Organism.h
*   CS 307 Programming Assignment 1
*   Author: Marcus Posey
*   Date Submitted: 02/23/2016
*
*   This program is entirely my own work.
*******************************************************************/
#pragma once
#include <vector>

#include "gene/Gene.h"
#include "Chromosome.h"

using std::string;

/**
 * @brief The Organism class represents a living thing
 *
 * The main purpose of the Organism is to store categorical information,
 * such as scientific name, as well as the genotype. New organisms can be
 * created through use of the LoveChamber class and two parent organisms.
 * @see Gene, LoveChamber
 */
class Organism
{
public:
	/**
	 * @brief Constructs an Organism with an initial genus, species, name, and blank genotype
	 *
	 * As the initial state of the Organism is one without a genotype, it is
	 * necessary that ::addGene is used to assign the Organism some genotype
	 * which then makes it elligble to mate with other organisms.
	 * @param genus the genus of the organism
	 * @param species the species of the organism
	 * @param name the common name of the organism
	 */
	Organism(const string &genus, const string &species, const string &name);

	/**
	 * Adds a gene to the Organism's genotype
	 * @param gene a constant reference to a Gene to be added to the genotype
	 */
	void addGene(const Gene &gene);

	/**
	 * @brief Retrieves the next Gene in the genotype
	 *
	 * Repeated calls to ::serveGene will iterate through the Organism's list of
	 * Genes. When the list has been fully traversed, the position returns to
	 * zero.
	 * @return the next gene in the organism's genotype
	 */
	Gene &serveGene();

	/**
	 * @brief Prints a full description of the Organism to stdout
	 *
	 * Prints the genus, species, and common name of the organism, as well as
	 * the contents of the organism's genotype
	 */
	void printDescription() const;

	/// Returns the number of Genes in the Organism's genotype
	int getGeneCount() const { return _genotype.size(); }

	/// Returns a const reference to the Organism's genotype
	const std::vector<Gene> &getGenotype() const { return _genotype; };

	/// Returns the genus of the the Organism as a string
	string getGenus() const { return _genus; }

	/// Returns the species of the Organism as a string
	string getSpecies() const { return _species; }

	/// Returns the common name of the organism as a string
	string getName() const { return _name; }

private:
	int _serveCounter;

	string _genus;
	string _species;
	string _name;

	std::vector<Chromosome> _chromosomes;
};
