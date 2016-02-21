#include <gtest/gtest.h>
#include <exception>

#include "../Genetics/Organism.cpp"

class OrganismTests : public testing::Test {
public:
    const char *genus;
    const char *species;
    const char *name;

    Organism organism;
    Gene gene;

    OrganismTests()
        : genus("Pisum")
        , species("Sativum")
        , name("Pea Plant")
        , organism(genus, species, name)
        , gene(Allele('T', "desc"), Allele('T', "desc"), "desc")
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

    ASSERT_EQ(0, organism.getGeneCount());

    organism.addGene(gene);

    ASSERT_EQ(1, organism.getGeneCount());
}

/**
 * This test assumes the following behavior:
 * 1.) If no genes are stored, an exception is thrown
 * 2.) Each call returns the address of the Organism's next gene
 * 3.) Repeated calls should cause an eventual wrap
 *
 * Deviation from the above should result in a failed test.
 */
TEST_F(OrganismTests, serveGene) {
    bool isExceptionThrown = false;
    try {
        // Spoiler alert: organism has no genes
        Gene g = organism.serveGene();
    } catch (std::exception &e) {
        // If we didn't get to this point the program will crash anyways..
        isExceptionThrown = true;
    }

    ASSERT_TRUE(isExceptionThrown);

    organism.addGene(gene);
    organism.addGene(Gene(Allele('W', "d"), Allele('W', "d"), "d"));

    Gene g = organism.serveGene();
    ASSERT_EQ("desc", g.getDescription());

    g = organism.serveGene();
    ASSERT_EQ("d", g.getDescription());

    // The wrap should occur here
    g = organism.serveGene();
    ASSERT_EQ("desc", g.getDescription());
}

// TODO: Create test for Organism::printDescription
