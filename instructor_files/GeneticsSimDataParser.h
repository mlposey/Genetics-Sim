//====================================================================
// GeneticsSimDataParser.h
// Interface file for the data parser.
// Author: Dr. Rick Coleman
// Date: December 2009
//====================================================================
#ifndef GENETICSSIMDATAPARSER_H
#define GENETICSSIMDATAPARSER_H

#include <fstream>
#include <iostream>

using namespace std;

class GeneticsSimDataParser
{
	private:
		ifstream	*inFile;				// Genetics sim data definition file
		int			m_iNumGenes;			// Number of genes in the data file
		int			m_iNextGeneNumber;		// Counter to next gene to read
		int			m_iNextParentNumber;	// Counter to next parent genotype to read
		char        m_sFileName[64];		// Data file name
		char		m_sGenus[32];			// Genus name of this test organism
		char		m_sSpecies[32];			// Species name of this test organism
		char		m_sSciName[64];			// Full scientific name of the test organism
		char		m_sCommonName[32];		// Common use name of the test organism

	public:
		GeneticsSimDataParser(char *fileName);	// Constructor
		~GeneticsSimDataParser();				// Destructor
		int getGeneCount();
		char *getGenus();
		char *getSpecies();
		char *getScientificName();				// Get genus and species in one string
		char *getCommonName();
		bool getParentGenotype(char *genotype);		
		bool getGeneData(char *trait, char *domDesc, char *domSymbol, char *recDesc, char *recSymbol);
	private:
		bool getNextLine(char *buffer, int n);

};
#endif