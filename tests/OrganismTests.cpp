#include <gtest/gtest.h>
#include "core/Organism.cpp"
#include "util/CustomExceptions.h"

class OrganismTest : public testing::Test {};

// Organism.serveChromosome should throw EmptyContainerException if the
// organism has no chromosomes.
TEST_F(OrganismTest, serveChromosome_empty) {
    Organism organism("test", "test", "test");
    ASSERT_THROW(organism.serveChromosome(), EmptyContainerException);
}

// Organism.serveChromosome should loop to the start of the chromosomes
// after the collection has been fully traversed.
TEST_F(OrganismTest, serveChromosome_loop) {
    // TODO:
}
