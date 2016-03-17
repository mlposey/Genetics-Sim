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
#include <vector>
#include <string>

#include "StatCounter.h"

class MasterGene;

/**
 * @brief The Simulation class handles the main thread of execution for the genetic simulation

 * Simulation invokes the necessary file parser to read the initial parent
 * states and uses this data to start the LoveChamber and StatCounter which
 * handle all reproduction and data collection
 * @see LoveChamber, StatCounter
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
	void loadMasterGenes(const std::string &filename);

	// Stores counts of unique genes and genotypes that are created
	StatCounter _statCounter;

	// How many offspring to create
	int _offspringCount;

	// The collection of MasterGenes that are referenced by all Gene objects
	std::vector<std::shared_ptr<MasterGene>> _masterGenes;
};
