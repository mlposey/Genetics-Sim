#include <gtest/gtest.h>
#include <memory>
#include "../src/utils/CustomExceptions.h"
#include "../src/building_blocks/gene/GeneFactory.h"
#include "../src/building_blocks/gene/MasterGeneIndex.h"


class GeneFactoryTest : public testing::Test {};

TEST_F(GeneFactoryTest, createGene_bothAllelesValid) {
    MasterGeneIndex::getInstance()->add(std::make_shared<MasterGene>(
            "", "", "", 'T', 't', 0.0
    ));

    EXPECT_NO_THROW(GeneFactory::getInstance()->createGene('t', 't'));
    EXPECT_NO_THROW(GeneFactory::getInstance()->createGene('T', 'T'));
    EXPECT_NO_THROW(GeneFactory::getInstance()->createGene('t', 'T'));
    EXPECT_NO_THROW(GeneFactory::getInstance()->createGene('t', 'T'));
}

TEST_F(GeneFactoryTest, createGene_oneInvalidAllele) {
    MasterGeneIndex::getInstance()->add(std::make_shared<MasterGene>(
            "", "", "", 'X', 'x', 0.0
    ));

    EXPECT_THROW(GeneFactory::getInstance()->createGene('w', 'X'),
        InvalidSymbolException);
    EXPECT_THROW(GeneFactory::getInstance()->createGene('X', 'w'),
                 InvalidSymbolException);
}

TEST_F(GeneFactoryTest, createGene_bothAllelesInvalid) {
    MasterGeneIndex::getInstance()->add(std::make_shared<MasterGene>(
            "", "", "", 'Q', 'q', 0.0
    ));

    EXPECT_THROW(GeneFactory::getInstance()->createGene('b', 'b'),
                 InvalidSymbolException);
}
