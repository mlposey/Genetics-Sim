#pragma once

#include <vector>
#include "gene/Gene.h"
#include <unordered_map>

// A very basic representation of a chromosome that is used
// by ChromosomeFactory to create Chromosome objects
struct RawChromosome {
	string strand1, strand2;
};
// A vector of RawChromosome objects
typedef std::vector<RawChromosome> RawChromosomes;

class Chromosome : public std::vector<Gene> {
public:
	// The strands of a chromosome
	enum class Strand {
		STRAND1,
		STRAND2
	};

    /**
     * @brief Adds a Gene to the chromosome composition
	 * This should be used instead of the inherited vector additions
     * @param gene The gene to insert into the chromosome
     */
    void addGene(const Gene &gene);

	/// Returns the strand that the allele is located on
	Strand getStrand(char allele);

private:
	// Maps each allele character to the strand it resides on
	std::unordered_map<char, Strand> _strandMap;
};
