#include <gtest/gtest.h>
#include "core/gene/MasterGeneIndex.h"

class MasterGeneIndexTest : public testing::Test {
public:
    MasterGeneIndexTest() {
        index->clearIndex();
        masterGene = std::make_shared<MasterGene>(
                "", "", "", sym1, sym2, 3.3
        );
        index->add(masterGene);
    }

    MasterGeneIndex *index = MasterGeneIndex::getInstance();
    char sym1 = 'Z', sym2 = 'z';
    std::shared_ptr<MasterGene> masterGene;
};

// MasterGeneIndex.get should return a shared_ptr to a MasterGene which
// creates alleles of the type supplied in the method argument.
TEST_F(MasterGeneIndexTest, get_validSymbol) {
    ASSERT_EQ(*masterGene, *index->get(sym1));
    ASSERT_EQ(*masterGene, *index->get(sym2));
}

// MasterGeneIndex.get should return nullptr when an allele is supplied
// for which there is no matching MasterGene.
TEST_F(MasterGeneIndexTest, get_invalidSymbol) {
    ASSERT_EQ(nullptr, index->get('n'));
}
