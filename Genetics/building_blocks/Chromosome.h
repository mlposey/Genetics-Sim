#pragma once

#include <vector>
#include "Gene.h"

class Chromosome {
public:
    class const_iterator {
    public:
        const_iterator(std::vector<Gene>::const_iterator it,
					   std::vector<Gene>::const_iterator end)
			: _it(it)
			, _end(end)
		{ }

		/**
		 * @brief Compares two iterators for position equality
		 * @return True if the iterators are at different positions in the
		 *		   Chromosome.
		 */
        bool operator!=(const const_iterator &rhs) const;

        /**
		 * returns the symbol for a randomly chosen allele from the gene pair
		 * @throws std::range_error if dereferencing end iterator
		 */
        char operator*() const;

		/// Advances one Gene forward into the Chromosome
        const_iterator &operator++();

    private:
		// A const_iterator the underlying Gene vector
        std::vector<Gene>::const_iterator _it;

		// The end iterator. Used for bounds checking
		const std::vector<Gene>::const_iterator _end;
    };

    /**
     * @brief Adds a Gene to the chromosome composition
     * @param gene The gene to insert into the chromosome
     */
    void addGene(const Gene &gene);

	/// Acquires an iterator to the beginning of Chromosome strand
    const_iterator begin() const;

	/**
	 * @brief Acquires an iterator to the end of the Chromosome strand
	 * This element is theoretically one past the end and should not be
	 * queried for data.
	 */
    const_iterator end() const;

private:
	// The genes that make up the Chromosome
    std::vector<Gene> _genes;
};
