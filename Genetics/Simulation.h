#pragma once
#include <memory>

#include "Organism.h"
#include "LoveChamber.h"
#include "StatCounter.h"

class Simulation
{
public:
	Simulation();

	void run();

private:
	void init();

	std::vector<Organism> _parents;
	std::unique_ptr<LoveChamber> _loveChamber;

	StatCounter statCounter;

	int _offspringCount;
};

