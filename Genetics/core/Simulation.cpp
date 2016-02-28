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

using std::cout;
using std::string;

Simulation::Simulation()
	: _offspringCount(0) {
	init();
}

void Simulation::run() {
	_loveChamber->mate(_offspringCount);

	_statCounter.printStats();

	std::cout << "\nPress Enter to exit the simulation.\n";
	getchar();
}

void Simulation::init() {
	string input;

	while (true) {
		try {
			cout << "Enter the name of the simulation data file and press Enter: ";
			std::getline(std::cin, input);

			cout << "\nRunning Simulation...\n\n";
			cout << "---------------------------------------------------\n";

			ColemanXMLParser parser(input);

			std::vector<Organism> parents;
			// Take the data of the two parents from the input file
			parser.parseFile(parents);

			_loveChamber = std::unique_ptr<LoveChamber>(new LoveChamber(parents[0], parents[1]));

			// Add an object to keep track of created offspring
			_loveChamber->addObserver(_statCounter);

			break;
		}
		catch (ifstream::failure &e) {
			// They tried to give a file that didn't exist
			std::cerr << "The file '" + input + "' could not be opened.\n";
			std::cerr << "Please try another file.\n";
		}
		catch (MalformedFileException &e)
		{
			// The data is not in the expected format
			std::cerr << "An error occurred while reading the file:\n";
			std::cerr << e.what() << '\n';
		}
	}

	cout << "# of offspring to generate: ";
	std::getline(std::cin, input);

	std::istringstream ss(input);
	ss >> _offspringCount;
}
