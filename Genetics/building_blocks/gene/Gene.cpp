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

Gene::Gene(std::shared_ptr<MasterGene> master, char a1, char a2)
	: _master(master)
	, _allele1(a1)
	, _allele2(a2)
{}

char Gene::getRandomAllele() const {
	return rand() % 2 == 0 ? _allele1 : _allele2;
}

string Gene::getPhenotype() const {
	// TODO: getPhenotype
	return "";
}

string Gene::getZygosity() const {
	// TODO: getZygosity
	return "";
}

string Gene::toString() const {
	return getZygosity() + " (" + getPhenotype() + " " + getAllelesString() + ")";
}
