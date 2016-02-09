#include "LoveChamber.h"
#include "Organism.h"
#include <iostream>
#include <ctime>

LoveChamber::LoveChamber(Organism o1, Organism o2)
	: _o1(o1)
	, _o2(o2) {
		srand(static_cast<unsigned int>(time(nullptr)));
		// Show the genetic makeup of the organisms
		printParentData();
}

void LoveChamber::mate(int count) {
	int size = _o1.getGeneCount();

	// Create 'count' offspring and send each of them to the observers
	for (int c = 0; c < count; ++c) {
		Organism offspring(_o1.getGenus(), _o1.getSpecies(), _o1.getName());

		for (int i = 0; i < size; ++i)
		{
			// TODO: Consider making this faster
			Gene g1(_o1.serveGene());
			Gene g2(_o2.serveGene());

			offspring.addGene(Gene(g1.getRandomAllele(),
				g2.getRandomAllele(), g1.getDescription()));
		}

		notifyAll(offspring);
	}
}

void LoveChamber::printParentData() const
{
	std::cout << "\n-----------------------Parent Data-----------------\n";
	printOrganismData("Sim parent 1", _o1);
	std::cout << "\n\n";
	printOrganismData("Sim parent 2", _o2);
	std::cout << "---------------------------------------------------\n\n";
}

void LoveChamber::printOrganismData(const std::string &header, const Organism & o)
{
	std::cout << header << '\n';
	std::cout << "\tOrganism genus-species: " << o.getGenus() << " "
			  << o.getSpecies() << '\n';
	std::cout << "\tCommon name: " << o.getName() << '\n';
	std::cout << "\tGenes: \n";
	
	for (const Gene &g : o.getGenotype()) {
		std::cout << "\t\tGene type = " << g.getDescription() << '\n';
		std::cout << "\t\t\tGenotype = " << g.getAllelesString() << '\n';
	}
}
