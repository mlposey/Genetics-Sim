/*******************************************************************
*   Simulation.h
*   CS 307 Programming Assignment 1
*   Author: Marcus Posey
*   Date Submitted: 02/23/2016
*
*   This program is entirely my own work.
*******************************************************************/
#pragma once
#include <memory>
#include <string>
using std::string;

#include "../building_blocks/Organism.h"

/**
 * @brief The Simulation class handles the main thread of execution for the genetic simulation

 * Simulation invokes the necessary file parser to read the initial parent
 * states and uses this data to start the LoveChamber and StatCounter which
 * handle all reproduction and data collection
 * @see StatCounter
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
	 * @throws ifstream::failure
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
