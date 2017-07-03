#pragma once

#include <vector>
#include "gene/Gene.h"
#include <unordered_map>

/**
 * @brief Chromosome consists of genes placed on two strands.
 *
 * This illustration of chromosomes displays the concept:
 *
 *  - Chromosome -
 * |S1 -------- S2|
 * |--          --|
 * | t - Gene - T |
 * | q - Gene - q |
 * | X - Gene - x |
 * |--          --|
 * |S1 -------- S2|
 *
 */
class Chromosome : public std::vector<Gene> {
public:
	// The strands of a chromosome
	enum class Strand {
		STRAND1,
		STRAND2
	};

    /**
     * @brief Adds a Gene to the chromosome composition
     *
     * The first allele of the gene is placed on Strand 1 and the second
     * allele on Strand 2.
     *
	 * Mistakenly using the vector addition methods instead of this one will
     * result in alleles not being placed on their respective strands.
     *
     * @param gene The gene to insert into the chromosome
     */
    void addGene(const Gene &gene);

	/// Returns the strand that the allele is located on
	Strand getStrand(char allele);

private:
	// Maps each allele character to the strand it resides on
	std::unordered_map<char, Strand> _strandMap;
};
