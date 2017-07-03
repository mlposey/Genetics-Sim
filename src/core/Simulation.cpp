#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Simulation.h"
#include "../../external/instructor_files/GeneticsSimDataParser.h"
#include "../building_blocks/OrganismFactory.h"
#include "../building_blocks/gene/MasterGeneIndex.h"
#include "../building_blocks/gene/GeneFactory.h"

Simulation::Simulation()
	: _parent1(nullptr)
    , _parent2(nullptr)
    , _offspringCount(0) {
	init();
}

void Simulation::run() {
	cout << "\nRunning Simulation...\n\n";

	OrganismFactory *factory = OrganismFactory::getInstance();

	// Create _offspringCount number of offspring 
	for (int count = 0; count < _offspringCount; ++count) {
		_children.push_back(factory->createOrganism(_parent1, _parent2));
	}

    _scoreboard.displayResults();

	std::cout << "\nPress Enter to exit the simulation.";
	getchar();
}

void Simulation::init() {
	srand(time(nullptr));
	GeneFactory::getInstance()->addObserver(_scoreboard);

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
	MasterGeneIndex *index = MasterGeneIndex::getInstance();

	cout << "\nMaster Genes:\n";

	try {
		index->loadFromFile(filename, [](shared_ptr<MasterGene> gene) {
			cout << "\tTrait Name: " << gene->getTrait() << '\n';

			cout << "\t\tDominant Name: " << gene->getDominantAllele() << "("
				 << gene->getDominantSymbol() << ")\n";

			cout << "\t\tRecessive Name: " << gene->getRecessiveAllele() << "("
				 << gene->getRecessiveSymbol() << ")\n";

			cout << "\t\tChance of Crossover: " << gene->getCrossoverChance()
				 << "\n";
		});
	} catch (const std::ifstream::failure &e) { throw e; }

	cout << "\n\n";
}

void Simulation::loadParentData() {
	cout << "Sim Parent 1\n";
	_parent1 = createParent();
	_parent1->printDescription();
	cout << "\n\n";

	cout << "Sim Parent 2\n";
	_parent2 = createParent();
	_parent2->printDescription();
}

std::shared_ptr<Organism> Simulation::createParent() {
    GeneticsSimDataParser *parser = GeneticsSimDataParser::getInstance();
    ChromosomesStrands chromosomes(parser->getChromosomeCount());

    // Convert the data file's chars to pairs of chromosome strands.
    for (auto &s : chromosomes) {
        // Two strands, each with a max length of 128 chars
        char buffer[2][128];

        // Has the first parent been created yet?
        if (!_parent1) parser->getP1Chromosome(buffer[0], buffer[1]);
        else parser->getP2Chromosome(buffer[0], buffer[1]);

        s.first = buffer[0];
        s.second = buffer[1];
    }

    return OrganismFactory::getInstance()->createOrganism(
            parser->getGenus(),
            parser->getSpecies(),
            parser->getCommonName(),
            chromosomes
	);
}
