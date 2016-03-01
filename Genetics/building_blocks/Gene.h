/*******************************************************************
*   Gene.h
*   CS 307 Programming Assignment 1
*   Author: Marcus Posey
*   Date Submitted: 02/23/2016
*
*   This program is entirely my own work.
*******************************************************************/
#pragma once
#include <string>
#include <vector>

#include "Allele.h"

/**
 * @brief The Gene class handles pairs of Allele.
 *
 * Gene holds a pair of Alleles that can be any combination of
 * dominant or recessive. It is immutable and allows the random
 * retrieval of copies of either of the stored Alleles.
 * @see Allele
 */
class Gene
{
public:
	/**
	 * @brief Constructs a Gene object
	 * @param a1 One allele to be part of the gene
	 * @param a2 One allele to be part of the gene
	 * @param desc The description of the gene trait
	 */
	Gene(const Allele &a1, const Allele &a2, const std::string &desc);

	/**
	 * @brief Picks a random Allele from the pair and returns it
	 * @return An Allele from the pair
	 */
	Allele getRandomAllele() const;

	/// @return The first of two alleles
	Allele first() const { return _alleles[0]; }

	/// @return The second of two alleles
	Allele second() const { return _alleles[1]; }

	std::string getDescription() const { return _description; }

	/**
	 * @brief Gets the phenotype of the Gene
	 *
	 * The phenotype represents the visible Allele trait.
	 * This should belong to the Allele that is dominant or default
	 * to one of the recessives which should share the trait.
	 * @return The phenotype of the Gene as a string
	 */
	std::string getPhenotype() const;

	/**
	 * @brief Gets the zygosity of the Gene
	 *
	 * The zygosity of the gene represents the commonality of its Alleles.
	 * It can be one of three values:
	 *     1.) heterozygous dominant
	 *     2.) homozygous recessive
	 *     3.) homozgyous dominant
	 * @return The zygosity of the Gene as a string
	 */
	std::string getZygosity() const;

	/// @return The allele pair of the gene as a string
	std::string getAllelesString() const { return _allelesString; }

	/// @return The fully qualified description of the gene
	std::string toString() const;

private:
	std::vector<Allele> _alleles; // The two alleles that make up the gene
	std::string _allelesString;   // A concatenation of the two allele chars
	std::string _description;     // A description of what the gene codes for
};
