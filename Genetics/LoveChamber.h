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
	 * @brief Creates an offspring using two parent Organisms
	 *
	 * Uses the genotype of both organisms to create a random, new
	 * genotype that will belong to some offspring that is then sent to
	 * all Observers
	 */
	void mate();

private:
	void printParentData(const std::string &header, const Organism &o);

	Organism _o1;
	Organism _o2;
};

