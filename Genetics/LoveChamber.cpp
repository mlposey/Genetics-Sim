#include "LoveChamber.h"

LoveChamber::LoveChamber(Organism& o1, Organism& o2)
	: _o1(o1)
	, _o2(o2) {
}

void LoveChamber::mate() {
	notifyAll("");
}
