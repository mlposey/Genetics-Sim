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
    /**
     * @brief Creates a new MasterGene which Gene instances refer to.
     *
     * An example param list for a plant gene:
     *      trait - Plant Stature
     *      dominantAllele - Tall
     *      recessiveAllele - Dwarf
     *      dominantSymbol - T
     *      recessiveSymbol - t
     *      crossoverChance - 5.2
     *
     * @param trait The trait the gene causes in an organism
     * @param dominantAllele The physical result of having a dominant allele
     * @param recessiveAllele  The physical result of having a recessive allele
     * @param dominantSymbol The symbol for dominance
     * @param recessiveSymbol The symbol for recessiveness
     * @param crossoverChance The chance that alleles cross over during
     *  organism reproduction
     */
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
        _trait, // what trait the gene causes
        _dominantAllele, // physical result of a dominant allele
        _recessiveAllele; // physical result of a recessive allele
    
    // Symbols representing the dominant and recessive genes
    char 
        _dominantSymbol,
        _recessiveSymbol;

    // The chance that an allele from this gene will cross over
    double _crossoverChance;
};

