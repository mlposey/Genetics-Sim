/*******************************************************************
*   Gene.cpp
*   CS 307 Programming Assignment 1
*   Author: Marcus Posey
*   Date Submitted: 02/23/2016
*
*   This program is entirely my own work.
*******************************************************************/
#include "Gene.h"

#include <iostream>
using std::cout;

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

void Gene::printDescription() const {
	cout << "\t\t\tGene Type: " << _master->getTrait() << '\n';

	string pair = getAllelesString();
	for (int j = 0; j < pair.size(); ++j) {
		cout << "\t\t\t\tAllele " << j + 1 << ": ";
		if (isupper(pair[j])) {
			cout << _master->getDominantAllele();
		}
		else {
			cout << _master->getRecessiveAllele();
		}
		cout << "(" << pair[j] << ")\n";
	}
}

/*
This will be needed by the stat printer but is small enough in
scope that the logic should just be put in that function
string Gene::toString() const {
	return getZygosity() + " (" + getPhenotype() + " " + getAllelesString() + ")";
}*/