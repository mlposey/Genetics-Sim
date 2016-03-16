#pragma once

#include <memory>
#include "MasterGene.h"

/**
 * @brief The MasterGeneFactory class creates MasterGene objects from the data file
 *
 * MasterGeneFactory implements the singleton pattern and should be used to
 * create instances of MasterGene objects that mimic the information found within
 * the supplied data file.
 * @see MasterGene
 */
class MasterGeneFactory
{
public:
	/// Returns a static instance of MasterGeneFactory
	static MasterGeneFactory *getInstance();

	/**
	 * @brief creates a MasterGene using data in the data file
	 *
	 * Before calling this function, one should check the result of
	 * ::hasNext to ensure that another MasterGene exists within the
	 * data file.
	 * @return A shared_ptr to a MasterGene object
	 */
	std::shared_ptr<MasterGene> createMasterGene();

	/// Returns true if another MasterGene can be created
	bool hasNext() const;

private:
	MasterGeneFactory() {}
};
