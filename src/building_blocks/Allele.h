#pragma once
#include <string>

/**
 * @brief The Allele class models the alleles of a Gene
 *
 * An allele stores symbol information (e.g. T or t), the phenotype
 * of the allele (e.g. tall), and whether the allele is dominant or not.
 * Alleles are a component of Genes.
 * @see Gene
 */
class Allele
{
public:
	/**
	 * @brief Constructs an Allele object
	 * @param symbol The symbol for the allele
	 * @param phenotype The physical trait that the allele encodes
	 */
	Allele(char symbol, const std::string &phenotype);

	/// @return True if the allele is dominant or false if it is recessive
	bool isDominant() const { return isupper(_symbol) != 0; }

	/// @return The symbol of the allele (e.g. 'T' or 't')
	char getSymbol() const { return _symbol; }

	/// @return The physical description of the allele (e.g. "tall" or "short")
	std::string getPhenotype() const { return _phenotype; }

private:
	/*
	  The symbol of the Allele. Capital letters represent a dominant Allele
	  while lower case letters represent a recessive one.
	*/
	char _symbol;

	// The physical trait the Alelle represents
	std::string _phenotype;
};
