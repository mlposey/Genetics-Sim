#pragma once
#include <unordered_map>
using std::unordered_map;
#include <map>
using std::map;
#include "IObserver.h"
#include "core/gene/Gene.h"

/// @brief Scoreboard keeps track of the genetic variations that are created.
class Scoreboard : public IObserver<Gene> {
public:
    void notify(const Gene &gene);

    void displayResults();

private:
    /* This maps a type of gene to its variations and times they occurred.
     * Ex:
     *  {
     *      "Plant Stature" : {
     *          "heterozygous dominant (Tall Tt)" : 10,
     *          "homozygous dominant (Tall TT)" : 3,
     *          "homozygous recessive (Dwarf tt)" : 7
     *      }
     *  }
     */
    unordered_map<string, map<string, int>> _geneStats;
};
