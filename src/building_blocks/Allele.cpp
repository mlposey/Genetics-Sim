#include "Allele.h"

Allele::Allele(char symbol, const std::string& description)
	: _symbol(symbol)
	, _phenotype(description) {
}
