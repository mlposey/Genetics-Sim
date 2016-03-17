#pragma once

#include <memory>
using std::shared_ptr;

#include <string>
using std::string;

class MasterGene;
class GeneticsSimDataParser;

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
	 * @return A shared_ptr to a MasterGene object if another gene was
	 *         available. If this is not the case, nullptr is returned.
	 */
	shared_ptr<MasterGene> createMasterGene();

	/**
	 * @brief Sets the file name to retrieve genetic data from
	 *
	 * This should be called immediately after first initialization.
	 * ::isInitialized() can be used to check if a parser has been set.
	 * @param filename The name of the file which contains genetic information
	 * @return returns true if the file was valid; false otherwise
	 */
	bool setDataFile(const string &filename);

	/// Returns true if the parser has been initialized with ::setDataFile
	bool isInitialized() const { return _isParserInit; }

	/// Returns true if another MasterGene can be created
	bool hasNext() const { return _genesRemaining > 0; };

private:
	MasterGeneFactory();

	// This parser retrieves information from the data file
	shared_ptr<GeneticsSimDataParser> _parser;

	// The number of genes left to read from the file
	int _genesRemaining;

	// True if the _parser object has been initialized
	bool _isParserInit;
};
