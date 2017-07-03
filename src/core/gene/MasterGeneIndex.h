#pragma once
#include <memory>
using std::shared_ptr;

#include "MasterGene.h"
#include <vector>

/**
 * @brief MasterGeneIndex stores a collection of all MasterGene objects.
 * @see MasterGene
 */
class MasterGeneIndex
{
public:
    static MasterGeneIndex *getInstance();

    /// Removes all MasterGene objects from the index
    void clear() { _masterGenes.clear(); }

    /**
     * @brief Loads a collection of gene definitions from a data file
     *
     * - File Format -
     *  The expected file type is .xml. Here is an example of a valid data file:
     *
     *  <MENDELIAN_GENETICS_SIM>
     *      <ORGANISM>
     *          <GENUS>
     *              Pisum
     *          </GENUS>
     *          <SPECIES>
     *              Sativum
     *          </SPECIES>
     *          <COMMON_NAME>
     *              Pea Plant
     *          </COMMON_NAME>
     *          <CHROMOSOME_COUNT>
     *              2
     *          </CHROMOSOME_COUNT>
     *      </ORGANISM>
     *      <GENES>
     *          <GENE>
     *              <GENE_TRAIT>
     *                  Plant Stature
     *              </GENE_TRAIT>
     *              <DOMINANT_ALLELE>
     *                  Tall
     *              </DOMINANT_ALLELE>
     *              <DOMINANT_SYMBOL>
     *                  T
     *              </DOMINANT_SYMBOL>
     *              <RECESSIVE_ALLELE>
     *                  Dwarf
     *              </RECESSIVE_ALLELE>
     *              <RECESSIVE_SYMBOL>
     *                  t
     *              </RECESSIVE_SYMBOL>
     *              <CROSSOVER_CHANCE>
     *                  5.2
     *              </CROSSOVER_CHANCE>
     *          </GENE>
     *          <GENE>
     *              <GENE_TRAIT>
     *                  Seed Texture
     *              </GENE_TRAIT>
     *              <DOMINANT_ALLELE>
     *                  Wrinkled
     *              </DOMINANT_ALLELE>
     *              <DOMINANT_SYMBOL>
     *                  W
     *              </DOMINANT_SYMBOL>
     *              <RECESSIVE_ALLELE>
     *                  Smooth
     *              </RECESSIVE_ALLELE>
     *              <RECESSIVE_SYMBOL>
     *                  w
     *              </RECESSIVE_SYMBOL>
     *              <CROSSOVER_CHANCE>
     *                  4.3
     *              </CROSSOVER_CHANCE>
     *          </GENE>
     *          <GENE>
     *              <GENE_TRAIT>
     *                  Seed Color
     *              </GENE_TRAIT>
     *              <DOMINANT_ALLELE>
     *                  Green
     *              </DOMINANT_ALLELE>
     *              <DOMINANT_SYMBOL>
     *                  S
     *              </DOMINANT_SYMBOL>
     *              <RECESSIVE_ALLELE>
     *                  Yellow
     *              </RECESSIVE_ALLELE>
     *              <RECESSIVE_SYMBOL>
     *                  s
     *              </RECESSIVE_SYMBOL>
     *              <CROSSOVER_CHANCE>
     *                  4.25
     *              </CROSSOVER_CHANCE>
     *          </GENE>
     *          <GENE>
     *              <GENE_TRAIT>
     *                  Flower Color
     *              </GENE_TRAIT>
     *              <DOMINANT_ALLELE>
     *                  Purple
     *              </DOMINANT_ALLELE>
     *              <DOMINANT_SYMBOL>
     *                  C
     *              </DOMINANT_SYMBOL>
     *              <RECESSIVE_ALLELE>
     *                  White
     *              </RECESSIVE_ALLELE>
     *              <RECESSIVE_SYMBOL>
     *                  c
     *              </RECESSIVE_SYMBOL>
     *              <CROSSOVER_CHANCE>
     *                  5.75
     *              </CROSSOVER_CHANCE>
     *          </GENE>
     *      </GENES>
     *      <PARENTS>
     *          <PARENT>
     *              <CHROMOSOME>
     *                  <STRAND1>
     *                      T C
     *                  </STRAND1>
     *                  <STRAND2>
     *                      t c
     *                  </STRAND2>
     *              </CHROMOSOME>
     *              <CHROMOSOME>
     *                  <STRAND1>
     *                      W S
     *                  </STRAND1>
     *                  <STRAND2>
     *                      w s
     *                  </STRAND2>
     *              </CHROMOSOME>
     *          </PARENT>
     *          <PARENT>
     *              <CHROMOSOME>
     *                  <STRAND1>
     *                      T C
     *                  </STRAND1>
     *                  <STRAND2>
     *                      t c
     *                  </STRAND2>
     *              </CHROMOSOME>
     *              <CHROMOSOME>
     *                  <STRAND1>
     *                      W S
     *                  </STRAND1>
     *                  <STRAND2>
     *                      w s
     *                  </STRAND2>
     *              </CHROMOSOME>
     *          </PARENT>
     *      </PARENTS>
     *  </MENDELIAN_GENETICS_SIM>
     *
     * @param filename The full pathname of the file
     * @param printer This function runs on each gene that is created
     *  from the file
     *
     * @throws std::ifstream::failure if the file could not be read
     */
    void loadFromFile(const std::string &filename,
        std::function<void(shared_ptr<MasterGene>)> printer);

    /// Adds a MasterGene to the index
    void add(shared_ptr<MasterGene> gene);

    /// Retrieves a MasterGene from the index
    shared_ptr<MasterGene> get(char allele);

private:
    MasterGeneIndex() {}

    // The program-wide collection of master genes
    std::vector<shared_ptr<MasterGene>> _masterGenes;
};
