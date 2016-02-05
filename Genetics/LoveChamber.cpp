#include "LoveChamber.h"
#include "Organism.h"
#include <iostream>
#include <ctime>

LoveChamber::LoveChamber(Organism o1, Organism o2)
	: _o1(o1)
	, _o2(o2) {
		srand(time(nullptr));
		// TODO: Put this code in printParentData and make new function printOrganism
		std::cout << "-----------------------Parent Data-----------------\n";
		printParentData("Sim parent 1", o1);
		std::cout << "\n\n";
		printParentData("Sim parent 2", o2);
		std::cout << "---------------------------------------------------\n\n";
}

void LoveChamber::mate() {
	int size = _o1.getGeneCount();

	Organism offspring(_o1.getGenus(), _o1.getSpecies(), _o1.getName());
	Gene gene[2];
	string tmp;

	for (int i = 0; i < size; ++i) {
		_o1.serveGene(gene[0]);
		_o2.serveGene(gene[1]);

		offspring.addGene(Gene(gene[0].getRandomAllele(),
			gene[1].getRandomAllele(), gene[0].getDescription()));
	}

	notifyAll(offspring);
}

void LoveChamber::printParentData(const std::string &header, const Organism & o)
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
