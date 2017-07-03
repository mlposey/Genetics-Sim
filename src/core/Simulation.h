#pragma once
#include <memory>
#include <string>
using std::string;

#include "../building_blocks/Organism.h"

/**
 * @brief Simulation handles the main thread of execution for the program.
 *
 * Simulation loads possible genetic configurations from a definition file and
 * creates the first two parents. It uses this initial data in combination with
 * command-line input to simulate organism reproduction.
 */
class Simulation
{
public:
	/// Constructs a Simulation object and initializes the state of the program
	Simulation();

	/// Runs through the entirety of the simulation and then prints the results
	void run();

private:
	void init();

	/**
	 * @brief Loads genes from the file into _masterGenes
	 *
	 * If the file cannot be read, the program will display a message to
	 * standard error and then exit with a failing status.
	 */
	void loadMasterGenes(const string &filename);

	/// @brief Initializes two parent Organisms
	void loadParentData();

	// Stores counts of unique genes and genotypes that are created
	// StatCounter _statCounter;

	// These are the Organisms defined in the data file
	std::shared_ptr<Organism> _parent1, _parent2;
	std::vector<std::shared_ptr<Organism>> _children;

	// How many offspring to create
	int _offspringCount;

	// The number of times a crossover occurred
	int _crossoverCount;
};
