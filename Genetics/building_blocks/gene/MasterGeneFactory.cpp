#include "MasterGeneFactory.h"
#include "MasterGene.h"
#include "../../io/GeneticsSimDataParser.h"

MasterGeneFactory::MasterGeneFactory()
	: _parser(GeneticsSimDataParser::getInstance())
	, _isParserInit(false)
	, _genesRemaining(0)
{}

MasterGeneFactory* MasterGeneFactory::getInstance() {
	static MasterGeneFactory *instance = new MasterGeneFactory();
	return instance;
}

shared_ptr<MasterGene> MasterGeneFactory::createMasterGene() {
	if (hasNext()) {
		// Get data for the next gene from the parser and create
		// the MasterGene

		// This length matches what is defined in GeneticsSimDataParser
		const int kMaxChar = 128;

		char trait[kMaxChar],
			domDesc[kMaxChar],
			domSymbol[kMaxChar],
			recDesc[kMaxChar],
			recSymbol[kMaxChar];
		double crossoverChance;

		_parser->getGeneData(trait, domDesc, domSymbol, recDesc, recSymbol, 
			&crossoverChance);

		--_genesRemaining;

		// Under VS2012, _VARIADIC_MAX must be set in order to do this
		return std::make_shared<MasterGene>(string(trait), string(domDesc),
			string(recDesc), string(domSymbol), string(recSymbol),
			crossoverChance);
	}
	return nullptr;
}

bool MasterGeneFactory::setDataFile(const string& filename) {
	_isParserInit = _parser->initDataFile(const_cast<char*>(filename.c_str()));
	if (_isParserInit) {
		_genesRemaining = _parser->getGeneCount();
	}
	return _isParserInit;
}
