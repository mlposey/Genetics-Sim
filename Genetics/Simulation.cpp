#include <iostream>
#include <string>
#include <memory>
#include <sstream>

#include "Simulation.h"
#include "ColemanXMLParser.h"

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

			ColemanXMLParser parser(input);
			
			std::vector<Organism> parents;
			parser.parseFile(parents);

			_loveChamber = std::unique_ptr<LoveChamber>(new LoveChamber(parents[0], parents[1]));

			_loveChamber->addObserver(_statCounter);

			break;
		}
		catch (ifstream::failure &e) {
			std::cerr << "The file '" + input + "' could not be opened.\n";
			std::cerr << "Please try another file.\n";
		}
	}

	cout << "# of offspring to generate: ";
	std::getline(std::cin, input);

	std::istringstream ss(input);
	ss >> _offspringCount;
}
