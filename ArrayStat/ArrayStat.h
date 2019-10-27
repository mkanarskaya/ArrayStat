#pragma once
#include <vector>
#include <string>

class ArrayStat
{
private:
	std::vector<int> data;
	double m_mean;
	double m_rms;
public:
	ArrayStat(const std::string& fname);
	int get_max() const;
	int get_min() const;
	void print() const;
	size_t countLarger(int) const;
};


