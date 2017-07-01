/*******************************************************************
*   Allele.cpp
*   CS 307 Programming Assignment 1
*   Author: Marcus Posey
*   Date Submitted: 02/23/2016
*
*   This program is entirely my own work.
*******************************************************************/
#include "Allele.h"

Allele::Allele(char symbol, const std::string& description)
	: _symbol(symbol)
	, _phenotype(description) {
}
