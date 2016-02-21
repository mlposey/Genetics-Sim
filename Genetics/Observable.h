/*******************************************************************
*   Observable.h
*   CS 307 Programming Assignment 1
*   Author: Marcus Posey
*   Date Submitted: 02/23/2016
*
*   This program is entirely my own work.
*******************************************************************/
#pragma once
#include <vector>
#include <algorithm>

#include "IObserver.h"

// TODO: This description isn't quite accurate

/**
 * @brief The Observable class is an interface for observable objects
 * @see IObserver
 */
template <typename T>
class Observable {
public:
	virtual ~Observable(){}

	/// Adds an IObserver to the list of observers
	void addObserver(IObserver<T> &o);

	/// Removes an IObserver from the list of observers
	void removeObserver(const IObserver<T> &o);

	/**
	 * Invokes IObserver::notify on all stored IObserver objects
	 * @param arg a message to send to all observing objects
	 */
	void notifyAll(const T &arg);

	/**
	 * @brief Searches the stored IObservers for 'o'
	 * @param The IObserver object to search for
	 * @return True if the Observable contains 'o'
	 */
	bool contains(const IObserver<T> &o) const;

	/// @return The number of Observers watching the object
	int getObserverCount() const { return _observers.size(); }

protected:
	std::vector<IObserver<T>*> _observers;
};

template <typename T>
void Observable<T>::addObserver(IObserver<T> &o) {
	_observers.push_back(&o);
}

template <typename T>
void Observable<T>::removeObserver(const IObserver<T> &o) {
	_observers.erase(std::remove(_observers.begin(), _observers.end(), &o), _observers.end());
}

template <typename T>
void Observable<T>::notifyAll(const T &arg) {
	for (IObserver<T> *o : _observers) {
		o->notify(arg);
	}
}

template <typename T>
bool Observable<T>::contains(const IObserver<T> &o) const {
	return std::find(begin(_observers), end(_observers), &o) != end(_observers);
}
