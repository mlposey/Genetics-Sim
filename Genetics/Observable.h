#pragma once
#include <vector>
#include <algorithm>
#include <string>

#include "IObserver.h"

template <typename T>
class Observable {
public:
	virtual ~Observable(){}

	void addObserver(IObserver<T> &o);
	void removeObserver(const IObserver<T> &o);

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


