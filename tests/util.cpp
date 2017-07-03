#include "util.h"
#include "core/gene/MasterGeneIndex.h"

shared_ptr<MasterGene> addMasterGeneToBlankIndex(char allele1, char allele2) {
    auto index = MasterGeneIndex::getInstance();
    index->clear();

    auto masterGene = std::make_shared<MasterGene>(
            "test", "test", "test", allele1, allele2, 3.3
    );
    index->add(masterGene);

    return masterGene;
}
