#pragma once

#include <vector>
#include "Gene.h"

class Chromosome {
public:
    class const_iterator {
    public:
        const_iterator(std::vector<Gene>::const_iterator it)
                : _it(it) { }

        bool operator!=(const const_iterator &rhs);

        char operator*() const;

        const_iterator &operator++(int c);

    private:
        std::vector<Gene>::const_iterator _it;
    };

    /**
     * @brief Adds a Gene to the chromosome composition
     * @param gene The gene to insert into the chromosome
     */
    void addGene(const Gene &gene);

    const_iterator begin() const;

    const_iterator end() const;

private:
    std::vector<Gene> _genes;
};
