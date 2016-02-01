#pragma once
#include <string>

template <typename T>
struct IObserver {
	virtual ~IObserver() {}
	virtual void notify(const T &arg) = 0;
};