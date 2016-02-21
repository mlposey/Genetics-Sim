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

#include "LoveChamber.h"
#include "StatCounter.h"

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

	std::unique_ptr<LoveChamber> _loveChamber;

	StatCounter _statCounter;

	int _offspringCount;
};
