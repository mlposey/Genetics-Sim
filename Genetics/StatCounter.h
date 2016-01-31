#pragma once
#include <unordered_map>
#include <string>

using std::string;

#include "IObserver.h"

class StatCounter : public IObserver
{
public:
	void notify(const string &arg) override;

	int size() const { return _genotypeCounts.size(); }

	int count(const string &genotype);

private:
	std::unordered_map<string, int> _genotypeCounts;
};
