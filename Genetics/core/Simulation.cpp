/*******************************************************************
*   Simulation.cpp
*   CS 307 Programming Assignment 1
*   Author: Marcus Posey
*   Date Submitted: 02/23/2016
*
*   This program is entirely my own work.
*******************************************************************/
#include <iostream>
#include <string>
#include <memory>
#include <sstream>

#include "Simulation.h"
#include "../io/ColemanXMLParser.h"
#include "../utils/CustomExceptions.h"
#include "../building_blocks/gene/MasterGeneFactory.h"

using std::cout;
using std::string;

Simulation::Simulation()
	: _offspringCount(0) {
	init();
}

void Simulation::run() {
	cout << "\nRunning Simulation...\n\n";
	cout << "---------------------------------------------------\n";

	// Simulation happens here

	std::cout << "\nPress Enter to exit the simulation.\n";
	getchar();
}

void Simulation::init() {
	string input;

	while (true) {
		try {
			cout << "Enter the name of the simulation data file and press Enter: ";
			std::getline(std::cin, input);

			loadMasterGenes(input);
			
			// Get the general organism information from the top of the file
			
			// Get each organisms strands

			// Use factories to turn the strands into a series of objects

			break;
		}
		catch (ifstream::failure &e) {
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

void Simulation::loadMasterGenes(const std::string &filename) {
	MasterGeneFactory* mgFactory = MasterGeneFactory::getInstance();
	mgFactory->setDataFile(filename);

	if (!mgFactory->isInitialized()) {
		// The file probably didn't exist
		throw ifstream::failure(filename + " did not exist.");
	}

	MasterGeneIndex *index = MasterGeneIndex::getInstance();

	// Load all of the master genes for later flyweight use by Gene objects
	while (mgFactory->hasNext()) {
		index->add(mgFactory->createMasterGene());
	}
}
