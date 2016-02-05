#pragma once

/// @brief The IObserver class is an interface for observers
template <typename T>
struct IObserver {
	virtual ~IObserver() {}
	virtual void notify(const T &arg) = 0;
};