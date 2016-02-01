#include "Gene.h"
#include "Allele.h"

#include <string>
#include <sstream>
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
}

Allele Gene::getRandomAllele() const {
	return _alleles[rand() % 2];
}

std::string Gene::getPhenotype() const {
	char s1 = _alleles[0].getSymbol(), s2 = _alleles[1].getSymbol();
	if (s1 == s2) {
		return _alleles[0].getDescription();
	}
	else if (s1 > s2) {
		return _alleles[1].getDescription();
	}
	else {
		return _alleles[0].getDescription();
	}
}

std::string Gene::getZygosity() const {
	char s1 = _alleles[0].getSymbol(), s2 = _alleles[1].getSymbol();

	if (s1 == s2) {
		if (islower(s1)) {
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

std::string Gene::getAllelesString() const {
	std::ostringstream ss;
	ss << _alleles[0].getSymbol();
	ss << _alleles[1].getSymbol();
	return ss.str();
}

std::string Gene::toString() const {
	return getZygosity() + " (" + getPhenotype() + " " + getAllelesString() + ")";
}
