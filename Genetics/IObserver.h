#pragma once
#include <string>

struct IObserver {
	virtual ~IObserver() {}
	virtual void notify(const std::string &arg) = 0;
};