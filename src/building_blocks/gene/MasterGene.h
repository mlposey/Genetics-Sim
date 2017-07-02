#pragma once

#include <string>
using std::string;

/**
 * @brief MasterGene is the common instance of a specific Gene.
 *
 * Genes are implemented in a flyweight pattern. Common data is stored in a
 * master instance (this class), while specific details are kept in Gene
 * instances.
 *
 * When making future modifications, keep in mind that many Gene instances will
 * rely on one instance of a MasterGene. And, in any case, you will likely not
 * create MasterGene objects directly. Consult GeneFactory and
 * MasterGeneFactory for a better idea of what creational responsibilities code
 * additions require.
 */
class MasterGene
{
public:
	MasterGene(const string &trait, const string &dominantAllele,
		       const string &recessiveAllele, char dominantSymbol,
			   char recessiveSymbol, double crossoverChance);

	string getTrait() const {
		return _trait;
	}

	string getDominantAllele() const {
		return _dominantAllele;
	}

	string getRecessiveAllele() const {
		return _recessiveAllele;
	}

	char getDominantSymbol() const {
		return _dominantSymbol;
	}

	char getRecessiveSymbol() const {
		return _recessiveSymbol;
	}

	/**
	 * @brief Returns the chance that an allele from this gene will cross over
	 * @see OrganismFactory.createOrganism to better understand the concept
	 * of allele crossover.
	 */
	double getCrossoverChance() const {
		return _crossoverChance;
	}

private:
	string
		_trait,
		_dominantAllele,
		_recessiveAllele;
	
	// Symbols representing the dominant and recessive genes
	char 
		_dominantSymbol,
		_recessiveSymbol;

	// The chance that an allele from this gene will cross over
	double _crossoverChance;
};

