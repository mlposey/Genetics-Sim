/*******************************************************************
*   StatCounter.h
*   CS 307 Programming Assignment 1
*   Author: Marcus Posey
*   Date Submitted: 02/23/2016
*
*   This program is entirely my own work.
*******************************************************************/
#pragma once
#include <unordered_map>

#include <string>
using std::string;

#include "../sync/IObserver.h"

class Organism;
class Gene;

// Not to be confused with the stl tree implementation of a map
#define map std::unordered_map

/**
 * @brief The StatCounter class records statistical data of Organisms
 *
 * This class is meant to observe some other class that provides
 * an implemenation of Observable<Organism>. All Organisms that
 * are sent to StatCounter have counts of both genotypes and Genes
 * recorded.
 * @see IObserver, Organism
 */
class StatCounter : public IObserver<Organism>
{
public:
	/// Increments the stored counts of the genotypes and genes that arg possesses
	void notify(const Organism &arg) override;

	/// Displays the count data for genotypes and genes that have been processed
	void printStats();

private:
	/// A count of how many times each genotype occurs
	map<string, int> _genotypeCounts;

	/// A count of how many times each gene occurs
	map<string/*desc*/, map<string/*gene*/, int>> _geneCounts;
};
