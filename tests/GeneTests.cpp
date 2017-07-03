#include <gtest/gtest.h>
#include <memory>
#include "../external/instructor_files/GeneticsSimDataParser.cpp"
#include "../src/core/gene/MasterGeneIndex.cpp"
#include "../src/core/gene/Gene.cpp"
#include "../src/core/gene/GeneFactory.cpp"


class GeneTest : public testing::Test {
public:
    enum Zygosity {HET_DOM, HOM_DOM, HOM_REC};

    GeneTest() {
        MasterGeneIndex::getInstance()->add(std::make_shared<MasterGene>(
                "Plant Stature",
                "Tall",
                "Dwarf",
                'T',
                't',
                5.2)
        );
    }

    Gene makeGene(Zygosity zyg) {
        auto factory = GeneFactory::getInstance();
        switch (zyg) {
            case HET_DOM: return factory->createGene('T', 't');
            case HOM_DOM: return factory->createGene('T', 'T');
            case HOM_REC: return factory->createGene('t', 't');
        }
    }
    // These exist because gtest string comparisons need cstrings
#define PHENOTYPE(ZYG) makeGene(ZYG).getPhenotype().c_str()
#define ZYGOSITY(ZYG) makeGene(ZYG).getZygosity().c_str()
};

// Gene.getPhenotype should return the phenotype of the dominant allele if there
// is one in the gene.
TEST_F(GeneTest, phenotype_tall) {
    auto expected = "Tall";
    ASSERT_STREQ(expected, PHENOTYPE(HET_DOM));
    ASSERT_STREQ(expected, PHENOTYPE(HOM_DOM));
    ASSERT_STRNE(expected, PHENOTYPE(HOM_REC));
}

// Gene.getPhenotype should return the phenotype of the recessive allele if both
// alleles are recessive.
TEST_F(GeneTest, phentotype_short) {
    auto expected = "Dwarf";
    ASSERT_STRNE(expected, PHENOTYPE(HET_DOM));
    ASSERT_STRNE(expected, PHENOTYPE(HOM_DOM));
    ASSERT_STREQ(expected, PHENOTYPE(HOM_REC));
}

// Gene.getZygosity should return 'heterozygous dominant' if one of the alleles
// in the gene is dominant.
TEST_F(GeneTest, zygosity_hetdom) {
    auto expected = "heterozygous dominant";
    ASSERT_STREQ(expected, ZYGOSITY(HET_DOM));
    ASSERT_STRNE(expected, ZYGOSITY(HOM_DOM));
    ASSERT_STRNE(expected, ZYGOSITY(HOM_REC));
}

// Gene.getZygosity should return 'homozygous dominant' if both of the alleles
// in the gene are dominant.
TEST_F(GeneTest, zygosity_homdom) {
    auto expected = "homozygous dominant";
    ASSERT_STREQ(expected, ZYGOSITY(HOM_DOM));
    ASSERT_STRNE(expected, ZYGOSITY(HET_DOM));
    ASSERT_STRNE(expected, ZYGOSITY(HOM_REC));
}

// Gene.getZygosity should return 'homozygous recessive' if both of the alleles
// in the gene are recessive.
TEST_F(GeneTest, zygosity_homrec) {
    auto expected = "homozygous recessive";
    ASSERT_STREQ(expected, ZYGOSITY(HOM_REC));
    ASSERT_STRNE(expected, ZYGOSITY(HET_DOM));
    ASSERT_STRNE(expected, ZYGOSITY(HOM_DOM));
}
