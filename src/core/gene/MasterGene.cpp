#include <cmath>
#include "MasterGene.h"

MasterGene::MasterGene(const string &trait, const string &dominantAllele,
           const string &recessiveAllele, char dominantSymbol,
           char recessiveSymbol, double crossoverChance)
    : _trait(trait)
    , _dominantAllele(dominantAllele)
    , _recessiveAllele(recessiveAllele)
    , _dominantSymbol(dominantSymbol)
    , _recessiveSymbol(recessiveSymbol)
    , _crossoverChance(crossoverChance) {
        // This must be at least 0 since the concept of a negative chance
        // does not make sense.
        _crossoverChance = _crossoverChance < 0 ? 0 : _crossoverChance;
}

bool MasterGene::operator==(const MasterGene &rhs) const {
        return
                _trait == rhs._trait &&
                _dominantAllele == rhs._dominantAllele &&
                _recessiveAllele == rhs._recessiveAllele &&
                _dominantSymbol == rhs._dominantSymbol &&
                _recessiveSymbol == rhs._recessiveSymbol &&
                fabs(_crossoverChance - rhs._crossoverChance) < 0.01;
}
