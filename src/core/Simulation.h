#pragma once
#include <memory>
#include <string>
using std::string;

#include "../building_blocks/Organism.h"
#include "Scoreboard.h"

/**
 * @brief Simulation simulates reproduction between organisms.
 *
 * Simulation loads possible genetic configurations from a definition file and
 * creates the first two parents. It uses this initial data in combination with
 * command-line input to simulate organism reproduction.
 */
class Simulation
{
public:
	Simulation();

	/// Runs through the entirety of the simulation and then prints the results
	void run();

private:
    /// Initializes the program using command-line input
	void init();

	/**
	 * @brief Populates the gene index with genes from the definition file
	 *
	 * @throws std::ifstream::failure if the file cannot be read
	 * @see MasterGeneIndex
	 */
	void loadMasterGenes(const string &filename);

	/// Reads and stores data for two parents from the definition file
	void loadParentData();

    /**
     * @brief Creates a parent using data from the definition file
     *
     * The file should only define two parents.
     */
    std::shared_ptr<Organism> createParent();

	// Stores counts of unique genes and genotypes that are created
	// StatCounter _statCounter;

	// These are the Organisms defined in the data file
	std::shared_ptr<Organism> _parent1, _parent2;
	std::vector<std::shared_ptr<Organism>> _children;

	// How many offspring to create
	int _offspringCount;

	// The number of times a crossover occurred
	int _crossoverCount;

	Scoreboard _scoreboard;
};
