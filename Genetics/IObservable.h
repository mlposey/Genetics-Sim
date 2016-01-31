#pragma once
#include <vector>
#include <algorithm>
#include <string>

#include "IObserver.h"

class IObservable {
public:
	virtual ~IObservable(){}

	void addObserver(IObserver &o);
	void removeObserver(const IObserver &o);

	void notifyAll(const std::string &arg);

protected:
	std::vector<IObserver*> _observers;
};

inline void IObservable::addObserver(IObserver& o) {
	_observers.push_back(&o);
}

inline void IObservable::removeObserver(const IObserver& o) {
	_observers.erase(std::remove(_observers.begin(), _observers.end(), &o), _observers.end());
}

inline void IObservable::notifyAll(const std::string& arg) {
	for (IObserver *o : _observers) {
		o->notify(arg);
	}
}


