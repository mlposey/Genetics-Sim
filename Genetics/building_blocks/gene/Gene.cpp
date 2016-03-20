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
#include "MasterGeneIndex.h"

Gene::Gene(std::shared_ptr<MasterGene> master, char a1, char a2)
	: _master(master)
	, _allele1(a1)
	, _allele2(a2)
{}

char Gene::getRandomAllele() const {
	return rand() % 2 == 0 ? _allele1 : _allele2;
}

// TODO: Test this method
string Gene::getPhenotype() const {
	MasterGeneIndex *index = MasterGeneIndex::getInstance();
	return (_allele1 == _allele2 || isupper(_allele1)) ?
		index->get(_allele1)->getDominantAllele()
		:
		index->get(_allele2)->getRecessiveAllele();
}

// TODO: Test this method
string Gene::getZygosity() const {
	if (_allele1 == _allele2) {
		if (isupper(_allele1)) {
			return "homozygous dominant";
		}
		else {
			return "homozygous recessive";
		}
	}
	return "heterozygous dominant";
}

string Gene::toString() const {
	return getZygosity() + " (" + getPhenotype() + " " + getAllelesString() + ")";
}
