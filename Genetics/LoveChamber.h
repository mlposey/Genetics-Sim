/*******************************************************************
*   LoveChamber.h
*   CS 307 Programming Assignment 1
*   Author: Marcus Posey
*   Date Submitted: 02/23/2016
*
*   This program is entirely my own work.
*******************************************************************/
#pragma once
#include "Observable.h"

#include "Organism.h"

/**
 * @brief The LoveChamber class handles mating between Organisms
 *
 * LoveChamber uses the genotype of two Organisms to perform random crosses
 * between the individual genotypes of each parent. The resulting offspring
 * are sent to classes that observe LoveChamber.
 * @see Organism, Observable
 */
class LoveChamber : public Observable<Organism>
{
public:
	/**
	 * @brief Constructs a LoveChamber capable of producing offspring
	 * @param o1 one parent of potential offspring
	 * @param o2 one parent of potential offspring
	 */
	LoveChamber(Organism o1, Organism o2);

	/**
	 * @brief Creates a number of offspring using two parent Organisms
	 *
	 * Uses the genotype of both organisms to repeatedly create a random, new
	 * genotype that will belong to some offspring that is then sent to
	 * all Observers
	 * @param count the number of offspring that should be created
	 */
	void mate(int count);

private:
	/// Prints the genetic makeup of each organism
	void printParentData() const;

	Organism _o1;  // A parent organism
	Organism _o2;  // A parent organism
};
