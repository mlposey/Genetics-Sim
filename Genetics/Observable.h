#pragma once
#include <vector>
#include <algorithm>
#include <string>

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

protected:
	std::vector<IObserver<T>*> _observers;
};

template <typename T>
void Observable<T>::addObserver(IObserver<T>& o) {
	_observers.push_back(&o);
}

template <typename T>
void Observable<T>::removeObserver(const IObserver<T>& o) {
	_observers.erase(std::remove(_observers.begin(), _observers.end(), &o), _observers.end());
}

template <typename T>
void Observable<T>::notifyAll(const T &arg) {
	for (IObserver<T> *o : _observers) {
		o->notify(arg);
	}
}


