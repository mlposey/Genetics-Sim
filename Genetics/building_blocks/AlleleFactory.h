#pragma once

#include <mutex>
#include <unordered_map>
#include <memory>
#include <string>

#include "Allele.h"

class AlleleFactory {
public:
	/// Returns a shared instance of the AlleleFactory
	static AlleleFactory *getInstance();

	/**
	 * @brief Retrieves a shared_ptr to an Allele with the supplied specs
	 *
	 * getAllele takes the supplied specs and either creates an Allele
	 * to return a pointer to or returns a pointer to an already
	 * stored Allele
	 * @param symbol The symbol of the Allele
	 * @param phentoype What physical trait the Allele encodes for
	 * @return A shared_ptr to the specified Allele
	 */
	std::shared_ptr<Allele> getAllele(char symbol, std::string phenotype);

private:
	// This class is a singleton, so this won't be used
	AlleleFactory(){}

	/*
	  This is the index of all Alleles in the program.
	  All Allele objects within the program should reference this index
	*/
	std::unordered_map<char, std::shared_ptr<Allele>> _index;

	// Used to lock _index
	std::mutex _indexMutex;
};
