#pragma once
#include <unordered_map>
#include <string>
using std::string;

#include <mutex>
#include <memory>
using std::shared_ptr;

#include "Gene.h"

/**
 * @brief The GeneFactory class manages creation of Gene objects
 *
 * GeneFactory maintains an index of all possible Genes and
 * should be used whenever a Gene is to be created.
 * It is thread safe.
 * @see Gene
 */
class GeneFactory {
public:
	/// Returns a shared instance of the GeneFactory
	static GeneFactory *getInstance();

	/**
	 * @brief Retrieves a pointer to a Gene with the given specs
	 *
	 * getGene takes the supplied specs and either creates a Gene
	 * to return a pointer to or returns a pointer to an already
	 * stored Gene
	 *
	 * @param trait The trait of the Gene
	 * @param chance The change that the Gene will cross over
	 * @param a1 The character for the first Allele
	 * @param a2 The character for the second Allele
	 * @return A shared_ptr to the specified Gene
	 * @see Allele, Gene
	 */
	shared_ptr<Gene> getGene(string trait, double chance,
							 shared_ptr<Allele> a1,
							 shared_ptr<Allele> a2);

private:
	// The class is a singleton, so this won't be used.
	GeneFactory(){}

	/*
	  The index of all requested Gene objects
	  Every usage of a Gene within the program should
	  be referring to objects that are stored in here.
	*/
	std::unordered_map<string, shared_ptr<Gene>> _index;

	// Used to lock _index
	std::mutex _indexMutex;
};
