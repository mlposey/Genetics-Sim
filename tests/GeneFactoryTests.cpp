#include <gtest/gtest.h>
#include <memory>
#include "util/CustomExceptions.h"
#include "core/gene/GeneFactory.h"
#include "core/gene/MasterGeneIndex.h"
#include "util.h"


class GeneFactoryTest : public testing::Test {
public:
    GeneFactoryTest() {
        addMasterGeneToBlankIndex(sym1, sym2);
    }

    char sym1 = 'T', sym2 = 't';
    GeneFactory *geneFactory = GeneFactory::getInstance();
};

// GeneFactory.createGene should not throw an exception if supplied two alleles
// that belong to a MasterGene in the MasterGeneIndex.
TEST_F(GeneFactoryTest, createGene_bothAllelesValid) {
    EXPECT_NO_THROW(geneFactory->createGene(sym1, sym1));
    EXPECT_NO_THROW(geneFactory->createGene(sym2, sym2));
    EXPECT_NO_THROW(geneFactory->createGene(sym2, sym1));
    EXPECT_NO_THROW(geneFactory->createGene(sym1, sym2));
}

// GeneFactory.createGene should throw InvalidSymbolException if supplied one
// allele that does not belong to a MasterGene in the MasterGeneIndex.
TEST_F(GeneFactoryTest, createGene_oneInvalidAllele) {
    EXPECT_THROW(geneFactory->createGene('w', sym1), InvalidSymbolException);
    EXPECT_THROW(geneFactory->createGene(sym2, 'w'), InvalidSymbolException);
}

// GeneFactory.createGene should throw InvalidSymbolException if supplied two
// alleles that do not belong to a MasterGene in the MasterGeneIndex.
TEST_F(GeneFactoryTest, createGene_bothAllelesInvalid) {
    EXPECT_THROW(geneFactory->createGene('b', 'b'), InvalidSymbolException);
}
