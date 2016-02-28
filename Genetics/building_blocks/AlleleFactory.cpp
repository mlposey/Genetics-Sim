#include "AlleleFactory.h"

AlleleFactory* AlleleFactory::getInstance() {
	static AlleleFactory *instance = new AlleleFactory();
	return instance;
}

std::shared_ptr<Allele> AlleleFactory::getAllele(char symbol, std::string phenotype) {
	// We want to avoid race conditions
	std::lock_guard<std::mutex> lock(_indexMutex);

	if (_index.find(symbol) == end(_index)) {
		// The key does not exist. Add it
		_index[symbol] = std::make_shared<Allele>(symbol, phenotype);
	}
	return _index[symbol];
}

