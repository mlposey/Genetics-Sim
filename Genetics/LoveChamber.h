#pragma once
#include "Observable.h"

#include "Organism.h"

class LoveChamber : public Observable<Organism>
{
public:
	LoveChamber(Organism o1, Organism o2);

	void mate();

private:
	Organism _o1;
	Organism _o2;
};

