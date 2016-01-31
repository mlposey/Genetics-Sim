#pragma once
#include "IObserver.h"

struct IObservable {
	virtual ~IObservable(){}
	virtual void addObserver(const IObserver &o) = 0;
	virtual void removeObserver(const IObserver &o) = 0;
	virtual void notifyAll();
};