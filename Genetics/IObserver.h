#pragma once

struct IObserver {
	virtual ~IObserver() {}
	virtual void notify(void *arg) = 0;
};