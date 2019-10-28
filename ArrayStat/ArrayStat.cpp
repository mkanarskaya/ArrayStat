#include "ArrayStat.h"

#include <fstream>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cmath>

using namespace std;

ArrayStat::ArrayStat(const string& fname) {
	ifstream file(fname, ifstream::in);
	if (!file.good()) {
		cout << "Cannot open file " << endl;
		exit(1);
	}
	while (!file.eof()) {
		int n;
		file >> n;
		data.push_back(n);
	}
	sort(begin(data), end(data));
	m_mean = accumulate(begin(data), end(data), 0.) / data.size();


	vector<int> squares(data.size());
	transform(begin(data), end(data), begin(squares), [](int val) {return val * val; });

	double mean_sq = accumulate(begin(squares), end(squares), 0.) / squares.size();
	m_rms = sqrt(mean_sq - m_mean * m_mean);
}

double ArrayStat::get_mean() const {
	return m_mean;
};

double ArrayStat::get_rms() const {
	return m_rms;
};

int ArrayStat::get_max() const {
	return data[data.size() - 1];
};

int ArrayStat::get_min() const {
	return data[0];
};

size_t ArrayStat::countLarger(int a) const {
	size_t count;
	auto number = upper_bound(begin(data), end(data), a);
    count = distance(number, end(data));
	return count;
}



void ArrayStat::print() const {
	std::cout << "Input const a ";
	double a;
	std::cin >> a;
	std::cout << "max =" << get_max() << "; min = " << get_min() << "; average value = " << get_mean() << "; rms = "
		<< get_rms() << "; count value which is more a = " << countLarger(a) << ";\n";
	for (int i = 0; i < data.size(); i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

