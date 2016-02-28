#include "GeneFactory.h"
#include "AlleleFactory.h"

GeneFactory* GeneFactory::getInstance() {
	static GeneFactory *instance = new GeneFactory();
	return instance;
}

shared_ptr<Gene> GeneFactory::getGene(string trait, double chance,
									  shared_ptr<Allele> a1,
									  shared_ptr<Allele> a2) {
	// We want to avoid race conditions on our index
	std::lock_guard<std::mutex> lock(_indexMutex);

	string key = trait + std::to_string(chance) + a1 + a2;
	if (_index.find(key) == end(_index)) {
		// Create the Gene if it didn't already exist
		// TODO: Gene should take chance in its constructor
		_index[key] = std::make_shared<Gene>(a1, a2, trait);
	}
	return _index[key];
}
