#pragma once

#include <vector>
#include "Gene.h"

class Chromosome {
public:
    class const_iterator {
    public:
    private:
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
