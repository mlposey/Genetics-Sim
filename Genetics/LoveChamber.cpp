#include "LoveChamber.h"
#include "Organism.h"
#include <iostream>
#include <ctime>

using std::cout;

LoveChamber::LoveChamber(Organism o1, Organism o2)
	: _o1(o1)
	, _o2(o2) {
		srand(static_cast<unsigned int>(time(nullptr)));
		// Show the genetic makeup of the organisms
		printParentData();
}

void LoveChamber::mate(int count) {
	const int size = _o1.getGeneCount();

	// Create 'count' offspring and send each of them to the observers
	for (int c = 0; c < count; ++c) {
		Organism offspring(_o1.getGenus(), _o1.getSpecies(), _o1.getName());

		for (int i = 0; i < size; ++i)
		{
			Gene &g1 = _o1.serveGene();
			Gene &g2 = _o2.serveGene();

			// Give the offspring a random allele from each parent
			offspring.addGene(Gene(g1.getRandomAllele(),
				g2.getRandomAllele(), g1.getDescription()));
		}

		notifyAll(offspring);
	}
}

void LoveChamber::printParentData() const
{
	cout << "\n-----------------------Parent Data-----------------\n";

	cout << "Sim parent 1\n";
	_o1.printDescription();
	
	cout << "\n\n";

	cout << "Sim parent 2\n";
	_o2.printDescription();

	cout << "---------------------------------------------------\n\n";
}
