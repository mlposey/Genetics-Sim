#ifndef SRC_SCOREBOARD_H
#define SRC_SCOREBOARD_H

#include "IObserver.h"
#include "../building_blocks/gene/Gene.h"

/// @brief Scoreboard keeps track of the genetic variations that are created.
class Scoreboard : public IObserver<Gene> {
public:
    void notify(const Gene &gene);

    void displayResults();
};

#endif //SRC_SCOREBOARD_H
