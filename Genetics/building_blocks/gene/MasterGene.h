#pragma once

#include <string>
using std::string;

class MasterGene
{
public:
	MasterGene(const string &trait, const string &dominantAllele,
		       const string &recessiveAllele, const string &dominantSymbol,
			   const string &recessiveSymbol, double crossoverChance)
		: _trait(trait)
		, _dominantAllele(dominantAllele)
		, _recessiveAllele(recessiveAllele)
		, _dominantSymbol(dominantSymbol)
		, _recessiveSymbol(recessiveSymbol)
		, _crossoverChance(crossoverChance) {
		// We set negative crossover chances to 0 since the concept
		// of a negative chance does not make sense.
		_crossoverChance = _crossoverChance < 0 ? 0 : _crossoverChance;
	}

	string getTrait() const {
		return _trait;
	}

	string getDominantAllele() const {
		return _dominantAllele;
	}

	string getRecessiveAllele() const {
		return _recessiveAllele;
	}

	string getDominantSymbol() const {
		return _dominantSymbol;
	}

	string getRecessiveSymbol() const {
		return _recessiveSymbol;
	}

	double getCrossoverChance() const {
		return _crossoverChance;
	}

private:
	string _trait,
		   _dominantAllele,
		   _recessiveAllele;
	
	// Symbols representing the dominant and recessive genes
	// Note: A "symbol" could be multicharacter (e.g. "A1")
	string _dominantSymbol,
		   _recessiveSymbol;

	double _crossoverChance;
};

