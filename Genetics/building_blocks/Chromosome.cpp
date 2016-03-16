#include "Chromosome.h"

void Chromosome::addGene(const Gene &gene) {
    _genes.push_back(gene);
}

Chromosome::const_iterator Chromosome::begin() const {
    return Chromosome::const_iterator(_genes.begin(), _genes.end());
}

Chromosome::const_iterator Chromosome::end() const {
    return Chromosome::const_iterator(_genes.end(), _genes.end());
}

bool Chromosome::const_iterator::operator!=(const Chromosome::const_iterator &rhs) const {
    return _it != rhs._it;
}

char Chromosome::const_iterator::operator*() const {
	if (_it == _end) {
		throw std::range_error("The iterator does not point to a valid object.");
	}
    return _it->getRandomAllele().getSymbol();
}

Chromosome::const_iterator &Chromosome::const_iterator::operator++() {
    ++_it;
    return *this;
}
