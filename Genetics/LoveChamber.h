#pragma once
#include "IObservable.h"

class Organism;

class LoveChamber : public IObservable
{
public:
	LoveChamber(Organism &o1, Organism &o2);

	void mate();

private:
	Organism &_o1;
	Organism &_o2;
};

