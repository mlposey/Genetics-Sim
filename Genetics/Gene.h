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
	 */
	Gene(const Allele &a1, const Allele &a2);

	/**
	 * @brief Picks a random Allele from the pair and returns it
	 * @return An Allele from the pair
	 */
	Allele getRandomAllele() const;

	/// @return The first of two alleles
	Allele first() const { return _alleles[0]; }

	/// @return The second of two alleles
	Allele second() const { return _alleles[1]; }

	/// @return The allele pair of the gene as a string
	std::string toString() const;

private:
	std::vector<Allele> _alleles;
};

