#include "Chromosome.h"

void Chromosome::addGene(const Gene &gene) {
	    push_back(gene);
		_strandMap.emplace(gene.first(), Strand::STRAND1);
		_strandMap.emplace(gene.second(), Strand::STRAND2);
}

Chromosome::Strand Chromosome::getStrand(char allele) {
	return _strandMap[allele];
}
