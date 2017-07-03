#pragma once

#include <memory>
using std::shared_ptr;
#include "core/gene/MasterGene.h"

// Clears MasterGeneIndex and adds one MasterGene with the supplied alleles
shared_ptr<MasterGene> addMasterGeneToBlankIndex(char allele1, char allele2);
