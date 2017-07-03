#include <iostream>
#include "Scoreboard.h"
#include "../core/OrganismFactory.h"

void Scoreboard::notify(const Gene &gene) {
    _geneStats[gene.getTrait()][gene]++;
}

void Scoreboard::displayResults() {
    std::cout << "============== Gene Results (Including Initial Parents) ==============\n\n";

    for (auto &traitVariations : _geneStats) {
        std::cout << "Gene: " << traitVariations.first << '\n';

        for (auto &variationCounts : traitVariations.second) {
            std::cout << '\t' << variationCounts.second << " "
                      << variationCounts.first << '\n';
        }
        std::cout << '\n';
    }

    std::cout << "A total of " << std::to_string(
            OrganismFactory::getInstance()->getCrossoverCount())
              << " offspring had at least one crossover gene.\n";
}
