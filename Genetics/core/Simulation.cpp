/*******************************************************************
*   Simulation.cpp
*   CS 307 Programming Assignment 1
*   Author: Marcus Posey
*   Date Submitted: 02/23/2016
*
*   This program is entirely my own work.
*******************************************************************/
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Simulation.h"
#include "../building_blocks/gene/MasterGeneFactory.h"
#include "../io/GeneticsSimDataParser.h"
#include "../building_blocks/OrganismFactory.h"
#include "../building_blocks/gene/MasterGeneIndex.h"



Simulation::Simulation()
	: _offspringCount(0) {
	init();
}

void Simulation::run() {
	cout << "\nRunning Simulation...\n\n";
	cout << "---------------------------------------------------\n";

	OrganismFactory *factory = OrganismFactory::getInstance();

	// Create _offspringCount number of offspring 
	for (int count = 0; count < _offspringCount; ++count) {
		_children.push_back(factory->createOrganism(_parent1, _parent2,
			_crossoverCount));
	}

	std::cout << "\nPress Enter to exit the simulation.\n";
	getchar();
}

void Simulation::init() {
	string input;

	// Attempt to get a valid data file from the user
	while (true) {
		try {
			cout << "Enter the name of the simulation data file and press Enter: ";
			std::getline(std::cin, input);

			// Acquire the MasterGene information and store it
			loadMasterGenes(input);

			// Acquire the parent information and create two parent organisms
			loadParentData();

			break;
		}
		catch (std::ifstream::failure &e) {
			// They tried to give a file that didn't exist
			std::cerr << "The file '" + input + "' could not be opened.\n";
			std::cerr << "Please try another file.\n";
		}
	}

	cout << "# of offspring to generate: ";
	std::getline(std::cin, input);

	std::istringstream ss(input);
	ss >> _offspringCount;
}

void Simulation::loadMasterGenes(const string &filename) {
	MasterGeneFactory* mgFactory = MasterGeneFactory::getInstance();
	mgFactory->setDataFile(filename);

	if (!mgFactory->isInitialized()) {
		// The file probably didn't exist
		throw std::ifstream::failure(filename + " did not exist.");
	}

	MasterGeneIndex *index = MasterGeneIndex::getInstance();

	cout << "Master Genes:\n";

	// Load all of the master genes for later flyweight use by Gene objects
	while (mgFactory->hasNext()) {
		auto masterGene = mgFactory->createMasterGene();
		
		// Print the master gene details
		cout << "\tTrait Name: " << masterGene->getTrait() << '\n';
		cout << "\t\tDominant Name: " << masterGene->getDominantAllele() << "("
			 << masterGene->getDominantSymbol() << ")\n";
		cout << "\t\tRecessive Name: " << masterGene->getRecessiveAllele() << "("
			 << masterGene->getRecessiveSymbol() << ")\n";
		cout << "\t\tChance of Crossover: " << masterGene->getCrossoverChance()
			 << "\n";

		// Add the master gene to the clustered index
		index->add(masterGene);
	}
	cout << "\n\n";
}

void Simulation::loadParentData() {
	// The parser used to retrieve information about each organism
	GeneticsSimDataParser *parser = GeneticsSimDataParser::getInstance();

	// Creates a parent organism
	auto createParent = [&](bool isParent1) {
		RawChromosomes chromosomes(parser->getChromosomeCount());

		// The chromosome information being displayed
		int counter = 1;
		
		// Convert the data file's chars to raw chromosomes
		for (auto &s : chromosomes) {
			// Two strands, each with a max length of 128 chars
			char buffer[2][128];
			isParent1 ? parser->getP1Chromosome(buffer[0], buffer[1]):
			parser->getP2Chromosome(buffer[0], buffer[1]);
			s.strand1 = buffer[0];
			s.strand2 = buffer[1];

			++counter;
		}

		auto &p = isParent1 ? _parent1 : _parent2;

		// Use the raw chromosomes to create an Organism
		p = OrganismFactory::getInstance()->createOrganism(
			parser->getGenus(),
			parser->getSpecies(),
			parser->getCommonName(),
			chromosomes);
	};

	cout << "Sim Parent 1\n";
	createParent(true);
	_parent1->printDescription();
	cout << "\n\n";

	cout << "Sim Parent 2\n";
	createParent(false);
	_parent2->printDescription();
}
