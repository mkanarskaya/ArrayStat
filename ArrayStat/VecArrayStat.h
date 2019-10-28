#pragma once
#include <vector>
#include <array>
#include <string>

class VecArrayStat
{
private:
	std::vector< std::array<int, 3> > data;
	double m_mean;
	double m_rms;
public:
	VecArrayStat(const std::string& fname);
	double get_mean() const;
	double get_rms() const;
	std::array <int, 3> get_max() const;
	std::array <int, 3>  get_min() const;
	void print() const;
	size_t countLarger(int) const;
};

