#pragma once
#include <memory>
using std::shared_ptr;

#include "MasterGene.h"
#include <vector>

/**
 * @brief The MasterGeneIndex class stores a collection of all MasterGene objects
 * @see MasterGene
 */
class MasterGeneIndex
{
public:
	static MasterGeneIndex *getInstance();

	/// Adds a MasterGene to the index
	void add(shared_ptr<MasterGene> master);

	/// Retrieves a MasterGene from the index
	shared_ptr<MasterGene> get(char symbol);

private:
	MasterGeneIndex() {}

	// The program-wide collection of master genes
	std::vector<shared_ptr<MasterGene>> _masterGenes;
};
