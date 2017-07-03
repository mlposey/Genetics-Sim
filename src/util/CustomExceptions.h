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