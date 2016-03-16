#include "MasterGeneFactory.h"

MasterGeneFactory* MasterGeneFactory::getInstance() {
	static MasterGeneFactory *instance = new MasterGeneFactory();
	return instance;
}

std::shared_ptr<MasterGene> MasterGeneFactory::createMasterGene() {
	return nullptr;
}

bool MasterGeneFactory::hasNext() const {
	return false;
}
