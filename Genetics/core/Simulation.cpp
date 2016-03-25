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
#include <thread>
#include <vector>

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

	// Simulation happens here
	
	// For each chromosome among both parents
		// Acquire iterators for each parent's chromosome
			// 

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

	// Load all of the master genes for later flyweight use by Gene objects
	while (mgFactory->hasNext()) {
		index->add(mgFactory->createMasterGene());
	}
}

void Simulation::loadParentData() {
	// The parser used to retrieve information about each organism
	GeneticsSimDataParser *parser = GeneticsSimDataParser::getInstance();

	// The Organisms will have a shared number of chromosomes
	const int kChromosomeCount = parser->getChromosomeCount();

	// Each chromosome has two strands
	const int kStrandCount = 2;

	// The max line length as defined by GeneticsSimDataParser is 128.
	// Therefore, the max strand length shares this value
	const int kMaxLength = 128;

	// A collection of raw chromosomes for each parent
	std::vector<RawChromosome>
		p1(kChromosomeCount),
		p2(kChromosomeCount);


	// Acquire chromosome information for each parent
	for (auto &s : p1) {
		char buffer[kStrandCount][kMaxLength];
		parser->getP1Chromosome(buffer[0], buffer[1]);
		s.strand1 = buffer[0];
		s.strand2 = buffer[1];
	}

	for (auto &s : p2) {
		char buffer[kStrandCount][kMaxLength];
		parser->getP2Chromosome(buffer[0], buffer[1]);
		s.strand1 = buffer[0];
		s.strand2 = buffer[1];
	}

	
	// Build the first parent using factories
	std::thread parent1Thread([&]() {
		_parent1 = OrganismFactory::getInstance()->createOrganism(
				parser->getGenus(),
				parser->getSpecies(),
				parser->getCommonName(),
				p1);
	});

	// Build the second parent using factories
	std::thread parent2Thread([&]() {
		_parent2 = OrganismFactory::getInstance()->createOrganism(
				parser->getGenus(),
				parser->getSpecies(),
				parser->getCommonName(),
				p2);
	});

	parent1Thread.join();
	parent2Thread.join();
}
