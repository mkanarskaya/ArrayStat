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
	double get_mean() const;
	double get_rms() const;
	int get_max() const;
	int get_min() const;
	void print() const;
	size_t countLarger(int) const;
};


