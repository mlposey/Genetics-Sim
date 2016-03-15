#include "Chromosome.h"

void Chromosome::addGene(const Gene &gene) {
    _genes.push_back(gene);
}

Chromosome::const_iterator Chromosome::begin() const {
    return Chromosome::const_iterator(_genes.begin());
}

Chromosome::const_iterator Chromosome::end() const {
    return Chromosome::const_iterator(_genes.end());
}

bool Chromosome::const_iterator::operator!=(const Chromosome::const_iterator &rhs) {
    return _it != rhs._it;
}

char Chromosome::const_iterator::operator*() const {
    return _it->getRandomAllele().getSymbol();
}

Chromosome::const_iterator &Chromosome::const_iterator::operator++(int c) {
    ++_it;
    return *this;
}
