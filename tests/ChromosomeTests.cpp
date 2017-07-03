#include <gtest/gtest.h>
#include "core/Chromosome.cpp"
#include "core/gene/MasterGeneIndex.h"

// Chromosome.addGene should place the first allele of the gene on the strand
// labeled Strand.STRAND1 and the second allele of the gene on the strand
// labeled Strand.STRAND2.
TEST(ChromosomeTest, ensureStrandPlacement) {
    auto index = MasterGeneIndex::getInstance();
    index->clear();

    char sym1 = 'T', sym2 = 't';
    auto masterGene = std::make_shared<MasterGene>(
            "", "", "", sym1, sym2, 3.3
    );
    index->add(masterGene);

    Chromosome chromosome;
    chromosome.addGene({masterGene, sym1, sym2});

    ASSERT_TRUE(Chromosome::Strand::STRAND1 == chromosome.getStrand(sym1));
    ASSERT_TRUE(Chromosome::Strand::STRAND2 == chromosome.getStrand(sym2));
}

