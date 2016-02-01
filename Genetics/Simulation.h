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

	std::unique_ptr<LoveChamber> _loveChamber;

	StatCounter _statCounter;

	int _offspringCount;
};

