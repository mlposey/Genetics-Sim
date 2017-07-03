#include <gtest/gtest.h>
#include "core/Organism.cpp"
#include "util/CustomExceptions.h"
#include "util.h"

class OrganismTest : public testing::Test {
public:
    OrganismTest() : organism("test", "test", "test") {}
    Organism organism;
};

// Organism.serveChromosome should throw EmptyContainerException if the
// organism has no chromosomes.
TEST_F(OrganismTest, serveChromosome_empty) {
    ASSERT_THROW(organism.serveChromosome(), EmptyContainerException);
}

// Organism.serveChromosome should loop to the start of the chromosomes
// after the collection has been fully traversed.
TEST_F(OrganismTest, serveChromosome_loop) {
    // Create chromosomes to add to the organism.
    char sym1 = 'T', sym2 = 't';
    auto masterGene = addMasterGeneToBlankIndex(sym1, sym2);

    Chromosome chromosome1, chromosome2;
    chromosome1.addGene({masterGene, sym1, sym2});
    chromosome2.addGene({masterGene, sym1, sym1});

    organism.addChromosome(chromosome1);
    organism.addChromosome(chromosome2);

    // TODO: This test really isn't ideal because we can't be sure the last
    //  call to serveChromosome returns the same chromosome as the first call.
    //  Fix this by overloading the equality operator for Chromosome and using
    //  ASSERT_EQ to verify the chromosome's identity.

    // Expect to loop through from chromosome1 -> chromosome2 -> chromosome1
    organism.serveChromosome();
    organism.serveChromosome();
    ASSERT_NO_THROW(organism.serveChromosome());
}
