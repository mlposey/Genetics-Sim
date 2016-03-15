#include "Chromosome.h"

void Chromosome::addGene(const Gene &gene) {
  _genes.push_back(gene);
}

Chromosome::const_iterator Chromosome::begin() const {
  return Chromosome::const_iterator();
}

Chromosome::const_iterator Chromosome::end() const {
  return Chromosome::const_iterator();
}
