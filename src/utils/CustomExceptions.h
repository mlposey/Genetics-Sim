/*******************************************************************
*   CustomExceptions.h
*   CS 307 Programming Assignment 1
*   Author: Marcus Posey
*   Date Submitted: 02/23/2016
*
*   This program is entirely my own work.
*******************************************************************/
#pragma once
#include <stdexcept>
#include "macros.h"

/**
 * @brief The InvalidSymbolException class is an exception for invalid allele symbols
 *
 * This is usually thrown when requesting a MasterGene from MasterGeneIndex
 * that does not exist.
 */
MAKE_EXCEPTION(InvalidSymbolException)

/**
 * @brief The EmptyContainerException class is an exception for empty containers
 *
 * Ideally, this should be used when one attempts to access elements in a container
 * which is either empty or not currently delivering data to outside objects.
 * @see std::exception
 */
MAKE_EXCEPTION(EmptyContainerException)