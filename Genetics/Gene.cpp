#include "Gene.h"
#include "Allele.h"

#include <ctime>
#include <string>
#include <sstream>

Gene::Gene(const Allele &a1, const Allele &a2) {
	_alleles.push_back(a1);
	_alleles.push_back(a2);
}

Allele Gene::getRandomAllele() const {
	srand(time(nullptr));
	return _alleles[rand() / (RAND_MAX + 1)];
}

std::string Gene::toString() const {
	std::ostringstream ss;
	ss << _alleles[0].getSymbol();
	ss << _alleles[1].getSymbol();
	return ss.str();
}
