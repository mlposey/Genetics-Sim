/*******************************************************************
*   Gene.cpp
*   CS 307 Programming Assignment 1
*   Author: Marcus Posey
*   Date Submitted: 02/23/2016
*
*   This program is entirely my own work.
*******************************************************************/
#include "Gene.h"

#include <algorithm>

Gene::Gene(shared_ptr<Allele> a1, shared_ptr<Allele> a2, const std::string &desc)
	: _description(desc) {
	_alleles.push_back(a1);
	_alleles.push_back(a2);

	// We want capital symbols to appear before lowercase
	std::sort(begin(_alleles), end(_alleles), [&](shared_ptr<Allele> a,
		                                          shared_ptr<Allele> b)
	{
		return a->getSymbol() < b->getSymbol();
	});

	// Store the sorted allele pair as a string
	_allelesString += first()->getSymbol();
	_allelesString += second()->getSymbol();
}

shared_ptr<Allele> Gene::getRandomAllele() const {
	return _alleles[rand() % 2];
}

std::string Gene::getPhenotype() const {
	if (first()->isDominant() == second()->isDominant()) {
		// They are either both recessive or both dominant
		return first()->getDescription();
	}
	else if (first()->isDominant()) {
		return first()->getDescription();
	}
	else {
		return second()->getDescription();
	}
}

std::string Gene::getZygosity() const {
	if (first()->isDominant() == second()->isDominant()) {
		if (!first()->isDominant()) {
			return "homozygous recessive";
		}
		else {
			return "homozygous dominant";
		}
	}
	else {
		return "heterozygous dominant";
	}
}

std::string Gene::toString() const {
	return getZygosity() + " (" + getPhenotype() + " " + getAllelesString() + ")";
}
