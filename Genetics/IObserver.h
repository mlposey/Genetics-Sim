/*******************************************************************
*   IObserver.h
*   CS 307 Programming Assignment 1
*   Author: Marcus Posey
*   Date Submitted: 02/23/2016
*
*   This program is entirely my own work.
*******************************************************************/
#pragma once

/// @brief The IObserver class is an interface for observers
template <typename T>
struct IObserver {
	virtual ~IObserver() {}
	virtual void notify(const T &arg) = 0;
};
