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
	for (int i = 0; i < _offspringCount; ++i) {
		_loveChamber->mate();
	}
	_statCounter.printStats();
}

void Simulation::init() {
	std::unique_ptr<IFileParser> parser;

	string input;

	while (true) {
		try {
			cout << "Enter the name of the simulation data file and press Enter: ";
			std::getline(std::cin, input);

			parser = std::unique_ptr<IFileParser>(new ColemanXMLParser(input));
			parser->parseFile(_parents, 2);

			_loveChamber = std::unique_ptr<LoveChamber>(new LoveChamber(_parents[0], _parents[1]));
			_loveChamber->addObserver(_statCounter);

			break;
		}
		catch (ifstream::failure &e) {
			std::cerr << "The file '" + input + "' could not be opened.\n";
			std::cerr << "Please try another file.\n";
		}
	}

	// Print organism info here

	cout << "# of offspring to generate: ";
	std::getline(std::cin, input);

	std::istringstream ss(input);
	ss >> _offspringCount;
}
