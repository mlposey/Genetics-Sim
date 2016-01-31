#include "Gene.h"
#include "Allele.h"

#include <string>
#include <sstream>

Gene::Gene(const Allele &a1, const Allele &a2, const std::string &desc)
	: _description(desc) {
	_alleles.push_back(a1);
	_alleles.push_back(a2);
}

Allele Gene::getRandomAllele() const {
	return _alleles[rand() % 2];
}

std::string Gene::toString() const {
	std::ostringstream ss;
	ss << _alleles[0].getSymbol();
	ss << _alleles[1].getSymbol();
	return ss.str();
}
