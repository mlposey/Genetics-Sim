#include "Gene.h"

#include <algorithm>

Gene::Gene(const Allele &a1, const Allele &a2, const std::string &desc)
	: _description(desc) {
	_alleles.push_back(a1);
	_alleles.push_back(a2);

	// We want capital symbols to appear before lowercase
	std::sort(begin(_alleles), end(_alleles), [&](Allele &a, Allele &b)
	{
		return a.getSymbol() < b.getSymbol();
	});

	// Store the sorted allele pair as a string
	_allelesString += _alleles[0].getSymbol();
	_allelesString += _alleles[1].getSymbol();
}

Allele Gene::getRandomAllele() const {
	return _alleles[rand() % 2];
}

std::string Gene::getPhenotype() const {
	const Allele &a1 = _alleles[0], &a2 = _alleles[1];

	if (a1.isDominant() == a2.isDominant()) {
		// They are either both recessive or both dominant
		return a1.getDescription();
	}
	else if (a1.isDominant()) {
		return a1.getDescription();
	}
	else {
		return a2.getDescription();
	}
}

std::string Gene::getZygosity() const {
	if (_alleles[0].isDominant() == _alleles[1].isDominant()) {
		if (!_alleles[0].isDominant()) {
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
