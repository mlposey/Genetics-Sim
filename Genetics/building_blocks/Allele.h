/*******************************************************************
*   Allele.h
*   CS 307 Programming Assignment 1
*   Author: Marcus Posey
*   Date Submitted: 02/23/2016
*
*   This program is entirely my own work.
*******************************************************************/
#pragma once
#include <string>

/**
 * @brief The Allele class models the alleles of a Gene
 *
 * This immutable representation of an allele holds information
 * regarding symbols (e.g. T or t), description of the allele
 * (e.g. tall), and whether the allele is dominant or not. It is
 * an essential part of the Gene class.
 * @see Gene
 */
class Allele
{
public:
	/**
	 * @brief Constructs an Allele object
	 * @param symbol The symbol for the allele
	 * @param description What the allele represents
	 */
	Allele(char symbol, const std::string &description);

	/// @return True if the allele is dominant or false if it is recessive
	bool isDominant() const { return isupper(_symbol) != 0; }

	/// @return The symbol of the allele (e.g. 'T' or 't')
	char getSymbol() const { return _symbol; }

	/// @return The description of the allele (e.g. "tall" or "short")
	std::string getDescription() const { return _phenotype; }

private:
	/*
	  The symbol of the Allele. Capital letters represent a dominant Allele
	  while lower case letters represent a recessive one.
	*/
	char _symbol;

	// The physical trait the Alelle represents
	std::string _phenotype;
};
