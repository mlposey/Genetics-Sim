#include <gtest/gtest.h>
#include "core/Chromosome.cpp"
#include "Util.h"

// Chromosome.addGene should place the first allele of the gene on the strand
// labeled Strand.STRAND1 and the second allele of the gene on the strand
// labeled Strand.STRAND2.
TEST(ChromosomeTest, ensureStrandPlacement) {
    char sym1 = 'T', sym2 = 't';
    auto masterGene = addMasterGeneToBlankIndex(sym1, sym2);

    Chromosome chromosome;
    chromosome.addGene({masterGene, sym1, sym2});

    ASSERT_TRUE(Chromosome::Strand::STRAND1 == chromosome.getStrand(sym1));
    ASSERT_TRUE(Chromosome::Strand::STRAND2 == chromosome.getStrand(sym2));
}

