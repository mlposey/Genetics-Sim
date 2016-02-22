/*******************************************************************
*   CustomExceptions.h
*   CS 307 Programming Assignment 1
*   Author: Marcus Posey
*   Date Submitted: 02/23/2016
*
*   This program is entirely my own work.
*******************************************************************/
#pragma once
#include <exception>

/**
 * @brief The MalformedFileException class is an exception for malformed files
 *
 * Ideally, this should be used when a file is read and determined to not contain
 * information in a manner that is deemed the standard.
 * @see std::exception
 */
class MalformedFileException : public std::exception {
public:
	MalformedFileException(const char *msg)
		: std::exception(msg)
	{}
};

/**
 * @brief The EmptyContainerException class is an exception for empty containers
 * 
 * Ideally, this should be used when one attempts to access elements in a container
 * which is either empty or not currently delivering data to outside objects.
 * @see std::exception
 */
class EmptyContainerException : public std::exception
{
public:
	EmptyContainerException(const char *msg)
		: std::exception(msg)
	{}
};
