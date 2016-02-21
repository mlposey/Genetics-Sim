#include <gtest/gtest.h>

#include "../Genetics/Organism.cpp"

class OrganismTests : public testing::Test {
public:
    const char *genus;
    const char *species;
    const char *name;

    Organism organism;

    OrganismTests()
        : genus("Pisum")
        , species("Sativum")
        , name("Pea Plant")
        , organism(genus, species, name)
    {}
};

/**
 * This test assumes the following behavior:
 * 1.) Organism::addGene stores a copy of a gene in the Organism
 *
 * Deviation from the above should result in a failed test.
 */
TEST_F(OrganismTests, addGene) {
    Allele a('T', "desc");
    Gene g(a, a, "desc");

    ASSERT_EQ(0, organism.getGeneCount());

    organism.addGene(g);

    ASSERT_EQ(1, organism.getGeneCount());
}
