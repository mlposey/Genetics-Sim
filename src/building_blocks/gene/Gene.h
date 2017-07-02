#pragma once
#include <string>
using std::string;

#include <memory>

#include "MasterGene.h"

/**
 * @brief The Gene class handles pairs of Allele.
 *
 * Gene holds a pair of alleles that can be any combination of
 * dominant or recessive.
 */
class Gene
{
public:
	/**
	 * @brief Constructs a Gene object
	 * @param master A shared_ptr to the MasterGene
	 * @param a1 The symbol of one allele to be part of the gene pair
	 * @param a2 The symbol of one allele to be part of the gene pair
	 */
	Gene(std::shared_ptr<MasterGene> master, char a1, char a2);

	/**
	 * @brief Picks a random Allele from the pair and returns it
	 * @return An Allele from the pair
	 */
	char getRandomAllele() const;

	/// @return The first of two alleles
	char first() const { return _allele1; }

	/// @return The second of two alleles
	char second() const { return _allele2; }

	/**
	 * @brief Gets the phenotype of the Gene
	 *
	 * The phenotype represents the visible Allele trait.
	 * This should belong to the Allele that is dominant or default
	 * to one of the recessives which should share the trait.
	 * @return The phenotype of the Gene as a string
	 */
	string getPhenotype() const;

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
	string getZygosity() const;

	/// @return The allele pair of the gene as a string
	string getAllelesString() const {
		return string() += _allele1
			 + string() += _allele2;
	}

	/// Prints a full description of the Gene to stdout
	void printDescription() const;

private:
	char
		_allele1,  // The symbol for the first allele of the gene pair
		_allele2;  // The symbol for the second allele of the gene pair

	std::shared_ptr<MasterGene> _master;  // A shared_ptr to the MasterGene
};
